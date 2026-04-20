import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        Courier[] couriers = new Courier[n];
        String[] items = new String[n];

        int totalSpeed = 0;
        boolean fast = false;

        for (int i = 0; i < n; i++) {
            String type = sc.next();
            String name = sc.next();
            int speed = sc.nextInt();
            String item = sc.next();

            if (type.equals("B")) {
                couriers[i] = new BikeCourier(name, speed);
            } else {
                couriers[i] = new CarCourier(name, speed);
            }

            items[i] = item;
            totalSpeed += couriers[i].getSpeed();
            if (couriers[i].getSpeed() > 40) {
                fast = true;
            }
        }

        for (int i = 0; i < n; i++) {
            System.out.println(couriers[i]);
            System.out.println(couriers[i].deliver(items[i]));
        }

        double averageSpeed = (n == 0) ? 0.0 : (double)totalSpeed / n;
        System.out.printf("Average speed: %.2f%n", averageSpeed);
        System.out.println("Fast? " + fast);

        sc.close();
    }
}
