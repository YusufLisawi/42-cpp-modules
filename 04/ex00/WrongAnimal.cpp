/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:16:14 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/29 16:42:16 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "Constructor called for WrongAnimal"<< std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Destructor called for WrongAnimal"<< std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << "Copy constructor called for WrongAnimal"<< std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "Assignment operator called for WrongAnimal" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

std::string WrongAnimal::getType() const {
    return this->type;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal making sound" << std::endl;
}