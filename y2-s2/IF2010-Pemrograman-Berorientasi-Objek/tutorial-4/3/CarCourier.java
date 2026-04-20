public class CarCourier extends Courier {
    public CarCourier(String name, int speed) { super(name, speed); }

    @Override
    public String toString() {
        return "[Car] " + super.toString();
    }
}
