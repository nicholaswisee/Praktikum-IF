public abstract class Barang {
    protected String nama;
    protected int harga;

    public Barang(String nama, int harga) {
        this.nama = nama;
        this.harga = harga;
    }

    public String getNama() { return nama; }

    public int getHarga() { return harga; }

    public abstract String info();
}
