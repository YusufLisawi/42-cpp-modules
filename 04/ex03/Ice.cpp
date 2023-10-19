/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:40:38 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/16 10:11:49 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    // std::cout << "Constructor called for Ice"<< std::endl;
}

Ice::~Ice() {
    // std::cout << "Destructor called for Ice"<< std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
    // std::cout << "Copy constructor called for Ice"<< std::endl;
    *this = other;
}

Ice& Ice::operator=(const Ice& other) {
    // std::cout << "Assignment operator called for Ice" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

void    Ice::use(ICharacter& target) {
    // std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}