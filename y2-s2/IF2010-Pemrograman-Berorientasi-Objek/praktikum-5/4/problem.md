Kumpulkan File: BoardGameAnalytics.java (TANPA fungsi main)

Pada soal ini, Anda diminta melengkapi implementasi kelas BoardGameAnalytics untuk mengelola data board game, rating pemain, dan stok game.

File yang Disediakan

Kelas model BoardGame.
Starter file BoardGameAnalytics.
Atribut pada BoardGameAnalytics

List<BoardGame> games untuk menyimpan semua board game.
Set<String> players untuk menyimpan nama pemain unik tanpa duplikasi.
Map<String, Integer> stockByGame untuk menyimpan stok game berdasarkan nama game.
Map<String, List<Integer>> ratings untuk menyimpan semua rating untuk tiap game.
Tugas

Lengkapi method berikut:

public BoardGameAnalytics()
public void addGame(BoardGame game, int initialStock)
public void addRating(String gameName, String playerName, int rating)
private double getAverageRating(String gameName)
public List<String> getLowStockGames(int threshold)
public List<String> getRecommendedGames(int playerCount, double minRating)
Spesifikasi Method

BoardGameAnalytics()
Menginisialisasi semua collection yang dibutuhkan.

addGame(BoardGame game, int initialStock)
Menambahkan game baru beserta stok awal. Jika sudah ada game dengan nama yang sama, game tidak ditambahkan lagi ke games, tetapi stok game tersebut tetap ditambahkan ke stockByGame.

addRating(String gameName, String playerName, int rating)
Menambahkan rating untuk game bernama gameName. Nama pemain harus disimpan di players agar setiap pemain hanya tercatat satu kali.

getAverageRating(String gameName)
Mengembalikan rata-rata rating game tersebut. Jika belum ada rating, kembalikan 0.0.

getLowStockGames(int threshold)
Mengembalikan daftar nama game yang memiliki stok kurang dari threshold. Hasil harus diurutkan berdasarkan stok menaik. Jika terdapat beberapa game dengan stok sama, urutkan berdasarkan nama game secara alfabetis.

getRecommendedGames(int playerCount, double minRating)
Mengembalikan daftar nama game yang memenuhi seluruh syarat berikut:

Game dapat dimainkan oleh playerCount pemain, yaitu minPlayers <= playerCount <= maxPlayers.
Game memiliki rata-rata rating minimal minRating.
Hasil harus diurutkan secara alfabetis menaik.

Ketentuan

Wajib menggunakan Java Collection Framework untuk menyimpan dan mengelola data.
Wajib menggunakan Stream API pada getAverageRating, getLowStockGames, dan getRecommendedGames.
Format Input (pada Main yang telah disediakan)

N
name minPlayers maxPlayers playTime category stock
... (sebanyak N baris)
R
gameName playerName rating
... (sebanyak R baris)
threshold
playerCount minRating
Keterangan:

N adalah jumlah board game.
Setiap baris game berisi nama game, jumlah pemain minimum, jumlah pemain maksimum, waktu bermain, kategori, dan stok awal.
R adalah jumlah rating.
Setiap baris rating berisi nama game, nama pemain, dan nilai rating.
threshold digunakan untuk memanggil getLowStockGames.
playerCount dan minRating digunakan untuk memanggil getRecommendedGames.
Format Output

Program mencetak tepat dua baris.

Baris pertama:

LOW_STOCK <name1> <name2> ...
Jika tidak ada game dengan stok di bawah threshold, cetak:

LOW_STOCK -
Baris kedua:

RECOMMENDED <name1> <name2> ...
Jika tidak ada game yang direkomendasikan, cetak:

RECOMMENDED -
Contoh

Input

4
Catan 3 4 90 Strategy 5
Dobble 2 8 15 Party 2
Chess 2 2 30 Abstract 1
Pandemic 2 4 45 Cooperative 6
5
Catan alice 9
Catan bob 8
Dobble charlie 7
Dobble alice 6
Pandemic dave 8
3
3 7.0
Output

LOW_STOCK Chess Dobble
RECOMMENDED Catan Pandemic
Penjelasan Contoh

Chess dan Dobble memiliki stok di bawah 3, sehingga muncul pada baris LOW_STOCK.
Catan dapat dimainkan oleh 3 pemain dan rata-rata ratingnya 8.5.
Pandemic dapat dimainkan oleh 3 pemain dan rata-rata ratingnya 8.0.
Dobble dapat dimainkan oleh 3 pemain, tetapi rata-rata ratingnya 6.5 sehingga tidak direkomendasikan.
Chess tidak dapat dimainkan oleh 3 pemain.
