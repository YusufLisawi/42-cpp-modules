/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:15:38 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/24 14:34:53 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "utils.hpp"
#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Usage: ./PmergeMe [numbers...]" << std::endl;
        return (0);
    }

    try
    {
        PairVector collection = PmergeMe::createCollection(av);

        std::cout << "Before: ";
        printVector(collection);

        clock_t start_time = clock();
        PmergeMe::mergeInsertion(collection);
        clock_t end_time = clock();

        std::cout << "After: ";
        printVector(collection);

        std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << (float)(end_time - start_time) * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;
        std::cout << "Number of comparisons: " << PmergeMe::comps << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}