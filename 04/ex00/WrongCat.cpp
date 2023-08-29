/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:20:17 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/29 15:51:05 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "Constructor called for WrongCat"<< std::endl;
    this->type = "WrongCat";
}

WrongCat::~WrongCat() {
    std::cout << "Destructor called for WrongCat"<< std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
    std::cout << "Copy constructor called for WrongCat"<< std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "Assignment operator called for WrongCat" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "Meow Meow!!" << std::endl;
}