/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:18:07 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/23 19:12:59 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

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

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
    }
    return (*this);
}

std::vector<int> pending_element_indexes(int len) {
    std::vector<int> seq;
    for (int i = 0; i < len; ++i) {
        int num = round((pow(2, i) + pow(-1, i - 1)) / 3);
        if (num >= len) {
            break;
        }
        seq.push_back(num);
    }
    seq.push_back(len);

    std::vector<int> result;
    for (int i = 1; i < seq.size(); ++i) {
        for (int x = seq[i] - 1; x >= seq[i - 1]; --x) {
            result.push_back(x - 1);
        }
    }

    return result;
}

void binary_insert(std::vector<int>& a_positions, std::vector<int>& main_chain, std::vector<int>& pending_elements, int b_index, std::function<bool(int, int)> comp) {
    int val = pending_elements[b_index];
    std::vector<int> search_chain;
    if (b_index < a_positions.size()) {
        search_chain = std::vector<int>(main_chain.begin(), main_chain.begin() + a_positions[b_index]);
    } else {
        search_chain = main_chain;
    }

    std::vector<int>::iterator insertion_it = std::lower_bound(search_chain.begin(), search_chain.end(), val, comp);

    int insertion_idx = insertion_it - search_chain.begin();
    for (int idx = 0; idx < a_positions.size(); ++idx) {
        if (a_positions[idx] >= insertion_idx) {
            ++a_positions[idx];
        }
    }

    main_chain.insert(main_chain.begin() + insertion_idx, val);
}

void merge_insertion_sort(std::vector<int>& main_chain, std::vector<int>& pending_elements, std::function<bool(int, int)> comp) {
    std::vector<int> a_positions(main_chain.size());
    for (int i = 0; i < a_positions.size(); ++i) {
        a_positions[i] = i;
    }

    std::vector<int> pending_indexes = pending_element_indexes(pending_elements.size());
    for (int b_index : pending_indexes) {
        binary_insert(a_positions, main_chain, pending_elements, b_index, comp);
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
    PairVector::iterator it = pend.begin();
    PairVector::iterator main_it = mainchain.begin();
    mainchain.insert(main_it, *it);
    it++;
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
    return (a.back() < b.back());
}
