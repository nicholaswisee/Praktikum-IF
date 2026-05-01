public class Arsip {
    private Pesan[] pesan;
    private int count;

    public Arsip() {
        pesan = new Pesan[100];
        count = 0;
    }

    public void tambah(Pesan p) {
        if (count < 100) {
            pesan[count] = p;
            count++;
        }
    }

    public Pesan get(int index) { return pesan[index - 1]; }

    public int cari(String keyword) {
        int found = 0;
        String lowerKeyword = keyword.toLowerCase();
        for (int i = 0; i < count; i++) {
            if (pesan[i].content.toLowerCase().contains(lowerKeyword)) {
                found++;
            }
        }
        return found;
    }

    public int jumlah() { return count; }
}
