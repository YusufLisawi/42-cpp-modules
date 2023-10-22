/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:15:38 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/21 21:01:11 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> IntVector;
typedef std::vector<IntVector> PairVector;

bool compare(const IntVector& a, const IntVector& b)
{
    return (a.back() < b.back());
}

void printVector(IntVector collection)
{
    std::cout << "[";
    for (IntVector::iterator it = collection.begin(); it != collection.end(); ++it)
    {
        std::cout << *it << ((it + 1 != collection.end()) ? ", " : "");
    }
    std::cout << "]" << std::endl;
}

void printVector(PairVector collection)
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

PairVector pairing(IntVector collection, size_t size)
{
    PairVector pairs;
    for (size_t i = 0; i < collection.size(); i += size * 2)
    {
        IntVector first_vec;
        IntVector second_vec;
        if (collection.size() - i < size * 2)
        {
            for (size_t j = i; j < collection.size(); j++)
            {
                if (j < i + size)
                    first_vec.push_back(collection[j]);
                else
                    second_vec.push_back(collection[j]);
            }
        }
        else
        {
            for (size_t j = i; j < i + size; j++)
                first_vec.push_back(collection[j]);
            for (size_t j = i + size; j < i + size * 2; j++)
                second_vec.push_back(collection[j]);
            if (first_vec.back() > second_vec.back())
                std::swap(first_vec, second_vec);
        }
        pairs.push_back(first_vec);
        pairs.push_back(second_vec);
    }
    return pairs;
}

void mergeInsertion(IntVector &collection, size_t size)
{
    IntVector remain;
    PairVector pairs;

    if (collection.size() < size * 2)
        return;
    if (collection.size() % (size * 2) != 0)
    {
        for (size_t i = collection.size() - (collection.size() % (size * 2)); i < collection.size(); i++)
            remain.push_back(collection[i]);
        collection.erase(collection.end() - (collection.size() % (size * 2)), collection.end());
    }

    pairs = pairing(collection, size);

    std::cout << "pairs > ";
    printVector(pairs);

    std::cout << "remain > ";
    printVector(remain);

    collection.clear();
    for (PairVector::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        for (IntVector::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
            collection.push_back(*it2);
    } 
    mergeInsertion(collection, size * 2);
    pairs.clear();

    // PairVector tmp;
    // for (PairVector::iterator it = collection.begin(); it != collection.end(); ++it)
    // {
    //     IntVector tmp_vec;
    //     for (IntVector::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
    //     {
    //         tmp_vec.push_back(*it2);
    //         if (tmp_vec.size() == 2)
    //         {
    //             tmp.push_back(tmp_vec);
    //             tmp_vec.clear();
    //         }
    //     }
    // }
    // collection.clear();
    // printVector(tmp);

    // PairVector mainchain;
    // PairVector pend;

    // for (PairVector::iterator it = tmp.begin(); it != tmp.end(); it += 2)
    // {
    //     pend.push_back(*it);
    //     if (it + 1 != tmp.end())
    //         mainchain.push_back(*(it + 1));
    // }
    // tmp.clear();
    // for (PairVector::iterator it = remain.begin(); it != remain.end(); ++it)
    //     pend.push_back(*it);
   
    // std::cout << "mainchain > ";
    // printVector(mainchain);

    // std::cout << "pend > ";
    // printVector(pend);
    
    // for (PairVector::iterator it = pend.begin(); it != pend.end(); ++it)
    // {
    //     PairVector::iterator tmp_it = std::lower_bound(mainchain.begin(), mainchain.end(), *it, compare);
    //     mainchain.insert(tmp_it, *it);
    // }
    // for (PairVector::iterator it = mainchain.begin(); it != mainchain.end(); ++it)
    //     collection.insert(collection.end(), it->begin(), it->end());
    // collection = mainchain;
    // std::cout << "mainchain > ";
    // printVector(mainchain);
}

int main(int ac, char **av)
{
    IntVector collection;
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
        collection.push_back(tmp);
        i++;
    }
    
    mergeInsertion(collection, 1);
}