/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:18:07 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/27 15:26:11 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int PmergeMe::comps = 0;

DoubleVector  PmergeMe::createCollection(char **av)
{
    DoubleVector collection;
    
    int i = 1;
    while (av[i])
    {
        char *end;
        int tmp = std::strtod(av[i], &end);
        if (*end != '\0' || tmp < 0 || tmp < INT_MIN || tmp > INT_MAX)
            throw std::invalid_argument("Invalid argument " + std::string(av[i]));
        IntVector tmp_vec;
        tmp_vec.push_back(tmp);
        collection.push_back(tmp_vec);
        i++;
    }
    return (collection);
}

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other) {}
    return (*this);
}

void PmergeMe::mergeInsertion(DoubleVector &collection)
{
    DoubleVector remain;
    DoubleVector mainchain;
    DoubleVector pend;

    if (collection.size() == 1)
        return; 
    if (collection.size() % 2 != 0)
    {
        remain.push_back(collection.back());
        collection.pop_back();
    }
    pairing(collection, remain);
    mergeInsertion(collection);
    splitPairs(collection, collection.at(0).size() / 2);
    for (DoubleVector::iterator it = collection.begin(); it != collection.end(); it += 2)
    {
        pend.push_back(*it);
        if (it + 1 != collection.end())
            mainchain.push_back(*(it + 1));
    }
    for (DoubleVector::iterator it = remain.begin(); it != remain.end(); ++it)
        pend.push_back(*it);
    binaryInsertion(mainchain, pend);
    collection = mainchain;
}

void    PmergeMe::binaryInsertion(DoubleVector &mainchain, DoubleVector &pend)
{
    IntVector mainIdxs;
    int i = 0;
    for (DoubleVector::iterator it = mainchain.begin(); it != mainchain.end(); ++it)
        mainIdxs.push_back(i++);
    
    IntVector jacobs = jacobSequence<IntVector>(pend.size());
    for (IntVector::iterator it = jacobs.begin(); it != jacobs.end(); ++it)
    {
        int pendIdx = *it;

        IntVector val = pend.at(pendIdx);
        DoubleVector::iterator insertion_it;;
        if (pendIdx < (int)mainIdxs.size())
            insertion_it = std::lower_bound(mainchain.begin(), mainchain.begin() + mainIdxs[pendIdx], val, compare);
        else
            insertion_it = std::lower_bound(mainchain.begin(), mainchain.end(), val, compare);

        int insertion_idx = std::distance(mainchain.begin(), insertion_it);
        for (IntVector::iterator it = mainIdxs.begin(); it != mainIdxs.end(); ++it)
        {
            if (*it >= insertion_idx)
                *it += 1;
        }
        mainchain.insert(insertion_it, val);
    }
}

void PmergeMe::pairing(DoubleVector &collection, DoubleVector &remain)
{
    DoubleVector tmp;
    for (DoubleVector::iterator it = collection.begin(); it != collection.end(); ++it)
    {
        if (it + 1 != collection.end())
        {
            IntVector tmp_vec;
            comps++;
            if ((*it).back() > (*(it + 1)).back())
                swap((*it), (*(it + 1)));

            flattenContainer(*it, tmp_vec);
            flattenContainer(*(it + 1), tmp_vec);
            tmp.push_back(tmp_vec);
            it++;
        }
        else
            remain.push_back(*it);
    }
    collection = tmp;
}

void PmergeMe::splitPairs(DoubleVector &collection, size_t pairSize)
{
    DoubleVector tmp;
    for (DoubleVector::iterator it = collection.begin(); it != collection.end(); ++it)
    {
        IntVector subVec;
        for (IntVector::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
        {
            subVec.push_back(*it2);
            if (subVec.size() == pairSize)
            {
                tmp.push_back(subVec);
                subVec.clear();
            }
        }
        if (subVec.size() > 0)
        {
            tmp.push_back(subVec);
        }
    }
    collection = tmp;
}

bool PmergeMe::compare(const IntVector& a, const IntVector& b)
{
    comps++;
    return (a.back() < b.back());
}

int PmergeMe::getComps()
{
    return (comps);
}