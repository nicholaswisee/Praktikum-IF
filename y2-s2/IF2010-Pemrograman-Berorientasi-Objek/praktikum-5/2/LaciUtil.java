public class LaciUtil {

    public static <T> void tukar(Laci<T> laci, int i, int j) {
        T itemI = laci.ambil(i);
        T itemJ = laci.ambil(j);

        if (itemI != null && itemJ != null) {
            laci.set(i, itemJ);
            laci.set(j, itemI);
        }
    }

    public static <T extends Comparable<T>> T terbesar(Laci<T> laci) {
        if (laci.ukuran() == 0) {
            return null;
        }

        T max = laci.ambil(1);
        for (int i = 2; i <= laci.ukuran(); i++) {
            T current = laci.ambil(i);
            if (current != null && current.compareTo(max) > 0) {
                max = current;
            }
        }
        return max;
    }
}
