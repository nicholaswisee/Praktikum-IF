#ifndef WORKER_HPP
#define WORKER_HPP

#include "Creature.hpp"
#include <string>

class Worker : public Creature {
protected:
  int workHours;
  std::string specialSkill;

public:
  Worker();
  Worker(const std::string &name, int power, const std::string &dimension,
         int workHours, const std::string &specialSkill);
  virtual ~Worker();

  int getWorkHours() const;
  const std::string &getSpecialSkill() const;
};

#endif
