#ifndef DOG_HPP
#define DOG_HPP

#include "Pet.hpp"

class Dog : public Pet {
  private:
    bool trained;

  public:
    Dog(string name, int age, bool trained);
    ~Dog();

    void makeSound() const override;
    void play() override;
};

#endif
