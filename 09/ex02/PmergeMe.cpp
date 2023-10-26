/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:18:07 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/27 00:21:22 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

int PmergeMe::comps = 0;

PairVector  PmergeMe::createCollection(char **av)
{
    PairVector collection;
    
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

void PmergeMe::mergeInsertion(PairVector &collection)
{
    PairVector remain;
    PairVector mainchain;
    PairVector pend;

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
    for (PairVector::iterator it = collection.begin(); it != collection.end(); it += 2)
    {
        pend.push_back(*it);
        if (it + 1 != collection.end())
            mainchain.push_back(*(it + 1));
    }
    for (PairVector::iterator it = remain.begin(); it != remain.end(); ++it)
        pend.push_back(*it);
    binaryInsertion(mainchain, pend);
    collection = mainchain;
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

void    PmergeMe::binaryInsertion(PairVector &mainchain, PairVector &pend)
{
    std::vector<int> aPositions;
    for (PairVector::iterator it = mainchain.begin(); it != mainchain.end(); ++it)
    {
        int distance = static_cast<int>(std::distance(mainchain.begin(), it));
        aPositions.push_back(distance);
    }
    IntVector jacobs = jacobSequence(pend.size());
    for (std::vector<int>::iterator it = jacobs.begin(); it != jacobs.end(); ++it)
    {
        int bIdx = *it;

        IntVector val = pend.at(bIdx);
        PairVector searchChain;
        if (bIdx < (int)aPositions.size())
            searchChain = PairVector(mainchain.begin(), mainchain.begin() + aPositions[bIdx]);
        else
            searchChain = mainchain;

        PairVector::iterator insertion_it = std::lower_bound(searchChain.begin(), searchChain.end(), val, compare);
        int insertion_idx = insertion_it - searchChain.begin();

        for (IntVector::iterator it = aPositions.begin(); it != aPositions.end(); ++it)
        {
            if (*it >= insertion_idx)
                *it += 1;
        }

        mainchain.insert(mainchain.begin() + insertion_idx, val);
    }
}

void PmergeMe::pairing(PairVector &collection, PairVector &remain)
{
    PairVector tmp;
    for (PairVector::iterator it = collection.begin(); it != collection.end(); ++it)
    {
        if (it + 1 != collection.end())
        {
            IntVector tmp_vec;
            comps++;
            if ((*it).back() > (*(it + 1)).back())
                swap((*it), (*(it + 1)));

            flattenVector(*it, tmp_vec);
            flattenVector(*(it + 1), tmp_vec);
            tmp.push_back(tmp_vec);
            it++;
        }
        else
            remain.push_back(*it);
    }
    collection = tmp;
}

void PmergeMe::splitPairs(PairVector &collection, size_t pairSize)
{
    PairVector tmp;
    for (PairVector::iterator it = collection.begin(); it != collection.end(); ++it)
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
