import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine().trim());
        Arsip arsip = new Arsip();

        for (int i = 0; i < n; i++) {
            String line = sc.nextLine();
            String[] parts = line.split(" ", 3);
            String cmd = parts[0];

            if (cmd.equals("ADD")) {
                String tipe = parts[1];
                String rest = parts[2];
                if (tipe.equals("CAPS")) {
                    arsip.tambah(new CapsMessage(rest));
                } else if (tipe.equals("REPEAT")) {
                    String[] rp = rest.split(" ", 2);
                    int ulang = Integer.parseInt(rp[0]);
                    arsip.tambah(new RepeatMessage(rp[1], ulang));
                } else if (tipe.equals("PANGRAM")) {
                    arsip.tambah(new PangramMessage(rest));
                }

            } else if (cmd.equals("PROCESS")) {
                int idx = Integer.parseInt(parts[1]);
                System.out.println(arsip.get(idx).process());

            } else if (cmd.equals("INFO")) {
                int idx = Integer.parseInt(parts[1]);
                System.out.println(arsip.get(idx));

            } else if (cmd.equals("VOKAL")) {
                int idx = Integer.parseInt(parts[1]);
                Pesan p = arsip.get(idx);
                if (p instanceof CapsMessage) {
                    System.out.println(
                        "Vokal: " + ((CapsMessage)p).countVowels() + ".");
                } else {
                    System.out.println("Pesan bukan tipe CAPS.");
                }

            } else if (cmd.equals("ULANG")) {
                int idx = Integer.parseInt(parts[1]);
                Pesan p = arsip.get(idx);
                if (p instanceof RepeatMessage) {
                    System.out.println(
                        "Pengulang: " + ((RepeatMessage)p).getN() + ".");
                } else {
                    System.out.println("Pesan bukan tipe REPEAT.");
                }

            } else if (cmd.equals("CEK")) {
                int idx = Integer.parseInt(parts[1]);
                Pesan p = arsip.get(idx);
                if (p instanceof PangramMessage) {
                    if (((PangramMessage)p).isPangram()) {
                        System.out.println("Pangram!");
                    } else {
                        System.out.println("Bukan pangram.");
                    }
                } else {
                    System.out.println("Pesan bukan tipe PANGRAM.");
                }

            } else if (cmd.equals("SEARCH")) {
                String keyword = parts[1];
                System.out.println("Ditemukan: " + arsip.cari(keyword) +
                                   " pesan mengandung \"" + keyword + "\".");

            } else if (cmd.equals("COUNT")) {
                System.out.println("Total: " + arsip.jumlah() + " pesan.");
            }
        }

        sc.close();
    }
}
