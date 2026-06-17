# Chess Movement

Inheritance, Interface, Polymorphism, & 4-Sekawan.
Anda bertugas untuk mengimplementasikan pergerakan beberapa bidak catur (Bishop, Knight, Rook).

Implementasi diharapkan memanfaatkan konsep OOP berupa Inheritance, Interface, Polymorphism, & 4-Sekawan.

Task:
No Task Desc
1
Membuat Interface Aksi yang berisi 8 method ("atas", "atasKanan", "atasKiri", "kanan", "kiri", "bawahKanan", "bawahKiri", "bawah").

Semua method ini memiliki default behaviour sprint "[X] Gerakan tidak valid untuk bidak ini!\n" dan berparameter "Optional<Integer> steps". Ini merupakan tindakan preventif jika kelas yang megimplements interface ini tidak memiliki aksi valid untuk method terpilih.

2 Lengkapi implementasi kelas Bidak, Bishop, Knight, Rook agar program berjalan sesuai expected behaviour.

Simbol Bishop = 'B', Knight = 'K', Rook = 'R'
Expected Alur program
Program akan inisiasi 3 bidak (Bishop, Knight, Rook) di posisi tertentu
Program akan menampilkan posisi setiap bidak dengan melakukan print bidak (cetakPapan)
User diminta untuk memilih id bidak yang ingin dimainkan, jika 0 program akan berhenti
User diminta untuk memilih arah pergerakan
Jika bidak yang dipilih (Bishop/Rook), user akan diminta jumlah langkah dari arah pergerakan
Program akan mengeksekusi fungsi terkait sehingga posisi berubah. Jika terjadi kondisi tidak valid (cetak error, aksi dibatalkan, posisi di-rollback).
Program akan looping mulai dari langkah ke-2, hingga input user [0]
Additional Notes
ChessMovement.zip
Driver.java
Petak.java
Kumpulkan Aksi.java, Bidak.java, Bishop.java, Knight.java, Rook.java ke dalam ChessMovement.zip
Anda mungkin akan membutuhkan Java.Util.Optional, silakan buka dokumentasi penggunaannya di sini
