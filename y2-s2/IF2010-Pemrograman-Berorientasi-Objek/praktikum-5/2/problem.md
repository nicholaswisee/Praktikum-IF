Gro sedang membangun sistem penyimpanan data untuk gudang risetnya. Gudangnya memiliki tiga laci khusus: satu untuk bilangan bulat (integer), satu untuk bilangan desimal (double), dan satu untuk kata-kata (string).

Yang membuatnya menarik: semua laci ini berbagi struktur yang sama, hanya tipe datanya yang berbeda. Dinda ingin menggunakan Java Generics agar kode tidak perlu ditulis ulang untuk setiap tipe.

File Main.java sudah disediakan dan tidak boleh diubah. Tugasmu adalah mengimplementasikan kelas-kelas generik yang digunakan oleh Main.java.

File yang Disediakan (tidak boleh diubah):

Main.java
File yang Harus Dibuat:

Laci.java
LaciAngka.java
LaciUtil.java
Spesifikasi Kelas

1. Kelas Generik Laci<T>

Kelas generik yang menyimpan item bertipe T dalam array dengan kapasitas tetap 10. Implementasikan method-method berikut:

Laci(String label) — konstruktor, simpan label laci
boolean simpan(T item) — tambah item ke laci. Kembalikan true jika berhasil, false jika laci sudah penuh
T ambil(int i) — kembalikan item pada indeks ke-i (dimulai dari 1). Kembalikan null jika indeks tidak valid
void set(int i, T item) — ganti item pada indeks ke-i (dimulai dari 1). Abaikan jika indeks tidak valid
int ukuran() — kembalikan jumlah item saat ini
String getLabel() — kembalikan label laci
String toString() — format: Laci[label]: [item1, item2, ...] 2. Kelas Generik LaciAngka<T extends Number>

Kelas turunan dari Laci<T> yang khusus untuk tipe angka (Integer, Double, dsb.). Gunakan bounded type parameter T extends Number agar bisa mengakses method doubleValue(). Implementasikan:

LaciAngka(String label) — konstruktor
double total() — jumlahkan semua item, kembalikan sebagai double
double rataRata() — kembalikan rata-rata semua item sebagai double. Kembalikan 0.0 jika laci kosong 3. Kelas Utilitas LaciUtil

Kelas dengan method static generik. Perhatikan tipe parameter pada setiap method:

static <T> void tukar(Laci<T> laci, int i, int j) — tukar posisi item pada indeks ke-i dan ke-j (1-based).
Tidak perlu tahu tipe spesifik T, cukup pakai tipe parameter generik.
static <T extends Comparable<T>> T terbesar(Laci<T> laci) kembalikan item terbesar dalam laci. Kembalikan null jika laci kosong.
Bounded type parameter memastikan item bisa dibandingkan satu sama lain.
Format Output

Perintah Kondisi Output
SIMPAN INT <val> — Disimpan: val
SIMPAN DBL <val> — Disimpan: val
SIMPAN STR <val> — Disimpan: val
AMBIL INT/DBL/STR <i> indeks valid nilai item ke-i
AMBIL INT/DBL/STR <i> indeks tidak valid null
TOTAL INT/DBL — Total: X.X
RATA INT/DBL — Rata-rata: X.X
TUKAR INT/STR <i> <j> — (tidak ada output)
TERBESAR INT/STR laci tidak kosong nilai item terbesar
TERBESAR INT/STR laci kosong Laci kosong
INFO INT/DBL/STR — Laci[label]: [item1, item2, ...]
