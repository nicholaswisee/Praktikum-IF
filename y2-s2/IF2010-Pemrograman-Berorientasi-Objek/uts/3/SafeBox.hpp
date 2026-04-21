#ifndef SAFE_BOX_HPP
#define SAFE_BOX_HPP

#include "SafeBoxException.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
// include header lain jika diperlukan (stack, vector, algorithm, etc.)

using namespace std;

// Template class SafeBox<T>:
// Menyimpan elemen bertipe T secara LIFO dengan kapasitas terbatas.
// Implementasi internal dibebaskan, dapat menggunakan stack, vector, atau
// struktur data lain sesuai kebutuhan.
template <typename T> class SafeBox {
  private:
    int maxCap;
    function<bool(const T &)> validator;
    vector<T> items;

  public:
    // Inisialisasi box dengan kapasitas maksimum dan validator opsional.
    // Jika validator diberikan, store() akan melempar InvalidItemException
    // untuk item yang tidak lolos validasi.
    SafeBox(int capacity, function<bool(const T &)> validator = nullptr)
        : maxCap(capacity), validator(validator) {}

    // Menyimpan item ke dalam box.
    // Lakukan hal berikut secara berurutan:
    // 1. Lempar InvalidItemException jika validator ada dan item tidak valid.
    // 2. Lempar BoxFullException(cap) jika items.size() >= cap.
    // 3. Tambahkan item ke box jika valid
    // Hint: Gunakan validator(item) untuk validasi, dan periksa apakah
    // validator tidak nullptr sebelum dipanggil.
    void store(const T &item) {
        if (validator && !validator(item)) {
            throw InvalidItemException<T>(item);
        }

        if ((int)items.size() >= maxCap) {
            throw BoxFullException(maxCap);
        }

        items.push_back(item);
    }

    // Mengambil dan menghapus item teratas (LIFO).
    // Lempar BoxEmptyException jika kosong.
    T retrieve() {
        if (items.empty()) {
            throw BoxEmptyException();
        }

        T top = items.back();
        items.pop_back();
        return top;
    }

    // Melihat item teratas tanpa menghapusnya.
    // Lempar BoxEmptyException jika kosong.
    T peek() const {
        if (items.empty()) {
            throw BoxEmptyException();
        }

        return items.back();
    }

    // Membalik urutan semua elemen dalam box.
    // Lempar BoxEmptyException jika box kosong saat dipanggil.
    void reverse() {
        if (items.empty()) {
            throw BoxEmptyException();
        }

        std::reverse(items.begin(), items.end());
    }

    // Mengembalikan jumlah item saat ini.
    int size() const { return (int)items.size(); }

    // Mengembalikan kapasitas maksimum box.
    int capacity() const { return maxCap; }

    // Mengembalikan true jika box kosong.
    bool isEmpty() const { return items.empty(); }

    // Mencetak isi box dari bawah ke atas: [item_bawah, ..., item_atas]
    // Jika kosong, cetak [].
    friend ostream &operator<<(ostream &os, const SafeBox<T> &box) {
        os << "[";
        for (size_t i = 0; i < box.items.size(); ++i) {
            if (i > 0) {
                os << ", ";
            }
            os << box.items[i];
        }
        os << "]";
        return os;
    }
};

// Template function safeMerge:
// Memindahkan item dari src ke dst satu per satu (urutan LIFO).
// Hentikan jika dst penuh (tangkap BoxFullException secara internal).
// Kembalikan jumlah item yang berhasil dipindahkan.
template <typename T> int safeMerge(SafeBox<T> &src, SafeBox<T> &dst) {
    int moved = 0;

    while (!src.isEmpty()) {
        T item = src.peek();

        try {
            dst.store(item);
            src.retrieve();
            ++moved;
        } catch (const BoxFullException &) {
            break;
        }
    }

    return moved;
}

#endif
