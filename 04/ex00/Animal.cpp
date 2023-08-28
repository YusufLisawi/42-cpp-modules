#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Constructor called for Animal"<< std::endl;
}

Animal::~Animal() {
    std::cout << "Destructor called for Animal"<< std::endl;
}

Animal::Animal(const Animal& other) {
    std::cout << "Copy constructor called for Animal"<< std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Assignment operator called for Animal" << std::endl;
    if (this != &other) {
        // Copy data here
    }
    return *this;
}
