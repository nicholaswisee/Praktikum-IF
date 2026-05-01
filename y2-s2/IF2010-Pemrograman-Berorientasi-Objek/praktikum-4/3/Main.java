public class Main {
    public static void main(String[] args) {
        TrackerPengeluaran catatanKebin = new TrackerPengeluaran();

        catatanKebin.setCatatan(1, 0, 50000, "Pisang Goreng");
        catatanKebin.setCatatan(1, 1, 15000, "Ojek Online");

        // Minggu 2, Makan (Kolom 0) kosong
        catatanKebin.setCatatan(2, 2, 30000, "Print Laporan OOP");

        catatanKebin.cetakLaporan();

        System.out.println("\nTotal Pengeluaran Minggu 1: Rp " +
                           catatanKebin.totalPerMinggu(1));
        System.out.println("Total Pengeluaran Minggu 2: Rp " +
                           catatanKebin.totalPerMinggu(2));
    }
}
