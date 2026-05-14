import java.util.LinkedHashMap;

public class Bank {
    private LinkedHashMap<String, BankAccount> accounts;

    public Bank() { this.accounts = new LinkedHashMap<>(); }

    public void addAccount(String id, long initialBalance) {
        BankAccount account = new BankAccount(id, initialBalance);
        accounts.put(id, account);
    }

    public BankAccount getAccount(String id) throws AccountNotFoundException {
        BankAccount account = accounts.get(id);
        if (account == null) {
            throw new AccountNotFoundException(id);
        }
        return account;
    }

    public void deposit(String id, long amount)
        throws AccountNotFoundException, AccountFrozenException {
        BankAccount account = getAccount(id);
        account.deposit(amount);
    }

    public void withdraw(String id, long amount)
        throws AccountNotFoundException, AccountFrozenException,
               InsufficientFundsException {
        BankAccount account = getAccount(id);
        account.withdraw(amount);
    }

    public void freeze(String id) throws AccountNotFoundException {
        BankAccount account = getAccount(id);
        account.freeze();
    }

    public void unfreeze(String id) throws AccountNotFoundException {
        BankAccount account = getAccount(id);
        account.unfreeze();
    }

    public void transfer(String fromId, String toId, long amount)
        throws AccountNotFoundException, AccountFrozenException,
               InsufficientFundsException {
        withdraw(fromId, amount);
        deposit(toId, amount);
    }
}
