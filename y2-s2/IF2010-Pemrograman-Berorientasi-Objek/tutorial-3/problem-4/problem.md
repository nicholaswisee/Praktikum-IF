Nama File: TaskManager.cpp

Sebagai Nimon kepercayaan Gro, kamu ditugaskan untuk membantu mengelola daftar tugas rahasia laboratorium menggunakan kelas TaskManager. Data tugas para Nimon disimpan di dalam container STL dan diproses menggunakan algoritma STL berbasis iterator.

Gro sangat tidak suka kekacauan, jadi semua tugas harus dikelola dengan rapi dan efisien!

Untuk soal ini, implementasi file TaskManager.cpp dengan ketentuan:

Mengelola data melalui method pada header: add, update, remove, dan find
Mencari data tugas menggunakan algoritma standar (misalnya std::find_if)
Mengurutkan data tugas menggunakan std::sort
Menghitung total durasi menggunakan algoritma STL (misalnya std::accumulate)
Menggunakan iterator container (seperti begin() dan end()) saat pemrosesan
Spesifikasi kelas tersedia pada TaskManager.hpp dan driver tersedia pada main.cpp (tidak boleh diubah).

Format Masukan

Baris pertama berisi sebuah integer Q yang menyatakan banyak perintah dari Gro. Selanjutnya terdapat Q baris perintah:

1 id title priority duration : jika id belum ada, tambahkan tugas baru dari Gro (gunakan add). Jika sudah ada, perbarui tugas lama (gunakan update).
2 id : hapus tugas dengan id.
3 id : tampilkan detail tugas dengan id.
4 : urutkan tugas berdasarkan priority menurun, jika sama maka duration menaik, jika masih sama maka id menaik.
5 minPriority : hitung total durasi semua tugas dengan priority >= minPriority.
6 keyword : tampilkan semua tugas yang title-nya mengandung keyword (case-sensitive).
7 : tampilkan semua tugas sesuai urutan saat ini di container.
Format Keluaran

Perintah 1 : cetak OK
Perintah 2 : cetak DELETED jika berhasil, jika tidak NOT FOUND
Perintah 3 : cetak format id|title|priority|duration jika ditemukan, jika tidak NOT FOUND
Perintah 4 : cetak SORTED
Perintah 5 : cetak sebuah integer total durasi
Perintah 6 dan 7 :
Jika tidak ada data yang ditampilkan, cetak EMPTY
Setelah seluruh data (atau EMPTY), cetak END
Contoh Masukan dan Keluaran

Masukan:

8
1 T1 belajar_stl 4 90
1 T2 tugas_oop 5 120
3 T1
5 4
4
7
2 T3
6 oop
Keluaran:

OK
OK
T1|belajar_stl|4|90
210
SORTED
T2|tugas_oop|5|120
T1|belajar_stl|4|90
END
NOT FOUND
T2|tugas_oop|5|120
END
Catatan: Gunakan STL Algorithms dan iterators dalam implementasi Anda. Anda diperbolehkan mengimplementasikan fungsi lain sebagai parameter fungsi STL.