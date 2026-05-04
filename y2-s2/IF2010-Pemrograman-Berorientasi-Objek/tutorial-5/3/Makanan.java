public class Makanan extends Barang {
    private int kalori;

    public Makanan(String nama, int harga, int kalori) {
        super(nama, harga);
        this.kalori = kalori;
    }

    public int getKalori() { return kalori; }

    @Override
    public String info() {
        return "[Makanan] " + nama + " - " + harga + " IDR (" + kalori +
            " kal)";
    }
}
