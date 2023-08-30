/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:31:24 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/30 18:23:16 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("Default"), count(0), unequippedCount(0) {
    //std::cout << "Constructor called for Character"<< std::endl;
    this->inventory = new AMateria*[4];
    this->unequippedMaterias = new AMateria*[4];
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = NULL;
        this->unequippedMaterias[i] = NULL;
    }
}

Character::Character(std::string const &name) : name(name), count(0), unequippedCount(0) {
    //std::cout << "Constructor called for Character"<< std::endl;
    this->inventory = new AMateria*[4];
    this->unequippedMaterias = new AMateria*[4];
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = NULL;
        this->unequippedMaterias[i] = NULL;
    }
}

Character::~Character() {
    //std::cout << "Destructor called for Character"<< std::endl;
    for (int i = 0; i < 4; i++) {
        delete this->inventory[i];
        delete this->unequippedMaterias[i];
    }
    delete [] this->unequippedMaterias;
    delete [] this->inventory;
}

Character::Character(const Character& other) {
    //std::cout << "Copy constructor called for Character"<< std::endl;
    *this = other;
}

Character& Character::operator=(const Character& other) {
    //std::cout << "Assignment operator called for Character" << std::endl;
    if (this != &other) {
        // Delete the current Materias
        for (int i = 0; i < 4; i++) {
            delete this->inventory[i];
            delete this->unequippedMaterias[i];
        }
        // Copy the new Materias
        this->name = other.name;
        this->count = other.count;
        this->unequippedCount = other.unequippedCount;
        for (int i = 0; i < 4; i++) {
            if (other.inventory[i] != NULL) {
                this->inventory[i] = other.inventory[i]->clone();
            } else {
                this->inventory[i] = NULL;
            }
            if (other.unequippedMaterias[i] != NULL) {
                this->unequippedMaterias[i] = other.unequippedMaterias[i]->clone();
            } else {
                this->unequippedMaterias[i] = NULL;
            }
        }
    }
    return *this;
}

std::string const &Character::getName() const {
    return this->name;
}

void    Character::equip(AMateria* m) {
    if (this->count < 4 && m != NULL) {
        this->inventory[this->count] = m;
        this->count++;
    }
}
void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        if (unequippedCount > 3) {
        for (int i = 0; i < 4; i++) {
                delete this->unequippedMaterias[i];
                this->unequippedMaterias[i] = NULL;
            }
            this->unequippedCount = 0;
        }
        this->unequippedMaterias[this->unequippedCount] = this->inventory[idx];
        this->inventory[idx] = NULL;
        this->unequippedCount++;
        this->count--;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL)
        this->inventory[idx]->use(target);
}