#ifndef PET_HPP
#define PET_HPP

#include <iostream>
#include <string>

using namespace std;

class Pet {
  protected:
    string name;
    int age;
    int happiness;

  public:
    Pet(string name, int age);
    virtual ~Pet();

    virtual void makeSound() const = 0;
    virtual void play();
    virtual void feed();

    void showStatus() const;
    string getName() const;
    int getHappiness() const;
};

#endif
