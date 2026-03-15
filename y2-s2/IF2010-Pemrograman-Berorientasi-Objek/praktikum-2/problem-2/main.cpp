#include "Cat.hpp"
#include "Dog.hpp"
#include "Parrot.hpp"

// Command format:
// 1 type name age param  -> Create pet (type: 1=Cat, 2=Dog, 3=Parrot)
//                           param: indoor(0/1) for Cat, trained(0/1) for Dog,
//                           vocabulary(int) for Parrot
// 2 name                 -> makeSound()
// 3 name                 -> play()
// 4 name                 -> feed()
// 5 name                 -> showStatus()
// 6 name                 -> delete pet
// 7                      -> showStatus() for all pets

int main() {
    int n;
    cin >> n;

    Pet *pets[100];
    int petCount = 0;

    for (int i = 0; i < n; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int type;
            string name;
            int age;
            cin >> type >> name >> age;

            if (type == 1) {
                int indoor;
                cin >> indoor;
                pets[petCount++] = new Cat(name, age, indoor == 1);
            } else if (type == 2) {
                int trained;
                cin >> trained;
                pets[petCount++] = new Dog(name, age, trained == 1);
            } else if (type == 3) {
                int vocab;
                cin >> vocab;
                pets[petCount++] = new Parrot(name, age, vocab);
            }
        } else {
            string name;
            if (cmd != 7)
                cin >> name;

            int idx = -1;
            if (cmd != 7) {
                for (int j = 0; j < petCount; j++) {
                    if (pets[j] != nullptr && pets[j]->getName() == name) {
                        idx = j;
                        break;
                    }
                }
            }

            if (cmd == 2 && idx != -1) {
                pets[idx]->makeSound();
            } else if (cmd == 3 && idx != -1) {
                pets[idx]->play();
            } else if (cmd == 4 && idx != -1) {
                pets[idx]->feed();
            } else if (cmd == 5 && idx != -1) {
                pets[idx]->showStatus();
            } else if (cmd == 6 && idx != -1) {
                delete pets[idx];
                pets[idx] = nullptr;
            } else if (cmd == 7) {
                for (int j = 0; j < petCount; j++) {
                    if (pets[j] != nullptr) {
                        pets[j]->showStatus();
                    }
                }
            }
        }
    }

    for (int j = 0; j < petCount; j++) {
        if (pets[j] != nullptr) {
            delete pets[j];
            pets[j] = nullptr;
        }
    }

    return 0;
}
