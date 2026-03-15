Sebuah toko hewan sedang membangun sistem digital untuk mengelola hewan-hewan peliharaan yang dijualnya. Toko ini menjual tiga jenis hewan: Kucing (Cat), Anjing (Dog), dan Burung Nuri (Parrot).

Semua hewan memiliki sifat dasar yang sama, nama, umur, dan tingkat kebahagiaan, tetapi setiap jenis hewan memiliki perilaku yang berbeda-beda saat bermain, makan, dan bersuara. Sistem ini harus mampu mengelola berbagai jenis hewan dengan konsep polymorphism melalui pointer ke base class.

Tugasmu adalah mengimplementasikan kelas turunan Cat, Dog, dan Parrot berdasarkan kelas dasar abstrak Pet yang sudah disediakan.

Untuk membantu Anda, berikut diberikan file-file yang tidak boleh dirubah.
Pet.hpp: Header kelas dasar Pet (abstract class)
Pet.cpp: Implementasi kelas dasar Pet
Cat.hpp: Header kelas turunan Cat
Dog.hpp: Header kelas turunan Dog
Parrot.hpp: Header kelas turunan Parrot
main.cpp: Program utama (driver)
Anda perlu mengimplementasikan kelas-kelas turunan Cat, Dog, dan Parrot dengan mengikuti spesifikasi berikut:

1. Kelas Cat

Kelas turunan dari Pet yang merepresentasikan kucing. Memiliki sifat tambahan yang menentukan apakah kucing tersebut kucing rumahan atau kucing luar.

Cat(string name, int age, bool indoor) Constructor harus memanggil constructor Pet terlebih dahulu menggunakan initializer list, kemudian menginisialisasi atribut indoor. Setelah itu mencetak: [CAT] {name} entered as indoor cat jika indoor bernilai true, atau [CAT] {name} entered as outdoor cat jika false.
~Cat() Destructor yang mencetak: [CAT] {name} meows goodbye
void makeSound() const override Mengimplementasikan suara kucing. Mencetak: [SOUND] {name}: Meow!
void play() override Meng-override perilaku bermain default. Perilaku bergantung pada tipe kucing:
Jika indoor: menambah happiness sebesar 15 dan mencetak: [PLAY] {name} plays with yarn! Happiness: {happiness}
Jika outdoor: menambah happiness sebesar 20 dan mencetak: [PLAY] {name} chases mice! Happiness: {happiness}
void feed() override Meng-override perilaku makan default. Menambah happiness sebesar 8. Mencetak: [FEED] {name} eats fish! Happiness: {happiness} 2. Kelas Dog

Kelas turunan dari Pet yang merepresentasikan anjing. Memiliki atribut tambahan yang menentukan apakah anjing tersebut sudah terlatih atau belum.

Dog(string name, int age, bool trained) Constructor harus memanggil constructor Pet terlebih dahulu menggunakan initializer list, kemudian menginisialisasi atribut trained. Setelah itu mencetak: [DOG] {name} entered as trained dog jika trained bernilai true, atau [DOG] {name} entered as untrained dog jika false.
~Dog() Destructor yang mencetak: [DOG] {name} barks goodbye
void makeSound() const override Mengimplementasikan suara anjing. Mencetak: [SOUND] {name}: Woof!
void play() override Meng-override perilaku bermain default. Perilaku bergantung pada status latihan:
Jika trained: menambah happiness sebesar 25 dan mencetak: [PLAY] {name} fetches the ball! Happiness: {happiness}
Jika untrained: menambah happiness sebesar 10 dan mencetak: [PLAY] {name} runs around! Happiness: {happiness} 3. Kelas Parrot

Kelas turunan dari Pet yang merepresentasikan burung nuri. Memiliki atribut tambahan yang menyimpan jumlah kata yang diketahui sang burung.

Parrot(string name, int age, int vocabulary) Constructor harus memanggil constructor Pet terlebih dahulu menggunakan initializer list, kemudian menginisialisasi atribut vocabulary. Setelah itu mencetak: [PARROT] {name} entered knowing {vocabulary} words
~Parrot() Destructor yang mencetak: [PARROT] {name} squawks goodbye
void makeSound() const override Mengimplementasikan suara burung nuri. Mencetak: [SOUND] {name}: Squawk! I know {vocabulary} words!
void play() override Meng-override perilaku bermain default. Saat bermain, burung nuri belajar kata baru: menambah vocabulary sebesar 1 dan menambah happiness sebesar 10. Mencetak: [PLAY] {name} learns a new word! Vocabulary: {vocabulary}, Happiness: {happiness}
void feed() override Meng-override perilaku makan default. Menambah happiness sebesar 3. Mencetak: [FEED] {name} eats seeds! Happiness: {happiness}
Contoh Masukan dan Keluaran

Masukan:
