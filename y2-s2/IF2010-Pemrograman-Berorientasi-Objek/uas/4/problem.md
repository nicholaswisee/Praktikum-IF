Smart Home Controller
Setelah Dr. Neroifa dibantu oleh Kebin dan Stewart terkait pengelolaan kedai jus dan usaha Vending Machine nya, Dr. Neroifa akhirnya bisa menabung untuk membeli rumah. Satu tahun kemudian, Dr. Neroifa akhirnya berhasil membeli rumah impiannya. Namun, Dr. Neroifa ingin melakukan upgrade rumahnya menjadi Smart Home beserta perabotan-perabotan di rumahnya bisa ia kontrol melalui aplikasi. Anda diminta untuk membantu Dr. Neroifa agar sistem kontrol smart homenya dapat berjalan dengan baik dan bisa diterapkan juga jika ia menambah perabotan baru ke depannya.

Spesifikasi Kelas
Nama Kelas Spesifikasi
SmartHomeController
SmartHomeController merupakan utility class yang menyediakan operasi untuk memeriksa status dan menjalankan perintah pada berbagai jenis perangkat smart home saat program sedang berjalan. Kelas ini dirancang agar dapat bekerja dengan objek perangkat apa pun tanpa bergantung secara langsung pada kelas seperti SmartLamp atau SmartFan. Seluruh informasi mengenai atribut dan method perangkat harus diperoleh menggunakan Java Reflection.
Atribut: tidak ada.
Konstruktor: Kelas ini tidak boleh dapat diinstansiasi dari luar kelas karena hanya berisi operasi statis.
Method:
static void printStatus(Object device) mencetak seluruh atribut yang dideklarasikan pada class dari objek device, termasuk atribut yang memiliki akses private.
Setiap atribut dicetak menggunakan format:

namaAtribut = nilaiAtribut

Contoh:
name = Lampu Kamar
brightness = 80
active = false

Jika suatu atribut tidak dapat diakses, method mencetak:

FIELD_ACCESS_ERROR
static void printCommands(Object device) mencetak nama seluruh method yang dideklarasikan pada class dari objek device, termasuk method dengan akses private.
Nama-nama method harus diurutkan secara ascending berdasarkan urutan alfabet agar output konsisten. Setiap nama method dicetak pada baris yang berbeda.
Contoh:

increaseBrightness
resetBrightness
turnOff
turnOn
static void execute(Object device, String command) mencari dan menjalankan method tanpa parameter pada objek device yang memiliki nama sama dengan nilai command. Method yang dijalankan dapat memiliki akses public maupun private. Jika method berhasil ditemukan, method tersebut dijalankan pada objek device.
Jika method dengan nama yang sesuai tidak ditemukan, cetak:
COMMAND_NOT_FOUND
Jika method ditemukan tetapi tidak dapat diakses atau mengalami kegagalan ketika dijalankan, cetak:

COMMAND_EXECUTION_ERROR
Seluruh operasi pada SmartHomeController harus bersifat umum dan dapat digunakan terhadap class perangkat lain yang tidak disebutkan secara langsung pada soal. Oleh karena itu, implementasi tidak boleh bergantung pada pengecekan tipe atau pemanggilan method khusus terhadap SmartLamp, SmartFan, maupun class perangkat tertentu lainnya.
