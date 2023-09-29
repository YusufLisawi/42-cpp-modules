/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 23:08:34 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/29 23:19:28 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

Serialize::Serialize() {
    // std::cout << "Constructor called for Serialize"<< std::endl;
}

Serialize::~Serialize() {
    // std::cout << "Destructor called for Serialize"<< std::endl;
}

Serialize::Serialize(const Serialize& other) {
    // std::cout << "Copy constructor called for Serialize"<< std::endl;
    *this = other;
}

Serialize& Serialize::operator=(const Serialize& other) {
    // std::cout << "Assignment operator called for Serialize" << std::endl;
    if (this != &other) {
        // Copy data here
    }
    return *this;
}

uintptr_t Serialize::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialize::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
