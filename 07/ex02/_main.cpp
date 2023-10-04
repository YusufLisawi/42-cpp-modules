/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:57:18 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/04 15:24:18 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    Array<int> intArray(5);

    for (unsigned int i = 0; i < intArray.getSize(); i++)
        intArray[i] = i;
    for (unsigned int i = 0; i < intArray.getSize(); i++)
        std::cout << intArray[i] << std::endl;
    try {
        std::cout << intArray[5] << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}