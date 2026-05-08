public class Checkout {
    private PaymentStrategy paymentStrategy;


    public void setPaymentStrategy(PaymentStrategy paymentStrategy) {
        this.paymentStrategy = paymentStrategy;
    }

    public void processPayment(int amount) {
        if (this.paymentStrategy == null) {
            System.out.println("No payment method selected");
            return;
        }
        this.paymentStrategy.pay(amount);
    }
}