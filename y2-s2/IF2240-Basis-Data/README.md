# IF2240 Basis Data

## Deskripsi

Kumpulan materi dan aset praktikum IF2240 Basis Data. README ini menjadi indeks, sedangkan soal, skema, dan dump SQL tetap berada di folder masing-masing praktikum.

## Praktikum

| Praktikum | Fokus | Dokumentasi |
| --- | --- | --- |
| 0 | Eksplorasi SQL dan SQL Basic Operation | [README Praktikum 0](prak0/README.md) |
| 1 | Query dasar dan operasi himpunan | [README Praktikum 1](prak1/README.md) |
| 2 | Subquery, agregasi, join, DDL, dan DML | [README Praktikum 2](prak2/README.md) |
| 3 | Cakupan SQL terpadu dengan basis data restoran | [README Praktikum 3](prak3/README.md) |

## Referensi umum

- [Aturan dan Teknis Praktikum](Aturan%20dan%20Teknis%20Praktikum.pdf)
- [Petunjuk Penggunaan MariaDB](Petunjuk%20Penggunaan%20MariaDB.pdf)

## Catatan Docker

Praktikum 1, 2, dan 3 menerbitkan port host `3306`. Hanya satu dari ketiganya yang dapat berjalan dan mengikat port tersebut pada satu waktu. Hentikan praktikum lain sebelum menjalankan praktikum yang dipilih.

## Cara kerja Docker Compose

Jalankan perintah dari folder praktikum yang memiliki `docker-compose.yml`. Compose membuat satu service MariaDB bernama `db`, mengambil image praktikum yang tercantum di YAML, membuat database dari `MARIADB_DATABASE`, lalu menerbitkan port container `3306` ke port host `3306`.

```bash
docker compose config --quiet
docker compose up -d
docker compose ps
docker compose logs -f db
```

Gunakan `stop` dan `start` untuk menghentikan sementara lalu melanjutkan container. Gunakan `down` untuk menghapus container dan network Compose. Hindari `docker compose down -v` kecuali ingin melakukan reset destruktif karena volume dan data database dapat ikut dihapus.

Koneksi dari host menggunakan user `labdas`, password `praktikum`, dan database sesuai praktikum:

```bash
mysql -h 127.0.0.1 -u labdas -D <nama-database> -p
```

Detail image dan nama database ada di README praktikum 1, 2, dan 3. Praktikum 0 tidak memiliki file Compose dan perlu dijalankan dengan MariaDB secara manual.
