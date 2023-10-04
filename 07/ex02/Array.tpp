/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:21:18 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/04 15:37:58 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : size(0)
{
    this->array = new T;
}

template <typename T>
Array<T>::Array(unsigned int n) : size(n)
{
    this->array = new T[n];
}

template <typename T>
Array<T>::Array(Array const &other)
{
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
        // if (this->array)
        //     delete [] this->array;
        this->size = other.size;
        this->array = new T[other.size];
        for (unsigned int i = 0; i < other.size; i++)
            this->array[i] = other.array[i];
    };
    return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= this->size)
        throw std::exception();
    return (this->array[i]);
}

template <typename T>
unsigned int Array<T>::getSize(void) const
{
    return (this->size);
}