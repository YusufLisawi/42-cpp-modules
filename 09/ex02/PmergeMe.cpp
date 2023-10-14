/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:18:07 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/14 10:18:08 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
    // std::cout << "Constructor called for PmergeMe"<< std::endl;
}

PmergeMe::~PmergeMe() {
    // std::cout << "Destructor called for PmergeMe"<< std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other) {
    // std::cout << "Copy constructor called for PmergeMe"<< std::endl;
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    // std::cout << "Assignment operator called for PmergeMe" << std::endl;
    if (this != &other) {
        // Copy data here
    }
    return *this;
}
