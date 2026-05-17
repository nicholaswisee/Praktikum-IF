Bayangkan kalian sedang membangun aplikasi yang perlu menyimpan data ke database. Tanpa bantuan apapun, kalian harus menulis SQL secara manual untuk setiap tabel buat INSERT, buat DELETE, buat SELECT, dan seterusnya.

Solusi dari masalah ini adalah ORM (Object-Relational Mapper) . ORM adalah sebuah lapisan yang "menerjemahkan" objek ke operasi database secara otomatis. Kamu cukup mendefinisikan kelas seperti biasa, dan ORM yang akan menghasilkan SQL-nya.

Bagaimana ORM tahu nama tabelnya apa? Kolom mana yang jadi primary key? Jawabannya adalah Annotation . Pengguna cukup "mendekorasi" kelas dan field-nya dengan annotation khusus.

ORM akan membaca dekorasi-dekorasi itu secara runtime menggunakan Reflection, kemampuan Java untuk menginspeksi dan memanipulasi kelas, field, dan method sebuah objek pada saat program berjalan, tanpa perlu mengetahui struktur kelas tersebut saat kompilasi.

Buatalah sebuah mini ORM yang menggunakan Java Reflection untuk membaca annotation dan menjalankan lifecycle hooks secara otomatis.

File-file berikut sudah tersedia dan tidak boleh diubah.

TableName.java — annotation yang diletakkan di atas deklarasi kelas. Menyimpan satu atribut: nama tabel (String value).
ColumnName.java — annotation yang diletakkan di atas deklarasi field. Menyimpan dua atribut: nama kolom (String value) dan apakah kolom ini adalah primary key (boolean primaryKey, default false).
Hook.java — annotation yang diletakkan di atas deklarasi method. Menentukan kapan method tersebut dipanggil, melalui atribut bertipe enum Hook.When yang punya tiga nilai: PRE_INSERT, POST_LOAD, dan PRE_DELETE.
Mahasiswa.java — contoh kelas model. Punya tiga field beranotasi @ColumnName dan satu field biasa tanpa anotasi (catatan). Juga punya tiga lifecycle hook methods (POST_LOAD, PRE_INSERT, PRE_DELETE) yang implementasinya sudah ada di dalamnya — kamu cukup memanggilnya via Reflection.
Produk.java — contoh kelas model lain. Punya tiga field beranotasi @ColumnName. Juga punya tiga lifecycle hook methods yang implementasinya sudah ada.
Main.java — driver program yang membaca perintah dari stdin dan memanggil method-method di kelas ORM. Tidak perlu diubah.
Lengkapi dan kumpulkan file ORM.java yang sudah memiliki keterangannya masing-masing. Gunakan file main untuk mengetesnya.
