/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:56:21 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/11 17:05:46 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    
    Span spn = Span(10000);

    std::srand(std::time(0));
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

    Span s(5);
    std::vector<int> v;
    v.push_back(5);
    v.push_back(54);
    v.push_back(34);
    v.push_back(2);
    s.addRange(v.begin(), v.end());
    std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
    std::cout << "Longest span: " << s.longestSpan() << std::endl;

    
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
