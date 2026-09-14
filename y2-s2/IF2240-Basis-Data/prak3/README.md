# Praktikum 3

## Cakupan SQL

Praktikum ini merangkum dan memperluas seluruh cakupan SQL berikut:

- Query dengan `SELECT`, `DISTINCT`, `FROM`, `WHERE`, `AND`, `OR`, dan `LIKE`
- Operasi himpunan `UNION`, `INTERSECT`, dan `EXCEPT`
- Subquery dengan `EXISTS`, `IN`, dan `WITH`
- Agregasi dan penyaringan hasil dengan `GROUP BY`, `ORDER BY`, dan `HAVING`
- `NATURAL JOIN`, `INNER JOIN`, dan `OUTER JOIN` dengan kondisi `ON`
- DDL: `CREATE`, `ALTER`, dan `VIEW`
- DML: `UPDATE`, `INSERT`, dan `DELETE`
- Fungsi dan ekspresi SQL dasar seperti `LIMIT`, alias kolom, `CONCAT()`, dan `NOW()` sesuai kebutuhan soal.

## Aset

- [Soal Praktikum 3](Soal%20Praktikum%203%20Lab%204.pdf)
- [Skema Basis Data Praktikum 3](Skema%20Basis%20Data%20Praktikum%203.pdf)
- [Restaurant.sql](Restaurant.sql)
- [docker-compose.yml](docker-compose.yml)

## Database dan Compose

Praktikum ini menggunakan image `167.205.32.151:5000/restaurant:latest` dan database `restaurant`. Panduan lifecycle Compose, koneksi, serta peringatan port ada di [README Basis Data](../README.md#cara-kerja-docker-compose).

```bash
docker compose up -d
docker compose ps
docker compose logs -f db
```

Koneksi dari host:

```bash
mysql -h 127.0.0.1 -u labdas -D restaurant -p
```

Password user adalah `praktikum`. Praktikum 1, 2, dan 3 menggunakan host port `3306`, sehingga hanya satu Compose dari ketiganya yang dapat aktif pada satu waktu.
