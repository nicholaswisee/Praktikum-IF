# Praktikum 2

## Cakupan SQL

Praktikum ini membahas:

- Subquery dengan `EXISTS`, `IN`, dan `WITH`
- Agregasi dengan `GROUP BY`, pengurutan dengan `ORDER BY`, dan penyaringan grup dengan `HAVING`
- `NATURAL JOIN`, `INNER JOIN`, dan `OUTER JOIN` dengan kondisi `ON`
- DDL: `CREATE`, `ALTER`, dan `VIEW`
- DML: `UPDATE`, `INSERT`, dan `DELETE`

## Aset

- [Soal Praktikum 2](Soal%20Praktikum%202%20Lab%204.pdf)
- [Skema Basis Data Praktikum 1 dan 2](Skema%20Basis%20Data%20Praktikum%201%20dan%202.pdf)
- [University.sql](University.sql)
- [docker-compose.yml](docker-compose.yml)

## Database dan Compose

Praktikum ini menggunakan image `167.205.32.151:5000/university:latest` dan database `university`. Panduan lifecycle Compose, koneksi, serta peringatan port ada di [README Basis Data](../README.md#cara-kerja-docker-compose).

```bash
docker compose up -d
docker compose ps
docker compose logs -f db
```

Koneksi dari host:

```bash
mysql -h 127.0.0.1 -u labdas -D university -p
```

Password user adalah `praktikum`. Praktikum 1, 2, dan 3 sama-sama memakai host port `3306`. Pastikan Compose dari praktikum lain tidak sedang aktif.
