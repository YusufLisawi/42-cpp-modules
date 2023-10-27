/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:18:04 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/27 14:55:40 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ctime>
#include <deque>
#include "utils.hpp"

class DmergeMe
{
private:
    DmergeMe();
    DmergeMe(char **av);
    ~DmergeMe();
    DmergeMe(const DmergeMe& other);
    DmergeMe& operator=(const DmergeMe& other); 
    static int          comps;
public:
    static void             mergeInsertion(DoubleDeque &collection);
    static DoubleDeque      createCollection(char **av);
    static void             binaryInsertion(DoubleDeque &mainchain, DoubleDeque &pend);
    static void             pairing(DoubleDeque &collection, DoubleDeque &remain);
    static void             splitPairs(DoubleDeque &collection, size_t pairSize);
    static bool             compare(const IntDeque& a, const IntDeque& b);
    static int              getComps();
};
