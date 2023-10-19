/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:15:38 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/19 21:03:22 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> IntVector;
typedef std::vector<IntVector> PairVector;

void    printVector(PairVector collection)
{
    std::cout << "[";
    for (PairVector::iterator it = collection.begin(); it != collection.end(); ++it)
    {
        std::cout << "[";
        for (IntVector::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
            std::cout << *it2 << ((it2 + 1 != (*it).end()) ? ", " : "");
        std::cout << "]";
    }
    std::cout << "]" << std::endl;
}

void flattenVector(IntVector collection, IntVector &toInsert)
{
    for (IntVector::iterator it = collection.begin(); it != collection.end(); ++it)
    {
        toInsert.push_back(*it);
    }
}

int main(int ac, char **av)
{
    PairVector collection;
    if (ac < 2)
    {
        std::cout << "Usage: ./PmergeMe [numbers...]" << std::endl;
        return (0);
    }
    int i = 1;
    while (av[i])
    {
        int tmp = std::atoi(av[i]);
        if (tmp < 0 || tmp < INT_MIN || tmp > INT_MAX)
            throw std::invalid_argument("Invalid argument " + std::string(av[i]));
        IntVector tmp_vec;
        tmp_vec.push_back(tmp);
        collection.push_back(tmp_vec);
        i++;
    }
    printVector(collection);
    PairVector tmp;
    PairVector rest;
    for (PairVector::iterator it = collection.begin(); it != collection.end(); ++it)
    {
        if (it + 1 != collection.end())
        {
            IntVector tmp_vec;
            if ((*it).back() > (*(it + 1)).back())
                std::swap((*it), (*(it + 1)));
            
            flattenVector(*it, tmp_vec);
            flattenVector(*(it + 1), tmp_vec);
            tmp.push_back(tmp_vec);
            it++;
        }
        else
            rest.push_back(*it);
    }
    collection = tmp;
    printVector(collection);
    tmp.clear();
    for (PairVector::iterator it = collection.begin(); it != collection.end(); ++it)
    {
        if (it + 1 != collection.end())
        {
            IntVector tmp_vec;
            if ((*it).back() > (*(it + 1)).back())
                std::swap((*it), (*(it + 1)));
            
            flattenVector(*it, tmp_vec);
            flattenVector(*(it + 1), tmp_vec);
            tmp.push_back(tmp_vec);
            it++;
        }
        else
            rest.push_back(*it);
    }
    collection = tmp;
    printVector(collection);
}