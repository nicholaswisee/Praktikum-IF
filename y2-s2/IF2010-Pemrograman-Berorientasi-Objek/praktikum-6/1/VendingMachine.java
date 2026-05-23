public class VendingMachine {
    private int stock;
    private int balance;
    private int price;

    public VendingMachine(int stock, int price) {
        // TODO:
        // Validasi nilai awal mesin.
        //
        // Stock awal tidak boleh bernilai negatif.
        // Jika tidak valid, hentikan pembuatan objek dengan pesan:
        // "stock tidak boleh negatif".
        //
        // Price harus bernilai positif.
        // Jika tidak valid, hentikan pembuatan objek dengan pesan:
        // "price harus bernilai positif".
        //
        // Jika semua nilai valid, simpan stock dan price ke atribut.
        // Balance awal adalah 0.
        //
        // Setelah state disimpan, pastikan invariant mesin tetap terpenuhi.

        if (stock < 0) {
            throw new IllegalArgumentException("stock tidak boleh negatif");
        }

        if (price <= 0) {
            throw new IllegalArgumentException("price harus bernilai positif");
        }

        this.stock = stock;
        this.price = price;
        this.balance = 0;
    }

    public void insertMoney(int amount) {
        // TODO:
        // Validasi jumlah uang yang dimasukkan.
        //
        // Amount harus bernilai positif.
        // Jika tidak valid, hentikan operasi dengan pesan:
        // "amount harus bernilai positif".
    
        if (amount <= 0) {
            throw new IllegalArgumentException("amount harus bernilai positif");
        }
        // Jika valid, tambahkan amount ke balance.
        
        balance += amount;

        checkInvariant();
        // Setelah state berubah, pastikan invariant mesin tetap terpenuhi.
    }

    public String buy() {

        // TODO:
        // Proses pembelian item dari vending machine.
        //
        // Pembelian tidak dapat dilakukan jika stock sudah kosong.
        // Jika kondisi ini terjadi, hentikan operasi dengan pesan:
        // "stock kosong".

        if (stock <= 0) {
            throw new IllegalStateException("stock kosong");

        }

        // Pembelian juga tidak dapat dilakukan jika balance kurang dari price.
        // Jika kondisi ini terjadi, hentikan operasi dengan pesan:
        // "balance tidak cukup".

        if (balance < price) {
            throw new IllegalStateException("balance tidak cukup");
        }

        // Jika pembelian valid, kurangi stock sebanyak 1
        // dan kurangi balance sebesar price.
        //

        stock -= 1;
        balance -= price;

        // Setelah state berubah, pastikan invariant mesin tetap terpenuhi.
        
        checkInvariant();
        // Kembalikan string:
        // "Item berhasil terbeli".

        return "Item berhasil terbeli";
    }

    public int refund() {
        // TODO:
        // Kembalikan seluruh balance yang tersimpan di mesin.
        //
        // Simpan nilai balance saat ini ke variabel sementara.
        // Setelah itu, ubah balance menjadi 0.
        //
        // Setelah state berubah, pastikan invariant mesin tetap terpenuhi.
        //
        // Kembalikan nilai uang yang dikembalikan.

        int temp = balance;
        balance = 0;

        checkInvariant();
        return temp;
    }

    public String status() {
        // TODO:
        // Kembalikan informasi state mesin dengan format:
        // "Stock: stock, Balance: balance, Price: price"
        //
        // Contoh:
        // "Stock: 2, Balance: 5000, Price: 3000"

        return "Stock: " + stock + ", Balance: " + balance + ", Price: " + price;
    }

    private void checkInvariant() {
        // TODO:
        // Pastikan invariant internal mesin selalu terpenuhi:
        //
        // stock tidak boleh negatif
        // balance tidak boleh negatif
        // price harus bernilai positif
        //
        // Gunakan pesan berikut jika invariant gagal:
        // "Invalid stock state"
        // "Invalid balance state"
        // "Invalid price state"

        assert stock >= 0 : "Invalid stock state";

        assert balance >= 0 : "Invalid balance state";

        assert price > 0 : "Invalid price state";
    }
}