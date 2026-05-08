Setelah Kebin dan Stewart puas bermain monopoli dan moba, mereka tak terasa mengalami dehidrasi tinggi. Tidak lama kemudian diam-diam mereka berdua mengamati Dr. Neroifa saat sedang tidak bertugas, malah membuka kedai jus. Mereka berdua langsung bergegas menghampiri Dr. Neroifa untuk membeli jus. Setelah mereka membeli jus, Kebin dan Stewart merasa ada yang aneh dengan jus mereka. Didapati bahwa mereka mendapat pesanan jus yang salah. Akhirnya, Dr. Neroifa mengaku bahwa ia masih sering bingung dengan desain mesin pembuat jus tersebut. Anda diminta untuk membantu Dr. Neroifa agar pengelolaan kedai jus dapat berjalan dengan baik pada: DapurJus.java. Dr. Neroifa hanya menjual beberapa buah saat ini, antara lain, Stroberi, Pisang, dan Apel. Tolong gunakan salah satu konsep OOP agar Dr. Neroifa tidak kesulitan jika ingin mengembangkan bisnisnya, misalnya ingin menambahkan buah Melon, Ceri, Jeruk, Kiwi, Persik, dan Alpukat. ( sebuah referensi ytta )

Spesifikasi Kelas
Nama Kelas Spesifikasi
DapurJus
DapurJus merupakan utility class yang menyediakan operasi untuk memproses daftar bahan dan daftar minuman. Kelas ini tidak menyimpan state dan tidak dimaksudkan untuk dibuat sebagai objek. Seluruh method dipanggil langsung melalui nama kelas.
Atribut: tidak ada.
Konstruktor: Kelas ini tidak boleh dapat diinstansiasi dari luar kelas karena hanya berisi operasi statis.
Method:
static void cekBahan(??? daftarBahan) mencetak deskripsi setiap bahan pada daftarBahan.
static int hitungTotalManis(??? daftarBahan) mengembalikan jumlah total tingkat manis dari seluruh bahan pada daftarBahan.
static void buatJusApelDefault(??? daftarMinuman) oleh karena Dr. Neroifa memiliki kebun apel yang selalu panen, ia memiliki standar menu yang selalu ada dalam daftar jus apel sehingga tambahkan secara default dua objek Jus Apel berikut, "Jus Apel Original" dan "Jus Apel Madu" ke dalam daftarMinuman.
static void cetakRakUmum(??? rak) mencetak seluruh isi rak. Method ini dapat menerima list dengan tipe apa pun.

Untuk memudahkan pengujian class, berikut program Main yang dapat Anda coba beserta file-file lainnya yang terkait
