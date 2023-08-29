#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Constructor called for Dog"<< std::endl;
}

Dog::~Dog() {
    std::cout << "Destructor called for Dog"<< std::endl;
}

Dog::Dog(const Dog& other) {
    std::cout << "Copy constructor called for Dog"<< std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Assignment operator called for Dog" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}
