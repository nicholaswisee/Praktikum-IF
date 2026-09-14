# Praktikum 1

## Cakupan SQL

Praktikum ini membahas query dasar:

- `SELECT`, `DISTINCT`, dan `FROM`
- `WHERE`, `AND`, `OR`, dan `LIKE`
- Operasi himpunan `UNION`, `INTERSECT`, dan `EXCEPT`

## Aset

- [Soal Praktikum 1](Soal%20Praktikum%201%20Lab%202.pdf)
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

Masukkan password `praktikum` saat diminta. Praktikum 1, 2, dan 3 memakai host port `3306`, jadi hanya satu Compose praktikum yang dapat aktif pada satu waktu.
