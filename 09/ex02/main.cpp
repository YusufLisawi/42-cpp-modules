/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:15:38 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/27 17:13:09 by yelaissa         ###   ########.fr       */
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

        clock_t start_timeV = clock();
        PmergeMe::mergeInsertion(collectionV);
        clock_t end_timeV = clock();

        std::cout << "After: ";
        printContainer(collectionV);

        // Deque
        DoubleDeque collectionD = DmergeMe::createCollection(av);

        clock_t start_timeD = clock();
        DmergeMe::mergeInsertion(collectionD);
        clock_t end_timeD = clock();

        std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << (float)(end_timeV - start_timeV) * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << (float)(end_timeD - start_timeD) * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;
        // std::cout << "Number of comparisons: " << DmergeMe::getComps() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}