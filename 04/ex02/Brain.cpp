/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:54:17 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/29 17:43:25 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Constructor called for Brain"<< std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = "A brilliant idea";
    }
}

Brain::~Brain() {
    std::cout << "Destructor called for Brain"<< std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Copy constructor called for Brain"<< std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Assignment operator called for Brain" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}
