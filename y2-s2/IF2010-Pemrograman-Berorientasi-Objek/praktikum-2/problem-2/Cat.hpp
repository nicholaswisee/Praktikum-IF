#ifndef CAT_HPP
#define CAT_HPP

#include "Pet.hpp"

class Cat : public Pet {
  private:
    bool indoor;

  public:
    Cat(string name, int age, bool indoor);
    ~Cat();

    void makeSound() const override;
    void play() override;
    void feed() override;
};

#endif
