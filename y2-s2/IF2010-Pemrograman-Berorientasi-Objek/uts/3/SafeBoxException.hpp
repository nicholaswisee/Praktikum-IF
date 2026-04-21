#ifndef SAFE_BOX_EXCEPTION_HPP
#define SAFE_BOX_EXCEPTION_HPP

#include <exception>
#include <sstream>
#include <string>
using namespace std;

// Base class untuk semua exception SafeBox.
// Turunan dari std::exception override what() di setiap subclass.
class SafeBoxException : public exception {
  public:
    virtual const char *what() const noexcept = 0;
    virtual ~SafeBoxException() noexcept {}
};

class BoxFullException : public SafeBoxException {
  private:
    int maxCapacity;
    string message;

  public:
    explicit BoxFullException(int capacity) : maxCapacity(capacity) {
        ostringstream oss;
        oss << "Box penuh: kapasitas maks " << maxCapacity;
        message = oss.str();
    }

    const char *what() const noexcept { return message.c_str(); }
};

class BoxEmptyException : public SafeBoxException {
  public:
    const char *what() const noexcept { return "Box kosong"; }
};

// Template: item yang tidak valid dapat bertipe apa saja (int, string, dll.)
// Gunakan ostringstream untuk mengonversi T ke string di dalam what().
// Contoh penggunaan ostringstream:
// int x = 42;
// ostringstream oss;
// oss << "Nilai x: " << x;
// string msg = oss.str(); // msg = "Nilai x: 42"
template <typename T> class InvalidItemException : public SafeBoxException {
  private:
    T invalidItem;
    string message;

  public:
    explicit InvalidItemException(const T &item) : invalidItem(item) {
        ostringstream oss;
        oss << "Item tidak valid: " << invalidItem;
        message = oss.str();
    }

    const char *what() const noexcept { return message.c_str(); }
};

#endif
