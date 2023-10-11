/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:29:02 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/11 16:32:20 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class Span 
{
private:
    unsigned int N;
    std::vector<int> container;
public:
    Span();
    Span(unsigned int n);
    ~Span();
    Span(const Span& other);
    Span& operator=(const Span& other);

    void    addNumber(unsigned int n);
    int     shortestSpan();
    int     longestSpan();

    void addRange(std::vector<int>::iterator first, std::vector<int>::iterator last);

    class ReachedMaxException : public std::exception {
        public:
            const char *what() const throw();
    };
    
    class NoSpanFoundException : public std::exception {
        public:
            const char *what() const throw();
    };
};

