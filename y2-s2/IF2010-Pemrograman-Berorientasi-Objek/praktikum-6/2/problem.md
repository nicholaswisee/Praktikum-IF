Sliding Window Sum Paralel
Kebin sedang menganalisis deret angka besar. Ia ingin menghitung jumlah elemen setiap sub-array berurutan dengan panjang tetap (window). Karena datanya bisa sangat besar, Kebin membagi pekerjaan ke beberapa thread. Setiap thread menghitung sebagian window dan menyimpan hasilnya ke posisi yang sesuai.
Sliding window adalah teknik untuk mengambil potongan data berurutan dengan ukuran tetap, lalu menggeser potongan itu satu langkah demi satu langkah. Misal data = [1, 2, 3, 4, 5] dan ukuran window W = 3. Maka window yang terbentuk adalah:

Window 0: [1, 2, 3] sum = 6
Window 1: [2, 3, 4] sum = 9
Window 2: [3, 4, 5] sum = 12
Jika panjang data N dan ukuran window W, maka jumlah window yang valid adalah M = N - W + 1.
Buatlah program yang menghitung sum sliding window secara paralel. Perbaikilah file Main.java dan WindowThread.java
Spesifikasi
Jumlah setiap kemungkinan window adalah M = N - W + 1.
Bagi semua window ke T threads dengan selisih <= 1.
Jika M tidak habis dibagi T, thread dengan indeks lebih kecil mendapat 1 window ekstra. Contoh: M=8, T=3, Banyak window per thread [3, 3, 2].
Setiap thread menghitung sum setiap window dan menulis hasilnya ke array output.
Format Input
N
A1 A2 ... AN
W
T
Format Output
Thread 0:
window idx 0, sum = S0
window idx 1, sum = S1
...

Thread 1:
...

Thread T:
...
window idx (M-1), sum = S(M-1)
Contoh
Input

8
1 2 3 4 5 6 7 8
4
3
Output

Thread 0:
window idx 0, sum = 10
window idx 1, sum = 14

Thread 1:
window idx 2, sum = 18
window idx 3, sum = 22

Thread 2:
window idx 4, sum = 26

Batasan
1 ≤ N ≤ 1.000.000
1 ≤ W ≤ N
1 ≤ T ≤ 64
Nilai elemen A dalam rentang int
Catatan
Dilarang menggunakan busy-wait atau Thread.sleep untuk sinkronisasi.
Kumpulkan Main.java dan WindowThread.java dalam satu zip file.
