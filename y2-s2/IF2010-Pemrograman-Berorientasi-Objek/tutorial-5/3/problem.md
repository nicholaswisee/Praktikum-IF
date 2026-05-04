Para Nimon membutuhkan sistem penyimpanan barang yang fleksibel untuk gudang mereka. Gudang ini menyimpan berbagai jenis barang: Elektronik, Makanan, dan Pakaian. Setiap jenis barang disimpan di kotak yang berbeda, tetapi terdapat satu kotak campuran yang dapat menampung semua jenis barang.

Untuk mengelola kotak-kotak ini secara efisien, dibutuhkan method utilitas yang dapat bekerja dengan kotak bertipe apapun. Di sinilah konsep Java Wildcard berperan:

? extends T (upper-bounded): untuk membaca dari kotak bertipe apa saja yang merupakan subtype dari T
? super T (lower-bounded): untuk menulis ke kotak bertipe apa saja yang merupakan supertype dari T
? (unbounded): untuk operasi yang tidak bergantung pada tipe spesifik
Kamu diminta mengimplementasikan file-file berikut. Main.java sudah disediakan dan tidak boleh diubah. Kumpulkan kembali KotakAjaib.zip yang berisi semua file .java yang kamu buat, termasuk Main.java.

Spesifikasi

1. Hierarki Kelas Barang

Buat hierarki kelas dengan Barang sebagai abstract base class:

Barang (abstract)
Atribut: String nama, int harga
Constructor: Barang(String nama, int harga)
Getter: getNama(), getHarga()
Abstract method: String info()
Elektronik extends Barang
Atribut tambahan: int watt
Constructor: Elektronik(String nama, int harga, int watt)
Getter: getWatt()
info() → "[Elektronik] nama - harga IDR (wattW)"
Makanan extends Barang
Atribut tambahan: int kalori
Constructor: Makanan(String nama, int harga, int kalori)
Getter: getKalori()
info() → "[Makanan] nama - harga IDR (kalori kal)"
Pakaian extends Barang
Atribut tambahan: String ukuran
Constructor: Pakaian(String nama, int harga, String ukuran)
Getter: getUkuran()
info() → "[Pakaian] nama - harga IDR (ukuran)" 2. Generic Class Kotak<T extends Barang>

Kelas generik Kotak<T extends Barang> menyimpan item menggunakan ArrayList<T> dengan kapasitas terbatas. Implementasikan method berikut:

Kotak(int kapasitas): Konstruktor dengan kapasitas maksimum
boolean tambah(T item): Menambahkan item. Mengembalikan true jika berhasil, false jika penuh
T ambil(): Mengambil dan menghapus item terakhir (LIFO). Mengembalikan null jika kosong
T lihat(int index): Melihat item pada index tertentu tanpa menghapus. Mengembalikan null jika index tidak valid
int jumlah(): Mengembalikan jumlah item saat ini
int kapasitas(): Mengembalikan kapasitas maksimum
boolean penuh(): Mengembalikan true jika jumlah item sama dengan kapasitas
boolean kosong(): Mengembalikan true jika kotak kosong 3. Kelas KotakUtils (Wildcard)

Kelas utilitas dengan method static yang menggunakan wildcard. Perhatikan tipe wildcard pada setiap method signature:

static void tampilkanSemua(Kotak<? extends Barang> kotak)
Mencetak info() setiap item (satu per baris). Jika kosong, cetak "Kotak kosong".
Menggunakan upper-bounded wildcard karena hanya membaca dari kotak.
static int totalHarga(Kotak<? extends Barang> kotak)
Mengembalikan total harga semua item dalam kotak.
Menggunakan upper-bounded wildcard karena hanya membaca harga.
static Barang termahal(Kotak<? extends Barang> kotak)
Mengembalikan item dengan harga tertinggi, atau null jika kosong.
Menggunakan upper-bounded wildcard karena membaca dan membandingkan item.
static <T extends Barang> int pindahkan(Kotak<? extends T> src, Kotak<? super T> dst)
Memindahkan semua item dari src ke dst secara LIFO. Berhenti jika src kosong atau dst penuh. Mengembalikan jumlah item yang dipindahkan.
Menggabungkan upper-bounded dan lower-bounded wildcard (prinsip PECS: Producer Extends, Consumer Super).
static int hitungItem(Kotak<?> kotak)
Mengembalikan jumlah item dalam kotak.
Menggunakan unbounded wildcard karena tidak perlu tahu tipe spesifik.
Format Masukan

Baris pertama berisi empat integer capE capM capP capC: kapasitas kotak Elektronik, Makanan, Pakaian, dan Campuran (bertipe Kotak<Barang>). Baris kedua berisi integer Q. Selanjutnya Q baris perintah:

ADDE nama harga watt: tambah Elektronik ke kotak 1
ADDM nama harga kalori: tambah Makanan ke kotak 2
ADDP nama harga ukuran: tambah Pakaian ke kotak 3
PRINT n: cetak isi kotak ke-n (1=Elektronik, 2=Makanan, 3=Pakaian, 4=Campuran)
TOTAL n: cetak total harga kotak ke-n
MAHAL n: cetak item termahal di kotak ke-n
COUNT n: cetak jumlah item kotak ke-n
TRANSFER n: pindahkan semua item dari kotak ke-n ke kotak Campuran
Format Keluaran

Perintah Kondisi Keluaran
ADDE / ADDM / ADDP berhasil Ditambahkan: info()
ADDE / ADDM / ADDP kotak penuh Gagal: Kotak penuh!
PRINT n ada isi info() setiap item, satu per baris
PRINT n kosong Kotak kosong
TOTAL n - Total: X
MAHAL n ada isi info() item termahal
MAHAL n kosong Kotak kosong
COUNT n - Jumlah: X
TRANSFER n - Dipindahkan: X item
Contoh Masukan dan Keluaran

Masukan 1:

3 3 3 10
12
ADDE Laptop 15000 65
ADDE Charger 500 10
ADDM Roti 20 250
ADDM Susu 15 150
ADDP Kaos 100 M
ADDP Jaket 300 L
PRINT 1
PRINT 2
PRINT 3
TOTAL 1
TOTAL 2
COUNT 3
Keluaran 1:

Ditambahkan: [Elektronik] Laptop - 15000 IDR (65W)
Ditambahkan: [Elektronik] Charger - 500 IDR (10W)
Ditambahkan: [Makanan] Roti - 20 IDR (250 kal)
Ditambahkan: [Makanan] Susu - 15 IDR (150 kal)
Ditambahkan: [Pakaian] Kaos - 100 IDR (M)
Ditambahkan: [Pakaian] Jaket - 300 IDR (L)
[Elektronik] Laptop - 15000 IDR (65W)
[Elektronik] Charger - 500 IDR (10W)
[Makanan] Roti - 20 IDR (250 kal)
[Makanan] Susu - 15 IDR (150 kal)
[Pakaian] Kaos - 100 IDR (M)
[Pakaian] Jaket - 300 IDR (L)
Total: 15500
Total: 35
Jumlah: 2
Masukan 2:

3 3 3 5
10
ADDE Laptop 15000 65
ADDE Mouse 200 5
ADDM Roti 20 250
ADDP Kemeja 250 L
TRANSFER 1
PRINT 1
PRINT 4
TRANSFER 2
TRANSFER 3
PRINT 4
Keluaran 2:

Ditambahkan: [Elektronik] Laptop - 15000 IDR (65W)
Ditambahkan: [Elektronik] Mouse - 200 IDR (5W)
Ditambahkan: [Makanan] Roti - 20 IDR (250 kal)
Ditambahkan: [Pakaian] Kemeja - 250 IDR (L)
Dipindahkan: 2 item
Kotak kosong
[Elektronik] Mouse - 200 IDR (5W)
[Elektronik] Laptop - 15000 IDR (65W)
Dipindahkan: 1 item
Dipindahkan: 1 item
[Elektronik] Mouse - 200 IDR (5W)
[Elektronik] Laptop - 15000 IDR (65W)
[Makanan] Roti - 20 IDR (250 kal)
[Pakaian] Kemeja - 250 IDR (L)
