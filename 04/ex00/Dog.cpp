/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:20:23 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/29 15:20:24 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
