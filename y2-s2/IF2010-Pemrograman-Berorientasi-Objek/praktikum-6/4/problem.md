Nama File: WeatherSystem.zip

[ BONUS ]

Latar Belakang

Observer Pattern adalah salah satu behavioral design pattern yang mendefinisikan mekanisme subscription: satu objek (subject/publisher) menyimpan daftar objek lain (observer/subscriber) dan secara otomatis memberitahu mereka setiap kali terjadi perubahan pada state-nya. Pola ini memisahkan logika "apa yang berubah" dari logika "siapa yang perlu tahu", sehingga komponen menjadi longgar-kait (loosely coupled).

Struktur dasar Observer Pattern terdiri dari:

Subject (Publisher): menyimpan daftar observer dan memanggil update() pada masing-masing observer setiap kali state berubah.
Observer (Subscriber): mendefinisikan interface update() yang dipanggil oleh subject.
Concrete Observer: implementasi nyata dari observer yang bereaksi terhadap notifikasi.
Deskripsi Soal

Kamu diminta membangun sistem pemantau cuaca berbasis Observer Pattern. Dalam sistem ini, sebuah stasiun cuaca (subject) menyimpan data suhu dan kelembaban. Setiap kali data cuaca diperbarui, semua tampilan yang terdaftar (observer) akan otomatis diberitahu dan menampilkan nilai terkini.

File Main.java (driver) sudah disediakan dan tidak boleh diubah. Tugas kamu adalah mengimplementasikan file-file berikut:

WeatherObserver.java: interface observer
WeatherStation.java: subject yang mengelola daftar observer dan data cuaca
TemperatureDisplay.java: observer yang menampilkan suhu
HumidityDisplay.java: observer yang menampilkan kelembaban
Kumpulkan WeatherSystem.zip yang berisi semua file .java yang kamu buat, termasuk Main.java.

Spesifikasi

1. Interface WeatherObserver

Interface yang mendefinisikan kontrak untuk semua observer cuaca.

Method Keterangan
void update(double temperature, double humidity) Dipanggil oleh subject saat data cuaca berubah. Implementasi masing-masing observer menentukan tampilannya.
String getName() Mengembalikan nama unik observer ini. 2. Kelas WeatherStation (Subject / Observable)

Menyimpan data cuaca terkini dan mengelola daftar observer. Wajib memiliki field observers bertipe List<WeatherObserver> dan method notifyObservers() yang dipanggil setiap kali data berubah.

Method / Constructor Keterangan
WeatherStation() Inisialisasi stasiun dengan suhu=0.0, kelembaban=0.0, dan daftar observer kosong.
void addObserver(WeatherObserver observer) Menambahkan observer ke daftar.
boolean removeObserver(String name) Menghapus observer dengan nama yang sesuai. Mengembalikan true jika berhasil, false jika tidak ditemukan.
boolean hasObserver(String name) Mengembalikan true jika observer dengan nama tersebut sudah terdaftar.
void setMeasurements(double temperature, double humidity) Memperbarui data cuaca lalu memanggil notifyObservers().
private void notifyObservers() Memanggil update(temperature, humidity) pada setiap observer dalam urutan pendaftaran.
double getTemperature() Mengembalikan suhu saat ini.
double getHumidity() Mengembalikan kelembaban saat ini.
int getObserverCount() Mengembalikan jumlah observer yang terdaftar. 3. Kelas TemperatureDisplay (Concrete Observer)

Observer yang mencetak suhu saat dipanggil oleh stasiun cuaca.

Method / Constructor Keterangan
TemperatureDisplay(String name) Membuat tampilan suhu dengan nama yang diberikan.
void update(double temperature, double humidity) Mencetak: Display <nama>: Suhu <suhu>
Format suhu: satu angka desimal (%.1f).
Contoh: Display TempA: Suhu 25.0
String getName() Mengembalikan nama tampilan ini. 4. Kelas HumidityDisplay (Concrete Observer)

Observer yang mencetak kelembaban saat dipanggil oleh stasiun cuaca.

Method / Constructor Keterangan
HumidityDisplay(String name) Membuat tampilan kelembaban dengan nama yang diberikan.
void update(double temperature, double humidity) Mencetak: Display <nama>: Kelembaban <kelembaban>%
Format kelembaban: satu angka desimal (%.1f).
Contoh: Display HumidA: Kelembaban 60.0%
String getName() Mengembalikan nama tampilan ini.
Constraint Whitebox

Implementasi kamu akan divalidasi secara struktural oleh PMD. Pastikan:

WeatherStation memiliki field bernama observers.
WeatherStation memiliki method bernama notifyObservers.
Method setMeasurements di WeatherStation memanggil notifyObservers().
Format Masukan

Baris pertama berisi integer Q (jumlah perintah). Diikuti Q baris perintah:

REGISTER <TEMP_DISPLAY|HUMIDITY_DISPLAY> <nama>: daftarkan observer baru
REMOVE <nama>: hapus observer dari daftar
UPDATE <suhu> <kelembaban>: perbarui data cuaca (memicu notifikasi ke semua observer)
STATUS: tampilkan informasi stasiun
Format Keluaran

Perintah Kondisi Keluaran
REGISTER berhasil OK
REGISTER nama sudah terdaftar ALREADY_REGISTERED
REGISTER tipe tidak dikenal UNKNOWN_OBSERVER_TYPE
REMOVE berhasil OK
REMOVE nama tidak ditemukan NOT_FOUND
UPDATE - Setiap observer mencetak satu baris (dalam urutan pendaftaran).
TemperatureDisplay: Display <nama>: Suhu <suhu>
HumidityDisplay: Display <nama>: Kelembaban <kelembaban>%
Jika tidak ada observer, tidak ada keluaran.
STATUS - Station: Suhu=<suhu>, Kelembaban=<kelembaban>%, Observer=<jumlah>
Perintah tidak dikenal - UNKNOWN_COMMAND
Semua nilai suhu dan kelembaban dicetak dengan satu angka desimal (contoh: 25.0, 60.0).

Contoh Masukan dan Keluaran

Masukan 1:

5
REGISTER TEMP_DISPLAY TempA
REGISTER HUMIDITY_DISPLAY HumidA
STATUS
UPDATE 25.0 60.0
STATUS
Keluaran 1:

OK
OK
Station: Suhu=0.0, Kelembaban=0.0%, Observer=2
Display TempA: Suhu 25.0
Display HumidA: Kelembaban 60.0%
Station: Suhu=25.0, Kelembaban=60.0%, Observer=2
Masukan 2:

8
REGISTER TEMP_DISPLAY TA
REGISTER HUMIDITY_DISPLAY HA
UPDATE 20.0 50.0
REMOVE TA
STATUS
UPDATE 25.0 65.0
REMOVE HA
STATUS
Keluaran 2:

OK
OK
Display TA: Suhu 20.0
Display HA: Kelembaban 50.0%
OK
Station: Suhu=20.0, Kelembaban=50.0%, Observer=1
Display HA: Kelembaban 65.0%
OK
Station: Suhu=25.0, Kelembaban=65.0%, Observer=0
Masukan 3:

6
REGISTER TEMP_DISPLAY Screen1
REGISTER TEMP_DISPLAY Screen1
REGISTER HUMIDITY_DISPLAY Screen1
STATUS
UPDATE 25.0 60.0
STATUS
Keluaran 3:

OK
ALREADY_REGISTERED
ALREADY_REGISTERED
Station: Suhu=0.0, Kelembaban=0.0%, Observer=1
Display Screen1: Suhu 25.0
Station: Suhu=25.0, Kelembaban=60.0%, Observer=1
