Dr. Neroifa, seorang ilmuwan bawahan Gro, menciptakan sebuah alat bernama Mesin Hitung Neroifa. Berbeda dengan kalkulator biasa, mesin ini bekerja menggunakan notasi postfix, di mana setiap operasi dilakukan berdasarkan prinsip LIFO (Last In First Out). Sebagai programmer kepercayaan Dr. Neroifa, tugas kalian adalah memastikan mesin ini bekerja dengan benar dan menangani setiap kesalahan menggunakan exception yang tepat.

File main.cpp, MesinHitungException.hpp, MesinHitungException.cpp, dan MesinHitungNeroifa.hpp sudah disediakan dan tidak boleh diubah.

File yang Disediakan (tidak boleh diubah):

main.cpp — Program utama (driver)
MesinHitungException.hpp — Header exception
MesinHitungException.cpp — Implementasi exception
MesinHitungNeroifa.hpp — Header file utama
File yang Harus Dimodifikasi:

MesinHitungNeroifa.cpp — Implementasi mesin hitung berbasis stack
Pengumpulan:

MesinHitungNeroifa.cpp
Spesifikasi Kelas

1. MesinHitungException
   Gunakan exception yang telah disediakan untuk menangani kondisi berikut:

InsufficientOperandException — jika operasi membutuhkan operand tetapi jumlahnya tidak mencukupi
DivisionByZeroException — jika terjadi pembagian dengan nol
InvalidTokenException — jika token bukan angka yang valid maupun operator yang dikenali
InvalidExpressionException — jika ekspresi tidak menghasilkan tepat satu nilai akhir 2. Kelas MesinHitungNeroifa

Mesin hitung bekerja dengan membaca ekspresi dalam bentuk postfix, dengan aturan sebagai berikut:

Format Ekspresi
Ekspresi berupa string
Token dipisahkan oleh spasi
Token dapat berupa:
bilangan bulat (boleh negatif)
operator: +, -, \*, /
Format Input

Input berupa satu baris string ekspresi postfix.

Format Output

Jika berhasil: tampilkan hasil perhitungan
Jika terjadi kesalahan: tampilkan pesan dari exception
Contoh hasil keluaran dari main sebagai berikut: Keluaran
