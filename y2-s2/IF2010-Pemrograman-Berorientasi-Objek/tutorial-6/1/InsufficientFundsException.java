public class InsufficientFundsException extends Exception {
    public InsufficientFundsException(String accountId, long balance,
                                      long amount) {
        super("Saldo tidak cukup di akun " + accountId + " (saldo: " + balance +
              ", diperlukan: " + amount + ")");
    }
}
