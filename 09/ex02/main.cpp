/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:15:38 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/27 14:50:19 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "utils.hpp"
#include "PmergeMe.hpp"
#include "DmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Usage: ./PmergeMe [numbers...]" << std::endl;
        return (0);
    }

    try
    {
        // Vector
        DoubleVector collectionV = PmergeMe::createCollection(av);

        std::cout << "Before: ";
        printContainer(collectionV);

        clock_t start_time = clock();
        PmergeMe::mergeInsertion(collectionV);
        clock_t end_time = clock();

        std::cout << "After: ";
        printContainer(collectionV);

        std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << (float)(end_time - start_time) * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;
        std::cout << "Number of comparisons: " << PmergeMe::getComps() << std::endl;
        std::cout << "------------------------------" << std::endl;
        // Deque
        DoubleDeque collectionD = DmergeMe::createCollection(av);

        std::cout << "Before: ";
        printContainer(collectionD);

        start_time = clock();
        DmergeMe::mergeInsertion(collectionD);
        end_time = clock();

        std::cout << "After: ";
        printContainer(collectionD);

        std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << (float)(end_time - start_time) * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;
        std::cout << "Number of comparisons: " << DmergeMe::getComps() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}