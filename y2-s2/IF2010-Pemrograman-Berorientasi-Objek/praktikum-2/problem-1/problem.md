Dunia Middle-earth dihuni oleh berbagai makhluk, masing-masing dengan sifat dan kemampuannya sendiri. Kamu diberikan kelas Creature (.hpp dan .cpp) beserta file main.cpp. Semua file ini tidak boleh diubah.

Tugasmu adalah mendesain dan mengimplementasikan lima kelas turunan (Elf, Ranger, Maiar, Wizard, dan Balrog) dengan menerapkan konsep Inheritance dan Access Modifiers (public, protected, atau private) yang tepat. Pisahkan deklarasi (.hpp) dan implementasi (.cpp) untuk setiap kelas. Kumpulkan dalam format .zip yang berisi hanya kelima kelas yang kamu implementasikan.

Spesifikasi Kelas
Elf

Elf adalah (IS-A) Creature. Kode mana pun yang bekerja dengan Creature harus bisa menerima Elf secara langsung — upcast ke Creature\* harus diperbolehkan dari luar kelas (misal dari main).
Memiliki atribut tambahan grace (int).
Constructor: menerima name, hp, grace.
describe(): mencetak "Elf [<name>] | HP: <hp> | Grace: <grace>\n"
getGrace(): mengembalikan nilai grace
Ranger

Ranger adalah (IS-A) Elf, dan dengan demikian juga Creature. Upcast ke Elf* maupun Creature* harus diperbolehkan dari luar kelas. Ranger membawa arrows (int).
Constructor: menerima name, hp, grace, arrows.
describe(): mencetak "Ranger [<name>] | HP: <hp> | Grace: <grace> | Arrows: <arrows>\n"
shoot(): mencetak "<name> draws an arrow (grace: <grace>) and fires! Arrows left: <arrows-1>\n", lalu kurangi arrows sebanyak 1.
Maiar

Maiar menggunakan (HAS-A) struktur Creature secara internal, ia punya nama dan HP, tetapi tidak dikenal sebagai Creature dari luar kelas. Kode eksternal tidak boleh melakukan upcast Maiar* ke Creature*. Namun, kelas-kelas yang mewarisi Maiar masih bisa mengakses atribut Creature (seperti name dan hp) secara internal. Maiar memiliki atribut power (int).
Constructor: menerima name, hp, power, constructor tidak bisa diinstansiasi langsung dari luar; hanya bisa dipanggil oleh subclass.
describe(): mencetak "Maiar [<name>] | HP: <hp> | Power: <power>\n"
getPower(): mengembalikan nilai power
Wizard

Wizard mewarisi Maiar dengan hubungan yang sepenuhnya tersembunyi dari luar kelas, baik dari kode eksternal maupun dari subclass Wizard. Tidak ada yang boleh upcast ke Maiar* atau Creature*, dan subclass Wizard pun tidak boleh mengakses atribut Maiar secara langsung. Wizard membawa staffName (string).
Constructor: menerima name, hp, power, staffName.
describe(): mencetak "Wizard [<name>] | HP: <hp> | Staff: <staffName>\n"
cast(): mencetak "<name> channels <power> power through <staffName>!\n"
Balrog

Balrog juga mewarisi Maiar dan dapat diakses dari luar kelas Balrog itu sendiri. Namun seperti semua Maiar, Balrog tidak dikenal sebagai Creature dari luar, kode eksternal tidak boleh upcast Balrog* ke Creature*. Balrog membawa whipName (string).
Constructor: menerima name, hp, power, whipName.
describe(): mencetak "Balrog [<name>] | HP: <hp> | Power: <power> | Whip: <whipName>\n"
rage(): mencetak "<name> cracks <whipName> with <power> power!\n"
SARAN

- Tentukan mode inheritance setiap kelas sebelum menulis kode apapun. Implementasi kelas cukup mudah, cuma nguli aja ^ ^
- Jangan lupa untuk mendefinisikan file .hpp kalian, bisa dengan #pragma once atau #ifndef seperti di C
- Jangan lupa untuk tambahkan keyword override method describe dari Creature
- Has-A relationship di kelas Maiar bukanlah Composition melainkan bentuk use case dari salah satu mode inheritance
