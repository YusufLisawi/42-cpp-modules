/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:40:17 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/16 10:11:38 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
    // std::cout << "Constructor called for Cure"<< std::endl;
}

Cure::~Cure() {
    // std::cout << "Destructor called for Cure"<< std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
    // std::cout << "Copy constructor called for Cure"<< std::endl;
    *this = other;
}

Cure& Cure::operator=(const Cure& other) {
    // std::cout << "Assignment operator called for Cure" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

void    Cure::use(ICharacter& target) {
    // std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}
