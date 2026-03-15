#ifndef PARROT_HPP
#define PARROT_HPP

#include "Pet.hpp"

class Parrot : public Pet {
  private:
    int vocabulary;

  public:
    Parrot(string name, int age, int vocabulary);
    ~Parrot();

    void makeSound() const override;
    void play() override;
    void feed() override;
};

#endif
