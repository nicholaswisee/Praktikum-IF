import java.util.Optional;

public class Bishop extends Bidak {
    public Bishop(int x, int y, int id) {
        super(x, y, 'B', id);
        actions.add("2. Atas Kanan");
        actions.add("4. Atas Kiri");
        actions.add("6. Bawah Kanan");
        actions.add("8. Bawah Kiri");
    };

    public Bishop(Bishop b) {
        super(b.getX(), b.getY(), 'B', b.getId());
        actions.add("2. Atas Kanan");
        actions.add("4. Atas Kiri");
        actions.add("6. Bawah Kanan");
        actions.add("8. Bawah Kiri");
    }

    public void atasKanan(Optional<Integer> steps) {
        this.x += steps.orElse(1);
        this.y -= steps.orElse(1);
    }

    public void atasKiri(Optional<Integer> steps) {
        this.x -= steps.orElse(1);
        this.y -= steps.orElse(1);
    }

    public void bawahKanan(Optional<Integer> steps) {
        this.x += steps.orElse(1);
        this.y += steps.orElse(1);
    }

    public void bawahKiri(Optional<Integer> steps) {
        this.x -= steps.orElse(1);
        this.y += steps.orElse(1);
    }
}
