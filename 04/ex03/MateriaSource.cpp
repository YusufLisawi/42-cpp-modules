/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:20:55 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/30 19:30:46 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    //std::cout << "Constructor called for MateriaSource"<< std::endl;
    this->nbMateria = 0;
    for (int i = 0; i < 4; i++) {
        this->materias[i] = NULL;
    }
}

MateriaSource::~MateriaSource() {
    //std::cout << "Destructor called for MateriaSource"<< std::endl;
    for (int i = 0; i < 4; i++) {
        delete this->materias[i];
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    //std::cout << "Copy constructor called for MateriaSource"<< std::endl;
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    //std::cout << "Assignment operator called for MateriaSource" << std::endl;
    if (this != &other) {
        this->nbMateria = other.nbMateria;
        // Delete the current Materias
        for (int i = 0; i < 4; i++) {
            if (this->materias[i] != NULL)
                delete this->materias[i];
        }
        // Copy the new Materias
        for (int i = 0; i < 4; i++) {
            if (other.materias[i] != NULL)
                this->materias[i] = other.materias[i]->clone();
            else
                this->materias[i] = NULL;
        }
    }
    return *this;
}

void        MateriaSource::learnMateria(AMateria* materia) {
    if (this->nbMateria < 4) {
        this->materias[this->nbMateria] = materia;
        this->nbMateria++;
    }
    else
        std::cout << "MateriaSource is full" << std::endl;
}

AMateria*   MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (this->materias[i] && this->materias[i]->getType() == type) {
            return this->materias[i]->clone();
        }
    }
    return NULL;
}
