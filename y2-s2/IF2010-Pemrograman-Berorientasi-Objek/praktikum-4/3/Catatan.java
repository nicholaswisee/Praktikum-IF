public class Catatan {
    private int nominal;
    private String deskripsi;

    public Catatan(int nominal, String deskripsi) {
        this.nominal = nominal;
        this.deskripsi = deskripsi;
    }

    public int getNominal() { return nominal; }

    public String getDeskripsi() { return deskripsi; }
}
