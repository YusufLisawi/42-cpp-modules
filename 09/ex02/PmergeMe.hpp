/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:18:04 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/23 19:13:52 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ctime>
#include "utils.hpp"

class PmergeMe
{
private:
    PmergeMe();
    PmergeMe(char **av);
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other); 
public:
    static int          comps;
    static void        mergeInsertion(PairVector &collection);
    static PairVector  createCollection(char **av);
    static void        binaryInsertion(PairVector &mainchain, PairVector &pend);
    static void        pairing(PairVector &collection, PairVector &remain);
    static void        splitPairs(PairVector &collection, size_t pairSize);
    static bool        compare(const IntVector& a, const IntVector& b);
};
