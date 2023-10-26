/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:23:09 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/27 00:21:06 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

typedef std::vector<int> IntVector;
typedef std::vector<IntVector> PairVector;

void printVector(IntVector collection);
void printVector(PairVector collection);
void flattenVector(IntVector collection, IntVector &toInsert);
int  jacobsthal(int n);

template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}