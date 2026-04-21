#include "InternalRecord.hpp"

InternalRecord::InternalRecord(std::string author, int key)
    : BaseRecord(author, key) {}

int InternalRecord::peekSecurity() const { return calculateClearance() * 2; }
