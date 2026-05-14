public class AccountFrozenException extends Exception {
    public AccountFrozenException(String accountId) {
        super("Akun dibekukan: " + accountId);
    }
}
