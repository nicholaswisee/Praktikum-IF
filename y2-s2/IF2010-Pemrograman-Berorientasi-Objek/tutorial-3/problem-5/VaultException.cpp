#include "VaultException.hpp"

VaultException::VaultException(const std::string &message) : message(message) {}

const char *VaultException::what() const noexcept { return message.c_str(); }

EmptyVaultException::EmptyVaultException()
    : VaultException("Error: Vault kosong") {}

FullVaultException::FullVaultException(size_t capacity)
    : VaultException("Error: Vault sudah penuh"), maxCapacity(capacity) {}

size_t FullVaultException::getCapacity() const { return maxCapacity; }

InvalidRelicException::InvalidRelicException(const std::string &relicName,
                                             const std::string &reason)
    : VaultException("Error: Nama relic tidak valid - " + reason),
      relicName(relicName) {}

const std::string &InvalidRelicException::getRelicName() const {
    return relicName;
}
