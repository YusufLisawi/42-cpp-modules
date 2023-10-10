/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:56:21 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/10 18:10:04 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    Span spn = Span(10000);

    std::srand(std::time(nullptr));
    for (int i = 0; i < 10000; i++)
    {
        spn.addNumber(std::rand());
    }

    std::cout << "Shortest span: " << spn.shortestSpan() << std::endl;
    std::cout << "Longest span: " << spn.longestSpan() << std::endl;

    try
    {
        spn.addNumber(1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Span empty = Span(0);
        std::cout << empty.shortestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}
