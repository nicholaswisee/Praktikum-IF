Intergalactic Cargo Bay
"Waktunya telah tiba! Alam semesta ini akan segera bertekuk lutut di bawah kakiku!" tawa Cipher menggema.

Untuk melanjutkan rencana penaklukan multiverse, Cipher menugaskan Pasukan Nimon untuk menyelundupkan berbagai barang. Mereka membangun sebuah sistem kargo antar-galaksi. Namun, Jendral Nimon yang bertugas tidak terlalu memahami bahasa pemrograman C++, sehingga sistem Cargo mereka sering meledak!

Cipher sangat murka dan membuang sang Jendral di dimensi lain. Kini, nyawa Anda bergantung pada kemampuan Anda merancang ulang Intergalactic Cargo Bay menggunakan Generics (Templates) dan Exception Handling!

Deskripsi Tugas
Anda diminta untuk melengkapi implementasi dari tiga buah komponen utama sistem, yaitu CargoException.hpp, Item.hpp, dan CargoBay.hpp. File header telah berisikan deklarasi dan penjelasan implementasi. Anda tidak diperkenankan menggunakan struktur data bawaan STL (seperti std::vector atau std::stack) pada internal Cargo. Link codebase.

Telah disediakan juga file main.cpp untuk mengetes implementasi kalian.

Contoh Input main.cpp

```
CREATE STRING BayX 3
CREATE STRING BayY 1
POP STRING BayX
PUSH STRING BayX Alpha 50
PUSH STRING BayX Beta 70
PUSH STRING BayX Gamma 90
PUSH STRING BayX Delta 100
EXTRACT STRING BayX Omega
TRANSFER STRING BayX BayY 2
FORGE STRING BayX Ultra_
POP STRING BayY
POP STRING BayX
TRANSFER STRING BayX BayY 2
```

Contoh Output

```
>> Created STRING bay: BayX
>> Created STRING bay: BayY
[ERROR 2] Cargo is empty!
>> Pushed to BayX
>> Pushed to BayX
>> Pushed to BayX
[ERROR 1] Cargo is full!
[ERROR 3] Item not found!
[ERROR 5] Transfer failed due to destination capacity!
>> Forge BayX success
Popped from BayY -> ID: 3 | Data: Gamma | Durability: 90
Popped from BayX -> ID: 4 | Data: Ultra_BetaAlpha | Durability: 60
[ERROR 4] Not enough items in cargo!
```

Format Pengumpulan
Kumpulkan CargoException.hpp, Item.hpp, dan CargoBay.hpp.
Kumpulkan dalam satu file zip (nama file zip dibebaskan).
