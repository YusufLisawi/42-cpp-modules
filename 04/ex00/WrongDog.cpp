/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:20:23 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/29 15:50:37 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog() {
    std::cout << "Constructor called for WrongDog"<< std::endl;
    this->type = "WrongDog";
}

WrongDog::~WrongDog() {
    std::cout << "Destructor called for WrongDog"<< std::endl;
}

WrongDog::WrongDog(const WrongDog& other) {
    std::cout << "Copy constructor called for WrongDog"<< std::endl;
    *this = other;
}

WrongDog& WrongDog::operator=(const WrongDog& other) {
    std::cout << "Assignment operator called for WrongDog" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

void WrongDog::makeSound() const {
    std::cout << "Woof Woof!!" << std::endl;
}