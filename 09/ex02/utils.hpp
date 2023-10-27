/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:23:09 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/27 15:28:33 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>

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
void flattenContainer(T collection, T &toInsert)
{
    for (typename T::iterator it = collection.begin(); it != collection.end(); ++it)
        toInsert.push_back(*it);
}

template <typename T>
T   jacobSequence(size_t len)
{
    T seq;
    for (size_t i = 0; i < len; ++i)
    {
        size_t j = (pow(2, i) + pow(-1, i - 1)) / 3;
        if (j >= len) {
            break; 
        }
        seq.push_back(j);
    }
    seq.push_back(len);

    T result;
    for (int i = 1; i < (int)seq.size(); ++i)
    {
        for (int x = seq[i]; x > seq[i - 1]; --x)
            result.push_back(x - 1);
    }

    return result;
}

template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}