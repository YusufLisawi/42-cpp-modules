/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:23:09 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/27 00:30:13 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

typedef std::vector<int> IntVector;
typedef std::vector<IntVector> DoubleVector;

void printVector(IntVector collection);
void printVector(DoubleVector collection);
void flattenVector(IntVector collection, IntVector &toInsert);
int  jacobsthal(int n);
IntVector   jacobSequence(size_t len);

template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}