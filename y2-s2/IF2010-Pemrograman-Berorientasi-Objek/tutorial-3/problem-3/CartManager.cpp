#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct GameEntry {
    string title;
    float price;

    GameEntry(string t, float p) {
        title = t;
        price = p;
    }
};

class CartManager {
  private:
    // TODO: Deklarasikan vector yang dibutuhkan
    vector<GameEntry> cart;
    vector<GameEntry> purchased;

  public:
    void addToCart(string title, float price) {
        // TODO: Menambahkan game ke akhir keranjang. Judul yang sama boleh
        // muncul lebih dari sekali.
        cart.push_back(GameEntry(title, price));
    }

    bool removeFromCart(string title) {
        // TODO: Menghapus kemunculan pertama game dengan judul tersebut.
        // Kembalikan true jika berhasil, false jika tidak ditemukan. Urutan
        // harus tetap terjaga.
        for (size_t i = 0; i < cart.size(); i++) {
            if (cart[i].title == title) {
                cart.erase(cart.begin() + i);
                return true;
            }
        }

        return false;
    }

    void checkout() {
        // TODO: Memindahkan semua game dari keranjang ke library, lalu
        // mengosongkan keranjang. Jika keranjang kosong, tidak melakukan
        // apa-apa.
        while (cart.size() > 0) {
            purchased.push_back(cart[0]);
            cart.erase(cart.begin());
        }
    }

    float cartTotal() {
        // TODO: Mengembalikan total harga semua item di keranjang.
        float sum = 0;
        for (const GameEntry &game : cart) {
            sum += game.price;
        }
        return sum;
    }

    float applyDiscount(float percent) {
        // TODO: Menerapkan diskon (misalnya 10.0 = 10%) ke semua item dalam
        // keranjang secara langsung (price game dalam keranjang berubah).
        // Mengembalikan total baru. Jika keranjang kosong, kembalikan 0.0.
        if (cart.size() == 0)
            return 0.0;
        for (GameEntry &game : cart) {
            game.price = game.price - (game.price * (percent / 100));
        }

        return cartTotal();
    }

    int countInCart(string title) {
        // TODO: Menghitung berapa kali game dengan judul tersebut muncul di
        // keranjang.
        int count = 0;
        for (const GameEntry &game : cart) {
            if (game.title == title)
                count++;
        }
        return count;
    }

    void printCart() {
        // TODO: sesuaikan nama variablenya
        if (cart.size() == 0) {
            cout << "Cart is empty." << endl;
            return;
        }
        for (size_t i = 0; i < cart.size(); i++) {
            cout << "[" << i << "] " << cart[i].title << " - $" << cart[i].price
                 << endl;
        }
    }

    void printPurchased() {
        // TODO: sesuaikan nama variablenya
        if (purchased.size() == 0) {
            cout << "No purchases yet." << endl;
            return;
        }
        for (size_t i = 0; i < purchased.size(); i++) {
            cout << "[" << i << "] " << purchased[i].title << " - $"
                 << purchased[i].price << endl;
        }
    }

    int totalPurchased() {
        // TODO: Mengembalikan jumlah total game yang ada di library.
        return purchased.size();
    }
};

int main() {
    CartManager cm;
    int q;

    if (!(cin >> q))
        return 0;

    cout << fixed << setprecision(2);

    for (int i = 0; i < q; i++) {
        string op;
        cin >> op;

        if (op == "ADD") {
            string title;
            float price;
            cin >> title >> price;
            cm.addToCart(title, price);
        } else if (op == "REMOVE") {
            string title;
            cin >> title;
            if (cm.removeFromCart(title))
                cout << "Removed: " << title << "\n";
            else
                cout << "Not found: " << title << "\n";
        } else if (op == "CHECKOUT") {
            cm.checkout();
        } else if (op == "TOTAL") {
            cout << "Cart total: $" << cm.cartTotal() << "\n";
        } else if (op == "DISCOUNT") {
            float pct;
            cin >> pct;
            cout << "After discount: $" << cm.applyDiscount(pct) << "\n";
        } else if (op == "COUNT") {
            string title;
            cin >> title;
            cout << title << ": " << cm.countInCart(title) << " in cart\n";
        } else if (op == "PRINT_CART") {
            cm.printCart();
        } else if (op == "PRINT_PURCHASED") {
            cm.printPurchased();
        } else if (op == "PURCHASED_COUNT") {
            cout << "Total purchased: " << cm.totalPurchased() << "\n";
        }
    }

    return 0;
}
