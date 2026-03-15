Anda diberikan kelas Vehicle (kelas dasar/base class) beserta tiga kelas "cucu" (Car, Submarine, Drone) dan file main.cpp. Semua file ini tidak boleh diubah. File Soal

Diberikan pula expected output dari main.

Tugas Anda adalah mendesain dan mengimplementasikan tiga kelas "anak" yang menjadi penghubung antara Vehicle dan kelas cucu:

LandVehicle — menghubungkan Vehicle ↔ Car
WaterVehicle — menghubungkan Vehicle ↔ Submarine
AirVehicle — menghubungkan Vehicle ↔ Drone
Anda harus menentukan sendiri mode pewarisan (public, protected, atau private) yang tepat untuk setiap kelas anak berdasarkan ketentuan berikut:

Ketentuan Aksesibilitas dari Kelas Cucu

### Car (turunan LandVehicle):

Dapat mengakses brand dan maxSpeed secara langsung
Dapat memanggil getSpec() dan getVehicleId()
getSpec() dapat dipanggil dari main() (tetap public)

### Submarine (turunan WaterVehicle):

Dapat mengakses brand dan maxSpeed secara langsung
Dapat memanggil getSpec() dan getVehicleId() secara internal (dari dalam kelas)
getSpec() tidak dapat dipanggil dari main() → perlu method wrapper showSpec()

### Drone (turunan AirVehicle):

Tidak dapat mengakses brand maupun maxSpeed secara langsung → perlu method wrapper getBrandName()
Tidak dapat memanggil getSpec() maupun getVehicleId() dari mana pun → perlu method wrapper showSpec()
Tidak dapat mengakses vehicleId secara langsung
Kumpulkan AirVehicle.hpp, AirVehicle.cpp, LandVehicle.hpp, LandVehicle.cpp, WaterVehicle.hpp, WaterVehicle.cpp dalam format ZIP
