/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:21:18 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/04 16:27:24 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array()
{
    this->array = new T;
    this->length = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    this->array = new T[n];
    this->length = n;
}

template <typename T>
Array<T>::Array(Array const &other)
{
    this->array = new T[other.length]; 
    *this = other;
}

template <typename T>
Array<T>::~Array()
{
    delete [] this->array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
    if (this != &other) {
        if (this->array)
            delete [] this->array;
        this->length = other.length;
        this->array = new T[other.length];
        for (unsigned int i = 0; i < other.length; i++)
            this->array[i] = other.array[i];
    };
    return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= this->length)
        throw std::exception();
    return (this->array[i]);
}

template <typename T>
unsigned int Array<T>::size(void) const
{
    return (this->length);
}