## Steam Spring Sale

Satu jam tersisa dari Steam Spring Sale. Tugasmu adalah membangun sebuah CartManager, sistem yang memungkinkan pemain mengelola keranjang aktif mereka, melacak game yang sudah dibeli, dan menerapkan kupon diskon flash sekali pakai. Beberapa game muncul berkali-kali di katalog dengan harga berbeda, dan sistem harus selalu menjaga urutan keranjang sesuai urutan penambahan sambil tetap mendukung berbagai operasi.

Deskripsi
Implementasikan sebuah class CartManager yang menyimpan dua vector internal: satu untuk keranjang aktif dan satu untuk library game yang sudah dibeli. Class ini harus mendukung operasi berikut:

Method Deskripsi
void addToCart(string title, float price) Menambahkan game ke akhir keranjang. Judul yang sama boleh muncul lebih dari sekali.
bool removeFromCart(string title) Menghapus kemunculan pertama game dengan judul tersebut. Kembalikan true jika berhasil, false jika tidak ditemukan. Urutan harus tetap terjaga.
void checkout() Memindahkan semua game dari keranjang ke vector pembelian, lalu mengosongkan keranjang. Jika keranjang kosong, tidak melakukan apa-apa.
float cartTotal() Mengembalikan total harga semua item di keranjang.
float applyDiscount(float percent) Menerapkan diskon (misalnya 10.0 = 10%) ke semua item dalam keranjang secara langsung. Mengembalikan total baru. Jika keranjang kosong, kembalikan 0.0.
int countInCart(string title) Menghitung berapa kali game dengan judul tersebut muncul di keranjang.
void printCart() Menampilkan isi keranjang dengan format: [i] Title - $X.XX. Jika kosong, tampilkan Cart is empty. (sudah diimplementasikan di kode template)
void printPurchased() Menampilkan daftar pembelian dengan format yang sama. Jika kosong, tampilkan No purchases yet. (sudah diimplementasikan di kode template)
int totalPurchased() Mengembalikan jumlah total game yang ada di library.
Format Input
Baris pertama berisi integer q — jumlah operasi. Setiap operasi berupa:

ADD title price — panggil addToCart
REMOVE title — jika berhasil: Removed: title, jika gagal: Not found: title
CHECKOUT — panggil checkout()
TOTAL — tampilkan Cart total: $X.XX
DISCOUNT percent — tampilkan After discount: $X.XX
COUNT title — tampilkan title: N in cart
PRINT_CART
PRINT_PURCHASED
PURCHASED_COUNT — tampilkan Total purchased: N
Judul game hanya satu kata. Harga berupa float positif dengan maksimal 2 angka di belakang koma.

Format Pengumpulan
Kumpulkan file CartManager.cpp

Batasan
Wajib menggunakan std::vector
Penghapusan harus menjaga urutan
1 ≤ q ≤ 200
Ukuran keranjang: 0 ≤ n ≤ 100
Harga: 0.01 ≤ price ≤ 999.99
Diskon: 0.0 ≤ percent ≤ 100.0
Contoh
Input:
12
ADD Hades 12.49
ADD Celeste 4.99
ADD Hades 9.99
COUNT Hades
TOTAL
DISCOUNT 10.0
REMOVE Celeste
PRINT_CART
CHECKOUT
PRINT_PURCHASED
PURCHASED_COUNT
PRINT_CART
Output:
Hades: 2 in cart
Cart total: $27.47
After discount: $24.72
Removed: Celeste
[0] Hades - $11.24
[1] Hades - $8.99
No purchases yet.
[0] Hades - $11.24
[1] Hades - $8.99
Total purchased: 2
Cart is empty.
Tips
Untuk mempermudah pengecekan output, masukkan input ke sebuah file txt (misal 1.txt) dan jalankan ./test < 1.txt (sesuaikan nama file executablesnya)
