public class BankAccount {
    private String id;
    private long balance;
    private boolean frozen;

    public BankAccount(String id, long initialBalance) {
        if (initialBalance < 0) {
            throw new InvalidAmountException(initialBalance);
        }
        this.id = id;
        this.balance = initialBalance;
        this.frozen = false;
    }

    public String getId() { return id; }

    public long getBalance() { return balance; }

    public boolean isFrozen() { return frozen; }

    public void deposit(long amount) throws AccountFrozenException {
        if (amount <= 0) {
            throw new InvalidAmountException(amount);
        }
        if (frozen) {
            throw new AccountFrozenException(id);
        }
        balance += amount;
    }

    public void withdraw(long amount)
        throws AccountFrozenException, InsufficientFundsException {
        if (amount <= 0) {
            throw new InvalidAmountException(amount);
        }
        if (frozen) {
            throw new AccountFrozenException(id);
        }
        if (balance < amount) {
            throw new InsufficientFundsException(id, balance, amount);
        }
        balance -= amount;
    }

    public void freeze() { frozen = true; }

    public void unfreeze() { frozen = false; }
}
