public class InvalidAmountException extends RuntimeException {
    public InvalidAmountException(long amount) {
        super("Jumlah tidak valid: " + amount);
    }
}
