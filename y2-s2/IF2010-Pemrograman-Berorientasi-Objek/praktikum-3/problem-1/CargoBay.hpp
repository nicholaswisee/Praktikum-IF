#ifndef CARGO_BAY_HPP
#define CARGO_BAY_HPP

#include "CargoException.hpp"
#include "Item.hpp"

template <class T> class CargoBay {
  private:
    Item<T> *arr;
    int capacity;
    int size;

  public:
    // TODO Constructor & Destructor
    // Constructor: inisialisasi capacity, size = 0, alokasi array arr.
    // Destructor: Dealokasi array arr.
    CargoBay(int cap);
    ~CargoBay();

    // TODO Push & Pop (Standard)
    // push: Lempar CargoFullException jika size >= capacity. Taruh item ke
    // index terakhir array pop: Lempar CargoEmptyException jika size <= 0.
    // Return item terakhir (LIFO) dan update size.
    void push(Item<T> item);
    Item<T> pop();

    // TODO extractItem
    // Cari item PERTAMA (dimulai dari index 0 hingga size-1)
    // yang nilai `data`-nya SAMA DENGAN `targetData`.
    // Jika ketemu:
    //     - Return Item tersebut.
    //     - Hapus Item tersebut dari array,
    //       lalu geser seluruh Item di kanannya ke kiri agar array tidak
    //       bolong.
    //     - Update size.
    // Jika tidak ketemu, lempar ItemNotFoundException.
    Item<T> extractItem(T targetData);

    // TODO forge
    // Menempa (Menggabungkan) dua Item teratas menjadi satu Item baru.
    // Cek apakah size < 2. Jika ya, lempar NotEnoughItemsException.
    // Jika aman, keluarkan (pop) item pertama dan item kedua.
    // Buatlah data baru hasil penjumlahan berurutan: `baseData` + data Top 1 +
    // data Top 2.
    //   (Contoh: Jika baseData = "X", Top 1 = "Y", Top 2 = "Z", maka data baru
    //   = "XYZ").
    // Dipastikan tipe data T support operator+
    // Buatlah durability baru: rata-rata dari durability item pertama dan kedua
    // (integer division). Buat objek Item baru dengan data & durability baru
    // tersebut, lalu push() ke CargoBay.
    void forge(T baseData);

    // TODO transferTo
    // Pindahkan sejumlah `count` item dari atas cargo `this` ke cargo `other`.
    // PROSES TRANSFER dilakukan satu per satu (LIFO).
    // Perhatikan bahwa urutan item akan terbalik.
    // Jika, size < count, lempar NotEnoughItemsException
    // PENANGANAN EXCEPTION:
    //    - Jika other ternyata penuh di tengah jalan (melempar
    //    CargoFullException),
    //      TANGKAP error tersebut dengan try-catch!
    //    - Kembalikan 1 item yang gagal masuk itu ke cargo `this`.
    //    - Lempar TransferFailedException ke luar fungsi untuk memberitahu
    //    bahwa transfer terhenti.
    void transferTo(CargoBay<T> &other, int count);
};

// Implementasi di sini (atau langsung di deklarasi methods juga bisa sih)

template <class T> CargoBay<T>::CargoBay(int cap) {
    this->capacity = cap;
    this->size = 0;
    this->arr = new Item<T>[cap];
}

template <class T> CargoBay<T>::~CargoBay() { delete[] this->arr; }

template <class T> void CargoBay<T>::push(Item<T> item) {
    if (this->size >= this->capacity) {
        throw CargoFullException();
    }

    item.assignId();
    this->arr[this->size] = item;
    this->size++;
}

template <class T> Item<T> CargoBay<T>::pop() {
    if (this->size <= 0) {
        throw CargoEmptyException();
    }

    Item<T> item = this->arr[this->size - 1];
    this->size--;
    return item;
}

template <class T> Item<T> CargoBay<T>::extractItem(T targetData) {
    int idx = -1;
    for (int i = 0; i < this->size; i++) {
        if (this->arr[i].getData() == targetData) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        throw ItemNotFoundException();
    }

    Item<T> extracted = this->arr[idx];
    for (int i = idx; i < this->size - 1; i++) {
        this->arr[i] = this->arr[i + 1];
    }
    this->size--;

    return extracted;
}

template <class T> void CargoBay<T>::forge(T baseData) {
    if (this->size < 2) {
        throw NotEnoughItemsException();
    }

    Item<T> top1 = this->pop();
    Item<T> top2 = this->pop();
    T forgedData = baseData + top1.getData() + top2.getData();
    int forgedDurability = (top1.getDurability() + top2.getDurability()) / 2;

    this->push(Item<T>(forgedData, forgedDurability));
}

template <class T> void CargoBay<T>::transferTo(CargoBay<T> &other, int count) {
    if (this->size < count) {
        throw NotEnoughItemsException();
    }

    for (int i = 0; i < count; i++) {
        Item<T> item = this->pop();

        try {
            other.push(item);
        } catch (const CargoFullException &) {
            this->push(item);
            throw TransferFailedException();
        }
    }
}

#endif
