/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:21:18 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/01 18:00:35 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array()
{
}

template <typename T>
Array<T>::Array(unsigned int n)
{
}

template <typename T>
Array<T>::Array(Array const &other)
{
    *this = other;
}

template <typename T>
Array<T>::~Array()
{
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
    if (this != &other)
    {
        
    }
    return (*this);
}

#endif