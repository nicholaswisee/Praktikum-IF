# IF3140 Sistem Basis Data

## Deskripsi

Kumpulan materi dan aset praktikum IF3140 Sistem Basis Data. README ini menjadi indeks topik praktikum, sedangkan soal, skema, dan berkas pendukung tersedia di folder masing-masing praktikum.

## Praktikum

| Praktikum | Topik | Deskripsi |
| --- | --- | --- |
| 0 | Pengenalan PostgreSQL | Operasi dasar PostgreSQL. |
| 1 | Database Performance Tuning | Operasi DML PostgreSQL sederhana hingga kompleks; menentukan metode tuning berdasarkan frequent query dan business rule; menerapkan vertical splitting, horizontal splitting, denormalisasi, dan indexing; serta menginterpretasikan performa query melalui `EXPLAIN` dan `\timing`. |
| 2 | Query/SQL Tuning (Query Processing dan Query Optimization) | Memahami pemrosesan query melalui `EXPLAIN ANALYZE`, tahapan pemrosesan DBMS, penyederhanaan query, peran `\timing`, serta karakteristik dan penggunaan operasi DML PostgreSQL untuk optimasi query. |
| 3 | Transactions & Concurrency Control | Memahami dan menerapkan ACID dengan `BEGIN`, `COMMIT`, dan `ROLLBACK`; menganalisis anomali pada isolation level `READ COMMITTED`, `REPEATABLE READ`, dan `SERIALIZABLE`; serta menerapkan lock-based protocol menggunakan `FOR UPDATE` dan `FOR SHARE`. |
| 4 | Database Security | Memahami tipe akses berdasarkan business rule; menerapkan dan menguji akses PostgreSQL dengan akun berbeda; membuat Access Control Matrix; serta membuat function, procedure, dan trigger terkait kontrol akses basis data. |
| 5 | ETL | Memanfaatkan perangkat lunak integrasi data untuk membuat pipeline ETL (Extract, Transform, Load). |
