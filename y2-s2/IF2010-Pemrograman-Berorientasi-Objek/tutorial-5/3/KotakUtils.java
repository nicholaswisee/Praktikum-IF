public class KotakUtils {

    public static void tampilkanSemua(Kotak<? extends Barang> kotak) {
        if (kotak.kosong()) {
            System.out.println("Kotak kosong");
            return;
        }
        for (int i = 0; i < kotak.jumlah(); i++) {
            System.out.println(kotak.lihat(i).info());
        }
    }

    public static int totalHarga(Kotak<? extends Barang> kotak) {
        int total = 0;
        for (int i = 0; i < kotak.jumlah(); i++) {
            total += kotak.lihat(i).getHarga();
        }
        return total;
    }

    public static Barang termahal(Kotak<? extends Barang> kotak) {
        if (kotak.kosong()) {
            return null;
        }
        Barang max = null;
        for (int i = 0; i < kotak.jumlah(); i++) {
            Barang item = kotak.lihat(i);
            if (max == null || item.getHarga() > max.getHarga()) {
                max = item;
            }
        }
        return max;
    }

    public static <T extends Barang> int pindahkan(Kotak<? extends T> src,
                                                   Kotak<? super T> dst) {
        int count = 0;
        while (!src.kosong() && !dst.penuh()) {
            T item = src.ambil();
            dst.tambah(item);
            count++;
        }
        return count;
    }

    public static int hitungItem(Kotak<?> kotak) { return kotak.jumlah(); }
}
