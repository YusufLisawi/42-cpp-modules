/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:18:07 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/27 15:25:41 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DmergeMe.hpp"

int DmergeMe::comps = 0;

DoubleDeque  DmergeMe::createCollection(char **av)
{
    DoubleDeque collection;
    
    int i = 1;
    while (av[i])
    {
        char *end;
        int tmp = std::strtod(av[i], &end);
        if (*end != '\0' || tmp < 0 || tmp < INT_MIN || tmp > INT_MAX)
            throw std::invalid_argument("Invalid argument " + std::string(av[i]));
        IntDeque tmp_vec;
        tmp_vec.push_back(tmp);
        collection.push_back(tmp_vec);
        i++;
    }
    return (collection);
}

DmergeMe::DmergeMe()
{
}

DmergeMe::~DmergeMe()
{
}

DmergeMe::DmergeMe(const DmergeMe& other)
{
    *this = other;
}

DmergeMe& DmergeMe::operator=(const DmergeMe& other)
{
    if (this != &other) {}
    return (*this);
}

void DmergeMe::mergeInsertion(DoubleDeque &collection)
{
    DoubleDeque remain;
    DoubleDeque mainchain;
    DoubleDeque pend;

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
    for (DoubleDeque::iterator it = collection.begin(); it != collection.end(); it += 2)
    {
        pend.push_back(*it);
        if (it + 1 != collection.end())
            mainchain.push_back(*(it + 1));
    }
    for (DoubleDeque::iterator it = remain.begin(); it != remain.end(); ++it)
        pend.push_back(*it);
    binaryInsertion(mainchain, pend);
    collection = mainchain;
}

void    DmergeMe::binaryInsertion(DoubleDeque &mainchain, DoubleDeque &pend)
{
    IntDeque mainIdxs;
    int i = 0;
    for (DoubleDeque::iterator it = mainchain.begin(); it != mainchain.end(); ++it)
        mainIdxs.push_back(i++);

    IntDeque jacobs = jacobSequence<IntDeque>(pend.size());
    for (IntDeque::iterator it = jacobs.begin(); it != jacobs.end(); ++it)
    {
        int pendIdx = *it;

        IntDeque val = pend.at(pendIdx);
        DoubleDeque::iterator insertion_it;
        if (pendIdx < (int)mainIdxs.size())
            insertion_it = std::lower_bound(mainchain.begin(), mainchain.begin() + mainIdxs[pendIdx], val, compare);
        else
            insertion_it = std::lower_bound(mainchain.begin(), mainchain.end(), val, compare);

        int insertion_idx = std::distance(mainchain.begin(), insertion_it);
        for (IntDeque::iterator it = mainIdxs.begin(); it != mainIdxs.end(); ++it)
        {
            if (*it >= insertion_idx)
                *it += 1;
        }
        mainchain.insert(insertion_it, val);
    }
}

void DmergeMe::pairing(DoubleDeque &collection, DoubleDeque &remain)
{
    DoubleDeque tmp;
    for (DoubleDeque::iterator it = collection.begin(); it != collection.end(); ++it)
    {
        if (it + 1 != collection.end())
        {
            IntDeque tmp_vec;
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

void DmergeMe::splitPairs(DoubleDeque &collection, size_t pairSize)
{
    DoubleDeque tmp;
    for (DoubleDeque::iterator it = collection.begin(); it != collection.end(); ++it)
    {
        IntDeque subVec;
        for (IntDeque::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
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

bool DmergeMe::compare(const IntDeque& a, const IntDeque& b)
{
    comps++;
    return (a.back() < b.back());
}

int DmergeMe::getComps()
{
    return (comps);
}