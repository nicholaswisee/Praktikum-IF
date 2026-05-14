Nama File: BankSystem.zip

Kamu diminta membangun sistem manajemen rekening bank sederhana menggunakan Java. Sistem ini harus menangani berbagai kondisi error dengan custom exceptions, baik checked exception (turunan Exception) maupun unchecked exception (turunan RuntimeException).

File Main.java (driver) dan AccountNotFoundException.java sudah disediakan dan tidak boleh diubah. Tugas kamu adalah mengimplementasikan file-file berikut:

InsufficientFundsException.java
InvalidAmountException.java
AccountFrozenException.java
BankAccount.java
Bank.java
Kumpulkan BankSystem.zip yang berisi semua file .java yang kamu buat, termasuk Main.java dan AccountNotFoundException.java.

Spesifikasi

1. AccountNotFoundException (sudah disediakan sebagai referensi)

Checked exception yang dilempar ketika akun dengan ID tertentu tidak ditemukan.
Pesan: "Akun tidak ditemukan: <accountId>"

2. InsufficientFundsException (checked exception)

Extends Exception. Dilempar ketika saldo rekening tidak mencukupi untuk penarikan.

Constructor Pesan Exception
InsufficientFundsException(String accountId, long balance, long amount) "Saldo tidak cukup di akun <accountId> (saldo: <balance>, diperlukan: <amount>)" 3. InvalidAmountException (unchecked exception)

Extends RuntimeException. Dilempar ketika jumlah yang diberikan tidak valid (≤ 0 untuk deposit/withdraw, < 0 untuk saldo awal).

Constructor Pesan Exception
InvalidAmountException(long amount) "Jumlah tidak valid: <amount>" 4. AccountFrozenException (checked exception)

Extends Exception. Dilempar ketika operasi dilakukan pada akun yang sedang dibekukan.

Constructor Pesan Exception
AccountFrozenException(String accountId) "Akun dibekukan: <accountId>" 5. Kelas BankAccount

Merepresentasikan sebuah rekening bank milik seorang nasabah.

Method / Constructor Keterangan
BankAccount(String id, long initialBalance) Membuat rekening baru. Lempar InvalidAmountException jika initialBalance < 0.
String getId() Mengembalikan ID rekening.
long getBalance() Mengembalikan saldo rekening saat ini.
boolean isFrozen() Mengembalikan true jika rekening sedang dibekukan.
void deposit(long amount) Menambah saldo sebesar amount.
Urutan pengecekan: amount ≤ 0 → InvalidAmountException; rekening beku → AccountFrozenException.
void withdraw(long amount) Mengurangi saldo sebesar amount.
Urutan pengecekan: amount ≤ 0 → InvalidAmountException; rekening beku → AccountFrozenException; saldo kurang → InsufficientFundsException.
void freeze() Membekukan rekening.
void unfreeze() Mengaktifkan kembali rekening yang dibekukan. 6. Kelas Bank

Mengelola kumpulan rekening menggunakan LinkedHashMap<String, BankAccount>.

Method Keterangan
void addAccount(String id, long initialBalance) Membuat dan menyimpan rekening baru. InvalidAmountException dari konstruktor BankAccount ter-propagate otomatis.
BankAccount getAccount(String id) Mengembalikan rekening dengan ID yang diberikan. Lempar AccountNotFoundException jika tidak ditemukan.
void deposit(String id, long amount) Memanggil deposit() pada rekening yang sesuai. Propagate semua exception.
void withdraw(String id, long amount) Memanggil withdraw() pada rekening yang sesuai. Propagate semua exception.
void freeze(String id) Membekukan rekening. Lempar AccountNotFoundException jika tidak ditemukan.
void unfreeze(String id) Mengaktifkan rekening. Lempar AccountNotFoundException jika tidak ditemukan.
void transfer(String fromId, String toId, long amount) Mentransfer amount dari rekening fromId ke toId. Panggil withdraw() pada rekening asal lalu deposit() pada rekening tujuan. Propagate semua exception.
Format Masukan

Input terdiri atas sejumlah baris, masing-masing berisi satu perintah:

ADD <id> <saldo_awal>: membuat rekening baru
DEPOSIT <id> <jumlah>: setor uang ke rekening
WITHDRAW <id> <jumlah>: tarik uang dari rekening
FREEZE <id>: bekukan rekening
UNFREEZE <id>: aktifkan rekening
TRANSFER <id_asal> <id_tujuan> <jumlah>: transfer antar rekening
STATUS <id>: tampilkan info rekening
Format Keluaran

Perintah Kondisi Keluaran
ADD berhasil Akun <id> dibuat dengan saldo <saldo>.
DEPOSIT berhasil Deposit <jumlah> ke akun <id> berhasil.
WITHDRAW berhasil Tarik <jumlah> dari akun <id> berhasil.
FREEZE berhasil Akun <id> dibekukan.
UNFREEZE berhasil Akun <id> diaktifkan.
TRANSFER berhasil Transfer <jumlah> dari <id_asal> ke <id_tujuan> berhasil.
STATUS - Akun <id>: Saldo=<saldo>, Status=<Aktif/Beku>.
Semua perintah terjadi exception Error: <pesan exception>
Contoh Masukan dan Keluaran

Masukan 1:

ADD A001 1000000
ADD A002 500000
ADD A003 0
DEPOSIT A001 200000
DEPOSIT A002 100000
STATUS A001
STATUS A002
STATUS A003
Keluaran 1:

Akun A001 dibuat dengan saldo 1000000.
Akun A002 dibuat dengan saldo 500000.
Akun A003 dibuat dengan saldo 0.
Deposit 200000 ke akun A001 berhasil.
Deposit 100000 ke akun A002 berhasil.
Akun A001: Saldo=1200000, Status=Aktif.
Akun A002: Saldo=600000, Status=Aktif.
Akun A003: Saldo=0, Status=Aktif.
Masukan 2:

ADD D001 800000
ADD D002 200000
FREEZE D001
DEPOSIT D001 100000
WITHDRAW D001 50000
TRANSFER D001 D002 100000
STATUS D001
UNFREEZE D001
DEPOSIT D001 100000
STATUS D001
Keluaran 2:

Akun D001 dibuat dengan saldo 800000.
Akun D002 dibuat dengan saldo 200000.
Akun D001 dibekukan.
Error: Akun dibekukan: D001
Error: Akun dibekukan: D001
Error: Akun dibekukan: D001
Akun D001: Saldo=800000, Status=Beku.
Akun D001 diaktifkan.
Deposit 100000 ke akun D001 berhasil.
Akun D001: Saldo=900000, Status=Aktif.
Masukan 3:

ADD E001 500000
DEPOSIT E001 -50000
DEPOSIT E001 0
WITHDRAW E001 -10000
ADD E002 -100
STATUS E001
Keluaran 3:

Akun E001 dibuat dengan saldo 500000.
Error: Jumlah tidak valid: -50000
Error: Jumlah tidak valid: 0
Error: Jumlah tidak valid: -10000
Error: Jumlah tidak valid: -100
Akun E001: Saldo=500000, Status=Aktif.
