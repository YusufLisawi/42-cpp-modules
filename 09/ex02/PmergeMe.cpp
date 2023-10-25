/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:18:07 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/25 00:59:50 by yelaissa         ###   ########.fr       */
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

IntVector pendIndexes(int len) {
    IntVector   indexes;

    for (int i = 3; i <= len; i++) {
        int j = jacobsthal(i);

        if (j >= len) {
            indexes.push_back(len - 1);
            break;
        }
        else
            indexes.push_back(j);
    }
    return indexes;
}

void binary_insert(IntVector& a_positions, PairVector& main_chain, PairVector& pending_elements, size_t b_index) {
    IntVector val = pending_elements[b_index];
    PairVector search_chain;
    if (b_index < a_positions.size()) {
        search_chain = PairVector(main_chain.begin(), main_chain.begin() + a_positions[b_index]);
    } else {
        search_chain = main_chain;
    }

    PairVector::iterator insertion_it = std::lower_bound(search_chain.begin(), search_chain.end(), val, PmergeMe::compare);

    int insertion_idx = insertion_it - search_chain.begin();
    for (size_t idx = 0; idx < a_positions.size(); ++idx) {
        if (a_positions[idx] >= insertion_idx) {
            ++a_positions[idx];
        }
    }

    main_chain.insert(main_chain.begin() + insertion_idx, val);
}

void merge_insertion_sort(PairVector& main_chain, PairVector& pending_elements) {
    std::vector<int> a_positions(main_chain.size());
    for (size_t i = 0; i < a_positions.size(); ++i) {
        a_positions[i] = i;
    }

    std::vector<int> pending_indexes = pendIndexes(pending_elements.size());
    for (size_t b_index = 0; b_index < pending_indexes.size(); b_index++) {
        binary_insert(a_positions, main_chain, pending_elements, pending_indexes[b_index]);
    }
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

void    PmergeMe::binaryInsertion(PairVector &mainchain, PairVector &pend)
{
    if (pend.size() == 0)
        return ;
    PairVector::iterator it = pend.begin();
    mainchain.insert(mainchain.begin(), *(it++));
    if (pend.size() >= 2)
    {
        PairVector::iterator it2 = std::lower_bound(mainchain.begin(), mainchain.begin() + 2, *it, compare);
        mainchain.insert(it2, *(it++));
    }
    IntVector jacobIdx;
    for (size_t i = 2; i < pend.size(); i++)
    {
        int j = jacobsthal(i);
        jacobIdx.push_back(j);
    }
    for (size_t i = 0; i < jacobIdx.size(); i++)
    {
        if (jacobIdx[i] >= (int)pend.size())
            jacobIdx[i] = pend.size() - 1;
        size_t begin = jacobIdx[i];
        // size_t move = jacobIdx[i];
        size_t end = jacobIdx[i - 1];
        for (size_t j = begin; j > end; j--)
        {
            PairVector::iterator tmp_it = std::lower_bound(mainchain.begin(), mainchain.end(), pend[j], compare);
            mainchain.insert(tmp_it, pend[j]);
            pend.erase(pend.begin() + j);
        }
    }
    for (; it != pend.end(); ++it)
    {
        PairVector::iterator tmp_it = std::lower_bound(mainchain.begin(), mainchain.end(), *it, compare);
        mainchain.insert(tmp_it, *it);
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
                std::swap((*it), (*(it + 1)));

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
