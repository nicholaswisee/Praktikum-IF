#include "RelicVault.hpp"
#include <cctype>

RelicVault::RelicVault(size_t capacity) : maxCapacity(capacity) {}

bool RelicVault::containsDigit(const std::string &name) const {
    for (size_t i = 0; i < name.size(); i++) {
        if (std::isdigit(static_cast<unsigned char>(name[i])) != 0) {
            return true;
        }
    }
    return false;
}

void RelicVault::push(const std::string &relicName) {
    if (relicName.size() < 3) {
        throw InvalidRelicException(relicName, "nama terlalu pendek");
    }

    if (containsDigit(relicName)) {
        throw InvalidRelicException(relicName, "mengandung angka");
    }

    if (relics.size() >= maxCapacity) {
        throw FullVaultException(maxCapacity);
    }

    relics.push_back(relicName);
}

std::string RelicVault::pop() {
    if (relics.empty()) {
        throw EmptyVaultException();
    }

    std::string lastRelic = relics.back();
    relics.pop_back();
    return lastRelic;
}

std::string RelicVault::top() const {
    if (relics.empty()) {
        throw EmptyVaultException();
    }

    return relics.back();
}

size_t RelicVault::size() const { return relics.size(); }

size_t RelicVault::capacity() const { return maxCapacity; }

bool RelicVault::empty() const { return relics.empty(); }
