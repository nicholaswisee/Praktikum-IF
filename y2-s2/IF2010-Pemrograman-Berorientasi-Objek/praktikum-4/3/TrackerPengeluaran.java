public class TrackerPengeluaran {
    private Catatan[][] matriks;

    public TrackerPengeluaran() {
        // TODO:
        // 1. Inisialisasi atribut matriks sebagai array 2 dimensi berukuran
        // 4x3.
        // 2. Baris merepresentasikan minggu ke-1 s.d. minggu ke-4.
        // 3. Kolom merepresentasikan kategori: 0=Makan, 1=Transportasi,
        // 2=Tugas.
        // 4. Seluruh elemen awal bernilai null (belum ada catatan).
        this.matriks = new Catatan[4][3];
    }

    public void setCatatan(int minggu, int kategori, int nominal,
                           String deskripsi) {
        // TODO:
        // 1. Ubah parameter minggu dari indeks berbasis 1 menjadi indeks array
        // berbasis 0.
        // 2. Validasi indeks minggu dan kategori sebelum mengakses matriks.
        // - Minggu valid: 1..4
        // - Kategori valid: 0..2
        // 3. Jika valid, isi matriks pada posisi [minggu-1][kategori]
        // dengan objek Catatan baru berisi nominal dan deskripsi.
        // 4. Jika tidak valid, cetak tepat: "Indeks tidak valid!" lalu newline.
        //
        int indeks = minggu - 1;
        if (indeks < 0 || indeks > 3 || kategori < 0 || kategori > 2) {
            System.out.println("Indeks tidak valid!");
            return;
        }

        this.matriks[indeks][kategori] = new Catatan(nominal, deskripsi);
    }

    public int totalPerMinggu(int minggu) {
        // TODO:
        // 1. Hitung total nominal seluruh catatan pada minggu yang diminta.
        // 2. Parameter minggu menggunakan indeks berbasis 1, ubah dulu ke
        // indeks array.
        // 3. Jika minggu valid (1..4), iterasi semua kategori pada minggu
        // tersebut.
        // 4. Hanya jumlahkan elemen yang tidak null.
        // 5. Jika minggu tidak valid, kembalikan 0.
        //

        if (minggu < 1 || minggu > 4) {
            return 0;
        }
        int total = 0;
        int indeks = minggu - 1;

        if (minggu < 1 || minggu > 4) {
            return 0;
        }

        for (int i = 0; i < 3; i++) {
            if (this.matriks[indeks][i] != null) {
                total += this.matriks[indeks][i].getNominal();
            }
        }

        return total;
    }

    public void cetakLaporan() {
        // TODO:
        // 1. Cetak header tabel dengan urutan kolom:
        // ""Minggu\tMakan\t\t\tTransportasi\t\t\tTugas""
        // 2. Untuk setiap minggu (1 sampai 4), cetak nomor minggu di awal baris
        // diikuti dengan
        // "\t".
        // 3. Untuk setiap kategori:
        // - Jika catatan ada, cetak format: "<nominal> (<deskripsi>)\t"
        // - Jika catatan tidak ada, cetak: "Kosong\t\t\t"
        // 4. Gunakan tab/spasi konsisten agar keluaran tetap berbentuk tabel
        // rapi.
        System.out.println("Minggu\tMakan\t\t\tTransportasi\t\t\tTugas");

        for (int i = 0; i < 4; i++) {
            System.out.print((i + 1) + "\t");

            for (int j = 0; j < 3; j++) {
                Catatan catatan = this.matriks[i][j];
                if (catatan != null) {
                    System.out.print(catatan.getNominal() + " (" +
                                     catatan.getDeskripsi() + ")\t");
                } else {
                    System.out.print("Kosong\t\t\t");
                }
            }
            System.out.println();
        }
    }
}
