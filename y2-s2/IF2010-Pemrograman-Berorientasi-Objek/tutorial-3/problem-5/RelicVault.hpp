#ifndef RELIC_VAULT_HPP
#define RELIC_VAULT_HPP

#include "VaultException.hpp"
#include <string>
#include <vector>

class RelicVault {
  private:
    std::vector<std::string> relics;
    size_t maxCapacity;

    bool containsDigit(const std::string &name) const;

  public:
    explicit RelicVault(size_t capacity);

    void push(const std::string &relicName);
    std::string pop();
    std::string top() const;

    size_t size() const;
    size_t capacity() const;
    bool empty() const;
};

#endif
