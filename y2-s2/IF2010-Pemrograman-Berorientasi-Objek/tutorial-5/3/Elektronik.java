public class Elektronik extends Barang {
    private int watt;

    public Elektronik(String nama, int harga, int watt) {
        super(nama, harga);
        this.watt = watt;
    }

    public int getWatt() { return watt; }

    @Override
    public String info() {
        return "[Elektronik] " + nama + " - " + harga + " IDR (" + watt + "W)";
    }
}
