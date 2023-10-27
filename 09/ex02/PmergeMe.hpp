/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:18:04 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/27 14:56:06 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ctime>
#include <vector>
#include "utils.hpp"

class PmergeMe
{
private:
    PmergeMe();
    PmergeMe(char **av);
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other); 
    static int          comps;
public:
    static void        mergeInsertion(DoubleVector &collection);
    static DoubleVector  createCollection(char **av);
    static void        binaryInsertion(DoubleVector &mainchain, DoubleVector &pend);
    static void        pairing(DoubleVector &collection, DoubleVector &remain);
    static void        splitPairs(DoubleVector &collection, size_t pairSize);
    static bool        compare(const IntVector& a, const IntVector& b);
    static int         getComps();
};
