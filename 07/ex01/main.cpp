/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:02:37 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/07 13:48:52 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

void printInt(int &n)
{
    std::cout << n << " ";
}

void printDouble(double &d)
{
    std::cout << d << " ";
}

void increment(int &n)
{
    n++;
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    std::cout << "Printing int array: ";
    iter(intArray, 5, printInt);
    std::cout << std::endl;

    std::cout << "Printing double array: ";
    iter(doubleArray, 5, printDouble);
    std::cout << std::endl;

    std::cout << "Incrementing int array: ";
    iter(intArray, 5, increment);
    iter(intArray, 5, printInt);
    std::cout << std::endl;

    return 0;
}