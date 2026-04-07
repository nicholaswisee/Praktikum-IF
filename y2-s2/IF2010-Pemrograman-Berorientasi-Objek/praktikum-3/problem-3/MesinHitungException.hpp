#ifndef MESINHITUNGEXCEPTION_HPP
#define MESINHITUNGEXCEPTION_HPP

#include <exception>
#include <string>
using namespace std;

class MesinHitungException : public exception {
  protected:
    string message;

  public:
    explicit MesinHitungException(const string &message);
    const char *what() const noexcept override;
};

class InvalidTokenException : public MesinHitungException {
  private:
    string token_;

  public:
    explicit InvalidTokenException(const string &token);
    string getToken() const;
};

class InsufficientOperandException : public MesinHitungException {
  public:
    InsufficientOperandException();
};

class DivisionByZeroException : public MesinHitungException {
  public:
    DivisionByZeroException();
};

class InvalidExpressionException : public MesinHitungException {
  public:
    InvalidExpressionException();
};

#endif
