import java.util.ArrayList;
import java.util.List;

public class Laci<T> {
    private String label;
    private List<T> items;
    private static final int CAPACITY = 10;

    public Laci(String label) {
        this.label = label;
        this.items = new ArrayList<>();
    }

    public boolean simpan(T item) {
        if (items.size() < CAPACITY) {
            items.add(item);
            return true;
        }
        return false;
    }

    public T ambil(int i) {
        if (i < 1 || i > items.size()) {
            return null;
        }
        return items.get(i - 1);
    }

    public void set(int i, T item) {
        if (i >= 1 && i <= items.size()) {
            items.set(i - 1, item);
        }
    }

    public int ukuran() { return items.size(); }

    public String getLabel() { return label; }

    @Override
    public String toString() {
        return "Laci[" + label + "]: " + items;
    }
}
