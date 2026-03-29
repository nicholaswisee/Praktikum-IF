
#ifndef VAULT_EXCEPTION_HPP
#define VAULT_EXCEPTION_HPP

#include <exception>
#include <string>

class VaultException : public std::exception {
  protected:
    std::string message;

  public:
    explicit VaultException(const std::string &message);
    const char *what() const noexcept override;
};

class EmptyVaultException : public VaultException {
  public:
    EmptyVaultException();
};

class FullVaultException : public VaultException {
  private:
    size_t maxCapacity;

  public:
    explicit FullVaultException(size_t capacity);
    size_t getCapacity() const;
};

class InvalidRelicException : public VaultException {
  private:
    std::string relicName;

  public:
    InvalidRelicException(const std::string &relicName,
                          const std::string &reason);
    const std::string &getRelicName() const;
};

#endif
