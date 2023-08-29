/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:20:17 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/29 15:20:18 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
