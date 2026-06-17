import java.util.List;

// Kelas utilitas dengan dua method statis untuk agregasi data.
// Method-method ini harus dapat menerima list batch dengan tipe numerik apapun
// (integer maupun desimal) tanpa duplikasi kode.
public class DataUtils {

    // Menjumlahkan hasil sum() dari semua batch. Kembalikan hasilnya sebagai
    // double.
    public static double totalSum(List<? extends DataBatch<? extends Number>> batches) {
        double total = 0.0;
        for (DataBatch<? extends Number> batch : batches) {
            total += batch.sum();
        }
        return total;
    }

    // Mencari nilai item terbesar dari seluruh batch sebagai double.
    // Iterasi semua batch dan semua item, gunakan .doubleValue().
    // Mulai dari Double.NEGATIVE_INFINITY.
    public static double findMax(List<? extends DataBatch<? extends Number>> batches) {
        double max = Double.NEGATIVE_INFINITY;
        for (DataBatch<? extends Number> batch : batches) {
            for (Number n : batch.getItems()) {
                double v = n.doubleValue();
                if (v > max) {
                    max = v;
                }
            }
        }
        return max;
    }
}
