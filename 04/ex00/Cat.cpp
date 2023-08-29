#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Constructor called for Cat"<< std::endl;
}

Cat::~Cat() {
    std::cout << "Destructor called for Cat"<< std::endl;
}

Cat::Cat(const Cat& other) {
    std::cout << "Copy constructor called for Cat"<< std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Assignment operator called for Cat" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}
