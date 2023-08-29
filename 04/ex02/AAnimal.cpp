/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:16:14 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/29 15:47:51 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "Constructor called for AAnimal"<< std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "Destructor called for AAnimal"<< std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
    std::cout << "Copy constructor called for AAnimal"<< std::endl;
    *this = other;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    std::cout << "Assignment operator called for AAnimal" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

std::string AAnimal::getType() const {
    return this->type;
}
