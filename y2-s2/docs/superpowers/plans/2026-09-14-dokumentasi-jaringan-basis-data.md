# Dokumentasi Jaringan dan Basis Data Implementation Plan

**Goal:** Menambahkan README yang jelas untuk materi Jaringan Komputer dan Praktikum Basis Data 0–3, termasuk operasi Docker Compose.

**Architecture:** Dokumentasi jaringan memakai satu README indeks karena empat kelompok materi sudah dipisahkan oleh `prak1`–`prak4`. Dokumentasi basis data memakai satu README indeks dan satu README per praktikum agar instruksi SQL, berkas sumber, serta perbedaan database Compose mudah ditemukan.

**Tech Stack:** Markdown, Docker Compose v2, MariaDB, SQL.

## Global Constraints

- Tulis dokumentasi dalam Bahasa Indonesia.
- Pertahankan berkas PDF, SQL, dan Compose yang sudah ada.
- Jangan mengarang service atau port di luar konfigurasi lokal.
- Bedakan `docker compose stop`, `down`, dan `down -v`.
- Praktikum 0 tidak memiliki `docker-compose.yml`.
- Buat commit terpisah untuk dokumentasi jaringan dan basis data.

## Tasks

- [x] Tambahkan `IF2230-Jaringan-Komputer/README.md` dengan indeks empat kelompok topik dan tautan PDF.
- [x] Tambahkan `IF2240-Basis-Data/README.md` dengan indeks praktikum dan berkas referensi bersama.
- [x] Tambahkan README `prak0` dengan eksplorasi SQL dan operasi dasar.
- [x] Tambahkan README `prak1` dengan operator SELECT dan panduan Compose database `university`.
- [x] Tambahkan README `prak2` dengan SQL lanjut, DDL/DML, dan panduan Compose.
- [x] Tambahkan README `prak3` dengan cakupan lengkap, database `restaurant`, dan panduan Compose.
- [x] Validasi tautan relatif, perintah, dan cakupan silabus.
- [ ] Commit dalam batch dokumentasi yang independen dan mudah ditinjau.
