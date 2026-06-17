import java.util.List;
import java.util.Locale;

// Kelas yang mengimplementasikan Runnable dan memproses sebagian dari daftar
// batch secara paralel.
public class BatchProcessor implements Runnable {
    private final List<? extends DataBatch<? extends Number>> batches;
    private final int threadIndex;
    private final String[] logs;
    private final int[] totalItems;
    private final Object lock;

    // Simpan semua parameter ke atribut.
    public BatchProcessor(List<? extends DataBatch<? extends Number>> batches,
                          int threadIndex, String[] logs, int[] totalItems,
                          Object lock) {
        this.batches = batches;
        this.threadIndex = threadIndex;
        this.logs = logs;
        this.totalItems = totalItems;
        this.lock = lock;
    }

    @Override
    public void run() {
        // 1. Tandai thread ini agar ThreadTracker dapat memverifikasi.
        ThreadTracker.mark();

        // 2. Bangun string log untuk thread ini.
        StringBuilder sb = new StringBuilder();
        sb.append("Thread ").append(threadIndex).append(":");

        int localCount = 0;
        for (DataBatch<? extends Number> batch : batches) {
            sb.append("\n")
                .append("Batch ")
                .append(batch.getLabel())
                .append(": sum = ")
                .append(String.format(Locale.US, "%.1f", batch.sum()));
            localCount += batch.getItems().size();
        }

        logs[threadIndex] = sb.toString() + "\n";

        // 3. Update totalItems[0] secara thread-safe.
        synchronized (lock) { totalItems[0] += localCount; }
    }
}
