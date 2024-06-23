#include <iostream>
#include <stdexcept>
#include "utils.h"

class InvalidInputException : public std::runtime_error {
public:
    InvalidInputException(const std::string& message)
        : std::runtime_error(message) {}
};

