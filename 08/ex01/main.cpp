/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:56:21 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/10 17:53:45 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    // Test constructor
    Span span(5);

    // Test addNumber
    span.addNumber(1);
    span.addNumber(499);
    span.addNumber(500);

    // Test shortestSpan
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;

    // Test longestSpan
    std::cout << "Longest span: " << span.longestSpan() << std::endl;

    // Test exception handling
    try {
        span.addNumber(6);
    } catch (const Span::ReachedMaxException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Span emptySpan;
        emptySpan.shortestSpan();
    } catch (const Span::NoSpanFoundException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
