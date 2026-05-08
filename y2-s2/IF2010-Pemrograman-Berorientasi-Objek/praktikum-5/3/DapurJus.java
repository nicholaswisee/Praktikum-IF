import java.util.List;

public class DapurJus {

    private DapurJus(){};

    public static void cekBahan(List<? extends Buah> daftarBahan) {
        for (int i = 0; i < daftarBahan.size(); i++) {
            System.out.println(daftarBahan.get(i).deskripsi());
        }
    }

    public static int hitungTotalManis(List<? extends Buah> daftarBahan) {
        int total = 0;
        for (int i = 0; i < daftarBahan.size(); i++) {
            total += daftarBahan.get(i).getTingkatManis();
        }

        return total;
    }

    public static void buatJusApelDefault(List<? super JusApel> daftarMinuman) {
        daftarMinuman.add(new JusApel("Jus Apel Original"));
        daftarMinuman.add(new JusApel("Jus Apel Madu"));
    }

    public static <T> void cetakRakUmum(List<T> rak) {
        for (int i = 0; i < rak.size(); i++) {
            System.out.println(rak.get(i).toString());
        }
    }
}
