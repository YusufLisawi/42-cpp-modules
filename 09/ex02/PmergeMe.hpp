/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:18:04 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/22 22:30:50 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ctime>
#include "utils.hpp"

template <class Container>
class PmergeMe
{
private:
    Container   collection;
    clock_t     start_time; 
    clock_t     end_time;   
public:
    PmergeMe<Container>() {throw std::invalid_argument("No arguments");};
    PmergeMe<Container>(char **av)
    {
        start_time = clock();
        int i = 1;
        while (av[i])
        {
            int tmp = std::atoi(av[i]);
            if (tmp < 0 || tmp < INT_MIN || tmp > INT_MAX)
                throw std::invalid_argument("Invalid argument " + std::string(av[i]));
            this->collection.push_back(tmp);
            i++;
        }
    };
    ~PmergeMe<Container>() {};
    PmergeMe<Container>(const PmergeMe& other) {*this = other;};
    PmergeMe<Container>& operator=(const PmergeMe& other) 
    {
        if (this != &other) 
        {
            this->collection = other.collection;
            this->start_time = other.start_time;
            this->end_time = other.end_time;
        }
        return *this;
    };
};

#include "PmergeMe.tpp"