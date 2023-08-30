/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:24:32 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/30 18:23:16 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("Default") {
    //std::cout << "Constructor called for AMateria"<< std::endl;
}

AMateria::AMateria(std::string const &type) : type(type) {
    //std::cout << "Constructor called for AMateria"<< std::endl;
}

AMateria::~AMateria() {
    //std::cout << "Destructor called for AMateria"<< std::endl;
}

AMateria::AMateria(const AMateria& other) {
    //std::cout << "Copy constructor called for AMateria"<< std::endl;
    *this = other;
}

AMateria& AMateria::operator=(const AMateria& other) {
    //std::cout << "Assignment operator called for AMateria" << std::endl;
    if (this != &other) {
        // this->type = other.type;
    }
    return *this;
}

std::string const &AMateria::getType() const {
    return this->type;
}

void AMateria::use(ICharacter& target) {
    (void) target;
}
