Kamu diminta mendesain dan mengimplementasikan sistem todo app sederhana. Aplikasi ini mengelola daftar aktivitas yang bisa di-complete untuk mendapatkan poin. Ada dua jenis aktivitas: tugas sekali jalan dan kebiasaan harian.

File main.cpp sudah disediakan dan tidak boleh diubah. Tugasmu adalah merancang kelas-kelas yang dibutuhkan agar main.cpp dapat berjalan dengan benar.

Perhatikan bagaimana main.cpp menggunakan kelas-kelasmu — dari situ kamu bisa menyimpulkan bagaimana hubungan antar kelas harus dirancang.

Kelas yang Harus Dibuat

1. Activity
   Activity adalah representasi umum dari sebuah aktivitas. Kelas ini tidak seharusnya bisa dibuat objeknya secara langsung, karena perilaku spesifik (cara menyelesaikan aktivitas dan cara menampilkan status) bergantung pada jenis aktivitasnya.

Setiap aktivitas menyimpan nama dalam variabel name (bertipe std::string). Data ini perlu bisa diakses oleh kelas turunannya.

Activity memiliki tanggung jawab berikut:

Dibuat dengan menerima sebuah nama.
Mengembalikan namanya melalui getName().
Menyelesaikan aktivitas melalui complete(), yang mengembalikan jumlah poin (int) yang didapat. Namun, karena cara menyelesaikan tiap jenis aktivitas berbeda, Activity sendiri tidak tahu bagaimana melakukannya.
Menampilkan status melalui getStatus(), yang mengembalikan std::string. Sama seperti complete(), formatnya bergantung pada jenis aktivitas.
Dihancurkan dengan benar meskipun dihapus melalui pointer bertipe Activity*.
Pikirkan: jika main.cpp menyimpan semua aktivitas dalam array Activity* lalu memanggil delete, apa yang harus kamu pastikan agar destructor yang tepat terpanggil?

2. TodoItem
   TodoItem adalah jenis aktivitas berupa tugas yang hanya perlu diselesaikan satu kali.

TodoItem menyimpan status apakah tugas sudah dikerjakan atau belum dalam variabel isDone (bertipe bool), yang awalnya bernilai false. Data ini hanya dikelola oleh TodoItem sendiri.

Tanggung jawab TodoItem:

Dibuat dengan menerima sebuah nama.
Menyelesaikan tugas (complete()): Jika belum selesai, tandai sebagai selesai dan berikan 10 poin. Jika sudah pernah diselesaikan, berikan 0 poin.
Menampilkan status (getStatus()): Menghasilkan format [TODO] <name> - Selesai atau [TODO] <name> - Belum.
Saat dihancurkan, mencetak Menghapus TodoItem <name> diikuti newline. 3. DailyHabit
DailyHabit adalah jenis aktivitas berupa kebiasaan yang bisa dilakukan berkali-kali, dengan poin yang semakin besar seiring frekuensi pengerjaannya.

DailyHabit menyimpan jumlah kali kebiasaan ini dilakukan dalam variabel streak (bertipe int), yang awalnya 0. Data ini hanya dikelola oleh DailyHabit sendiri.

Tanggung jawab DailyHabit:

Dibuat dengan menerima sebuah nama.
Menyelesaikan kebiasaan (complete()): Tambah streak sebanyak 1, lalu berikan poin sebesar 10 × streak. (Complete pertama = 10, kedua = 20, ketiga = 30, dst.)
Menampilkan status (getStatus()): Menghasilkan format [HABIT] <name> - Streak: <streak>.
Saat dihancurkan, mencetak Menghapus DailyHabit <name> diikuti newline.
Format Input
N
TYPE_1 NAME_1
TYPE_2 NAME_2
...
TYPE_N NAME_N
M
X_1
X_2
...
X_M
N — jumlah aktivitas
TYPE — jenis aktivitas: TODO atau HABIT
NAME — nama aktivitas (satu kata, tanpa spasi)
M — jumlah aksi complete
X — indeks aktivitas yang di-complete (1-indexed)
Format Output
Untuk setiap aksi complete:

Mendapat <poin> poin dari <nama>
Di akhir program:

--- DASHBOARD AKHIR ---
<status tiap aktivitas>
Total Poin: <total>
<output destructor tiap aktivitas>
Contoh
Input
3
TODO KembalikanPetir
HABIT MeditasiOlympus
TODO BersihkanAegis
5
1
2
2
1
3
Output
Mendapat 10 poin dari KembalikanPetir
Mendapat 10 poin dari MeditasiOlympus
Mendapat 20 poin dari MeditasiOlympus
Mendapat 0 poin dari KembalikanPetir
Mendapat 10 poin dari BersihkanAegis
--- DASHBOARD AKHIR ---
[TODO] KembalikanPetir - Selesai
[HABIT] MeditasiOlympus - Streak: 2
[TODO] BersihkanAegis - Selesai
Total Poin: 50
Menghapus TodoItem KembalikanPetir
Menghapus DailyHabit MeditasiOlympus
Menghapus TodoItem BersihkanAegis
Penjelasan
KembalikanPetir (TODO) di-complete → belum selesai, dapat 10 poin
MeditasiOlympus (HABIT) complete pertama → streak = 1, dapat 10 poin
MeditasiOlympus (HABIT) complete kedua → streak = 2, dapat 20 poin
KembalikanPetir (TODO) dicoba lagi → sudah selesai, dapat 0 poin
BersihkanAegis (TODO) di-complete → belum selesai, dapat 10 poin
Total: 10 + 10 + 20 + 0 + 10 = 50

File yang Disediakan
main.cpp — JANGAN DIUBAH (untuk testing).
Activity.hpp (Perlu dilengkapi)
TodoItem.hpp (Perlu dilengkapi)
DailyHabit.hpp (Perlu dilengkapi)
File yang Harus Dikumpulkan
Activity.hpp
TodoItem.hpp & TodoItem.cpp
DailyHabit.hpp & DailyHabit.cpp
