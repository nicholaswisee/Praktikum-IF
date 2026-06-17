Seorang insinyur sistem sedang membangun pipeline analitik untuk jaringan sensor industri. Setiap sensor menghasilkan serangkaian pembacaan numerik, beberapa sensor menghasilkan nilai integer (misalnya jumlah getaran), sementara yang lain menghasilkan nilai desimal (misalnya suhu dalam Celsius).

Data dari banyak sensor dikumpulkan ke dalam batch. Setiap batch memiliki sebuah label dan sejumlah nilai pembacaan. Karena jumlah batch bisa sangat banyak, pemrosesan dilakukan secara paralel. Beberapa thread mengerjakan bagian berbeda dari data secara bersamaan, lalu hasilnya digabungkan.

File yang Tersedia
Jangan diubah:

ThreadTracker.java — utilitas untuk melacak dan memverifikasi thread yang benar-benar dijalankan. Pelajari method-method yang tersedia di dalamnya dan gunakan dengan benar di implementasimu.
Perlu dilengkapi:

DataBatch.java — skeleton kelas generik untuk satu batch data. Struktur dan nama method sudah tersedia, namun type parameter dan implementasinya belum diisi.
BatchProcessor.java — skeleton kelas yang mengimplementasikan Runnable. Struktur sudah tersedia, namun tipe generik pada parameter dan implementasinya belum diisi.
DataUtils.java — skeleton kelas utilitas dengan dua method statis. Struktur sudah tersedia, namun tipe generik pada parameter dan implementasinya belum diisi.
Main.java — driver program yang membaca input, membagi batch ke thread, dan mencetak output. Isi blok // TODO yang ada di dalamnya; bagian lain jangan diubah.
Skeleton yang diberikan menggunakan raw type sebagai placeholder. Tugasmu adalah menentukan type parameter dan wildcard yang tepat, lalu mengisi implementasinya. Detail spesifikasi setiap method sudah tersedia sebagai komentar di dalam masing-masing skeleton. Gunakan Main.java sebagai acuan untuk mengetahui tipe apa yang diharapkan.

Format Input
N T
TYPE label k v1 v2 ... vk
TYPE label k v1 v2 ... vk
...
(N baris)
N — jumlah batch
T — jumlah thread (dijamin T ≤ N)
TYPE — tipe batch: INT atau DOUBLE
label — nama batch (string tanpa spasi)
k — jumlah nilai dalam batch
v1 ... vk — nilai-nilai batch sesuai tipe
Format Output
Batch dibagi ke thread secara merata. Jika N tidak habis dibagi T, thread dengan indeks lebih kecil mendapat satu batch ekstra.

Thread 0:
Batch <label>: sum = <sum>
...

Thread 1:
Batch <label>: sum = <sum>
...

(blank line setelah setiap blok thread)

Total items processed: <total_item>
Total sum: <total_sum>
Max: <max_item>
Semua nilai desimal dicetak dengan satu angka di belakang titik (%.1f). Total items processed adalah jumlah elemen (bukan batch) yang diproses oleh semua thread.

Contoh Input dan Output
Input

Output

Penjelasan:

N=5, T=2 → base=2, extra=1
Thread 0 mendapat 3 batch: sensor_a (sum=6.0), sensor_b (sum=100.0), sensor_c (sum=4.0)
Thread 1 mendapat 2 batch: sensor_d (sum=18.0), sensor_e (sum=300.0)
Total item: 3+4+2+3+2 = 14
Total sum: 6+100+4+18+300 = 428.0
Max item: 200 (dari sensor_e)
Batasan
1 ≤ T ≤ N ≤ 100
1 ≤ k ≤ 1.000 (jumlah item per batch)
Label batch hanya mengandung huruf, angka, dan underscore
Nilai INT dalam rentang int; nilai DOUBLE dalam rentang double
Catatan Teknis
Dilarang menggunakan Thread.sleep() untuk sinkronisasi.
Gunakan Locale.US di semua pemanggilan String.format dan printf agar format desimal menggunakan titik (bukan koma).
Format Pengumpulan
Kumpulkan zip yang berisi: DataBatch.java, BatchProcessor.java, DataUtils.java, dan Main.java.
