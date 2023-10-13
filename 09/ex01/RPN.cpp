#include "RPN.hpp"

RPN::RPN() {
    // std::cout << "Constructor called for RPN"<< std::endl;
}

RPN::~RPN() {
    // std::cout << "Destructor called for RPN"<< std::endl;
}

RPN::RPN(const RPN& other) {
    // std::cout << "Copy constructor called for RPN"<< std::endl;
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    // std::cout << "Assignment operator called for RPN" << std::endl;
    if (this != &other) {
        // Copy data here
    }
    return *this;
}
