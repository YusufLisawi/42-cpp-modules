#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "Constructor called for ScalarConverter"<< std::endl;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "Destructor called for ScalarConverter"<< std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    std::cout << "Copy constructor called for ScalarConverter"<< std::endl;
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    std::cout << "Assignment operator called for ScalarConverter" << std::endl;
    if (this != &other) {
        // Copy data here
    }
    return *this;
}
