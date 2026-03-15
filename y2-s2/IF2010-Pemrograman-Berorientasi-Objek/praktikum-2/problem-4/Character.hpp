#pragma once
#include <iostream>
#include <string>
using namespace std;

class Character {
  private:
    string characterId;

  protected:
    string name;
    int hp;
    int level;

  public:
    Character(string characterId, string name, int hp, int level);
    virtual ~Character();

    string getCharacterId() const;
    string getStatus() const;
    void levelUp();
};
