/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:15:38 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/20 15:32:48 by yelaissa         ###   ########.fr       */
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

void pairing(PairVector &collection, PairVector &remain)
{
    PairVector tmp;
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
            remain.push_back(*it);
    }
    collection.clear();
    collection = tmp;
}

void mergeInsertion(PairVector &collection, size_t size)
{
    PairVector remain;

    if (collection.size() <= 3)
        return;
    if (collection.size() % 2 != 0)
    {
        remain.push_back(collection.back());
        collection.pop_back();
    }
    
    pairing(collection, remain);

    std::cout << "collection > ";
    printVector(collection);

    std::cout << "remain > ";
    printVector(remain);

    mergeInsertion(collection, size * 2);

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
    mergeInsertion(collection, 1);
}