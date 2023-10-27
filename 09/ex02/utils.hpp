/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:23:09 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/27 11:36:43 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <math.h>

typedef std::vector<int> IntVector;
typedef std::vector<IntVector> DoubleVector;

typedef std::deque<int> IntDeque;
typedef std::deque<IntDeque> DoubleDeque;

template <typename T>
void printNestedContainer(T collection)
{
    // std::cout << "[";
    for (typename T::iterator it = collection.begin(); it != collection.end(); ++it)
        std::cout << *it << ((it + 1 != collection.end()) ? "" : " ");
    // std::cout << "]" << std::endl;

}
template <typename T>
void printContainer(T collection)
{
    // std::cout << "[";
    for (typename T::iterator it = collection.begin(); it != collection.end(); ++it)
        printNestedContainer(*it);
    std::cout << std::endl;
    // std::cout << "]" << std::endl;
}

template <typename T>
void flattenVector(T collection, T &toInsert)
{
    for (typename T::iterator it = collection.begin(); it != collection.end(); ++it)
        toInsert.push_back(*it);
}

int         jacobsthal(int n);
IntVector   jacobSequence(size_t len);

template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}