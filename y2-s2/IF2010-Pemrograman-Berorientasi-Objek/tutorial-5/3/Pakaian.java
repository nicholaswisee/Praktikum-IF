public class Pakaian extends Barang {
    private String ukuran;

    public Pakaian(String nama, int harga, String ukuran) {
        super(nama, harga);
        this.ukuran = ukuran;
    }

    public String getUkuran() { return ukuran; }

    @Override
    public String info() {
        return "[Pakaian] " + nama + " - " + harga + " IDR (" + ukuran + ")";
    }
}
