import java.util.Optional;

public interface Aksi {

    public default void atas(Optional<Integer> steps) {
        System.out.print("[X] Gerakan tidak valid untuk bidak ini!\n");
    }

    public default void atasKanan(Optional<Integer> steps) {
        System.out.print("[X] Gerakan tidak valid untuk bidak ini!\n");
    }

    public default void atasKiri(Optional<Integer> steps) {
        System.out.print("[X] Gerakan tidak valid untuk bidak ini!\n");
    }

    public default void kanan(Optional<Integer> steps) {
        System.out.print("[X] Gerakan tidak valid untuk bidak ini!\n");
    }

    public default void kiri(Optional<Integer> steps) {
        System.out.print("[X] Gerakan tidak valid untuk bidak ini!\n");
    }

    public default void bawahKanan(Optional<Integer> steps) {
        System.out.print("[X] Gerakan tidak valid untuk bidak ini!\n");
    }

    public default void bawahKiri(Optional<Integer> steps) {
        System.out.print("[X] Gerakan tidak valid untuk bidak ini!\n");
    }

    public default void bawah(Optional<Integer> steps) {
        System.out.print("[X] Gerakan tidak valid untuk bidak ini!\n");
    }
}
