# IF3170 Inteligensi Artifisial

## Deskripsi

Kumpulan notebook, data, dan aset praktikum IF3170 Inteligensi Artifisial. Notebook praktikum dapat dijalankan menggunakan virtual environment Python dan dependensi yang tercantum di `requirements.txt`.

## Praktikum

| Praktikum | Fokus                            | Dokumentasi                                    |
| --------- | -------------------------------- | ---------------------------------------------- |
| 1         | Data Understanding & Preparation | Notebook dan data tersedia di [prak1](prak1/). |
| 1         | Supervised Learning              | TBA                                            |

## Menjalankan Notebook

Dari folder ini, buat dan aktifkan virtual environment, lalu pasang dependensi:

```bash
python3 -m venv .venv
source .venv/bin/activate  # Windows: .venv\Scripts\activate
python -m pip install -r requirements.txt
python -m pip install ipykernel
```

Pilih kernel `.venv` di Jupyter. File data praktikum berada di folder `prak1/data/`.
