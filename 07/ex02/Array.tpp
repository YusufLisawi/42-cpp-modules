/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:21:18 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/01 19:58:21 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array()
{
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    (void)n;
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
        // add code here
    };
    return (*this);
}
