import java.util.ArrayList;

public class Kotak<T extends Barang> {
    private ArrayList<T> items;
    private int kapasitas;

    public Kotak(int kapasitas) {
        this.kapasitas = kapasitas;
        this.items = new ArrayList<>();
    }

    public boolean tambah(T item) {
        if (items.size() < kapasitas) {
            items.add(item);
            return true;
        }
        return false;
    }

    public T ambil() {
        if (items.isEmpty()) {
            return null;
        }
        return items.remove(items.size() - 1);
    }

    public T lihat(int index) {
        if (index < 0 || index >= items.size()) {
            return null;
        }
        return items.get(index);
    }

    public int jumlah() { return items.size(); }

    public int kapasitas() { return kapasitas; }

    public boolean penuh() { return items.size() >= kapasitas; }

    public boolean kosong() { return items.isEmpty(); }
}
