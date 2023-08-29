/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:16:14 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/29 15:16:15 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        this->type = other.type;
    }
    return *this;
}
