/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:22:03 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/27 00:30:13 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void printVector(IntVector collection)
{
    std::cout << "[";
    for (IntVector::iterator it = collection.begin(); it != collection.end(); ++it)
    {
        std::cout << *it << ((it + 1 != collection.end()) ? ", " : "");
    }
    std::cout << "]" << std::endl;
}

void printVector(DoubleVector collection)
{
    // std::cout << "[";
    for (DoubleVector::iterator it = collection.begin(); it != collection.end(); ++it)
    {
        // std::cout << "[";
        for (IntVector::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
            std::cout << *it2 << ((it2 + 1 != (*it).end()) ? "" : " ");
        // std::cout << "]";
    }
    std::cout << std::endl;
    // std::cout << "]" << std::endl;
}

void flattenVector(IntVector collection, IntVector &toInsert)
{
    for (IntVector::iterator it = collection.begin(); it != collection.end(); ++it)
    {
        toInsert.push_back(*it);
    }
}

int jacobsthal(int n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

IntVector   jacobSequence(size_t len)
{
    IntVector seq;
    for (size_t i = 0; i < len; ++i)
    {
        size_t j = jacobsthal(i);
        if (j >= len) {
            break; 
        }
        seq.push_back(j);
    }
    seq.push_back(len);

    std::vector<int> result;
    for (int i = 1; i < (int)seq.size(); ++i)
    {
        for (int x = seq[i]; x > seq[i - 1]; --x)
            result.push_back(x - 1);
    }

    return result;
}