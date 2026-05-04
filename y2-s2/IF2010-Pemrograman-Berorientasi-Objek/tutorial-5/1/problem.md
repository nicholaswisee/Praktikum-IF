Yu-Gi-Mon!
Para Nimon sedang bosan karena terlalu sering bermain Nimonspoli. Mereka kemudian meminta kalian untuk membantu mereka membuat sebuah game kartu yang jauh lebih seru bernama Yu-Gi-Mon! Di Game ini terdapat sebuah kartu Monster. Kartu monster ini hanya merepresentasikan informasi kartu. Namun, kartu monster dapat di-summon ke field. Ketika berhasil di-summon, kartu bisa memiliki fungsi-fungsi tambahan. Agar kelas monster yang sudah ada tidak perlu diubah, bantulah Nimon mengimplementasikan interface ISummoned beserta kelas SummonedMonster untuk monster yang telah di-summon.

Spesifikasi File
Nama Kelas Spesifikasi
InterfaceISummoned
Method:
boolean flip():
Mengubah kondisi kartu dari tertutup menjadi terbuka kemudian mengembalikan true. Bila kartu sudah dalam keadaan terbuka, tidak terjadi apa-apa dan mengembalikan false
void rotate():
Mengubah posisi kartu dari menyerang ke bertahan atau sebaliknya.
int getPositionValue:
Mengembalikan nilai attack jika posisi kartu menyerang. Mengembalikan nilai defense jika posisi kartu bertahan.
void render():
Melakukan print ke terminal, sudah diimplementasi pada kelas SummonedMonster yang telah diberikan.
ClassSummonedMonster
Attributes:
private Monster monster:
Referensi ke informasi kartu monster.
private boolean isFaceUp:
True artinya kartu dalam keadaan terbuka. False artinya kartu dalam keadaan tertutup.
private boolean isAttacking:
True artinya kartu dalam posisi menyerang. False artinya kartu dalam posisi bertahan.
Konstruktor: public SummonedMonster(Monster m, boolean faceUp, boolean attackPos):
Inisialisasi semua Attributes.
Method: Implementasi semua method dari interface ISummoned
