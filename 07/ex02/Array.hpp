/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:11:56 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/07 09:42:33 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

template <class T>
class Array
{
    private:
        T *array;
        unsigned int length; 
    public:
        Array(void);
        Array(unsigned int n);
        Array(Array  const &other);
        ~Array();
        Array &operator=(Array const &other);
        T &operator[](unsigned int i);

        unsigned int size(void) const;
};

# include "Array.tpp"
