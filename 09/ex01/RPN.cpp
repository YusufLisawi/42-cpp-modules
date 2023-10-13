/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:55:08 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/13 14:55:09 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
    // std::cout << "Constructor called for RPN"<< std::endl;
}

RPN::~RPN() {
    // std::cout << "Destructor called for RPN"<< std::endl;
}

RPN::RPN(const RPN& other) {
    // std::cout << "Copy constructor called for RPN"<< std::endl;
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    // std::cout << "Assignment operator called for RPN" << std::endl;
    if (this != &other) {
        // Copy data here
    }
    return *this;
}
