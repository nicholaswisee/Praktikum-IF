#include "TodoItem.hpp"
#include "Activity.hpp"
#include <iostream>

using namespace std;

TodoItem::TodoItem(const string &name) : Activity{name}, isDone{false} {}

int TodoItem::complete() {
    if (!isDone) {
        isDone = true;
        return 10;
    }

    return 0;
}

string TodoItem::getStatus() const {
    if (isDone) {
        return "[TODO] " + name + " - Selesai";
    } else {
        return "[TODO] " + name + " - Belum";
    }
}

TodoItem::~TodoItem() { cout << "Menghapus TodoItem " << name << endl; }
