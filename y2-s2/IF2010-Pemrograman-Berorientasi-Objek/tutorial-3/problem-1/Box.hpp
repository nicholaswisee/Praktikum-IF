#ifndef BOX_HPP
#define BOX_HPP

#include <iostream>
using namespace std;

template <class T> class Box {
  private:
    T value;

  public:
    // constructor
    Box();
    Box(T value);

    // getter setter
    void setValue(T value);
    T getValue() const;

    // cetak dengan format: "Value: [nilai]"
    void printValue() const;
};

template <class T> T getMax(T a, T b);

// ================= IMPLEMENTATION =================

// Hint:
// - Untuk class template, implementasi tetap ditulis pada file header ini.
// - Contoh bentuk implementasi method di luar class template:
// template <class T>
// ReturnType Box<T>::namaMethod(...) {
//     ...
// }

// TODO: implementasi constructor default
template <class T> Box<T>::Box() { this->value = T(); }
// TODO: implementasi constructor berparameter
template <class T> Box<T>::Box(T value) { this->value = value; }

// TODO: implementasi setValue
template <class T> void Box<T>::setValue(T value) { this->value = value; }

// TODO: implementasi getValue
template <class T> T Box<T>::getValue() const { return this->value; }

// TODO: implementasi printValue
template <class T> void Box<T>::printValue() const {
    cout << "Value: " << value << endl;
}
// Hint:
// Jangan lupa tambahkan endline

// TODO: implementasi function template getMax
// Hint:
// Kembalikan nilai yang lebih besar di antara a dan b.
template <class T> T getMax(T a, T b) { return a > b ? a : b; }

#endif
