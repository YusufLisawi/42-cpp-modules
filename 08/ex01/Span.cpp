/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:29:05 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/10 18:00:18 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0)
{
    // std::cout << "Constructor called for Span"<< std::endl;
}

Span::Span(unsigned int n) : N(n)
{
    // std::cout << "Constructor called for Span"<< std::endl;
}

Span::~Span()
{
    // std::cout << "Destructor called for Span"<< std::endl;
}

Span::Span(const Span &other)
{
    // std::cout << "Copy constructor called for Span"<< std::endl;
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    // std::cout << "Assignment operator called for Span" << std::endl;
    if (this != &other)
    {
        this->N = other.N;
        this->container = other.container;
    }
    return *this;
}

void Span::addNumber(unsigned int n)
{
    if (N > 0)
    {
        this->container.push_back(n);
        this->N--;
    }
    else
    {
        throw Span::ReachedMaxException();
    }
}

int Span::shortestSpan()
{
    if (this->container.empty() || this->container.size() < 2)
        throw Span::NoSpanFoundException();
    std::vector<int> tmp = this->container;
    std::sort(tmp.begin(), tmp.end());
    std::vector<int>::iterator it = tmp.begin();
    int min = *(it + 1) - *it;
    for (it = tmp.begin(); it != tmp.end() - 1; it++)
    {
        if (*(it + 1) - *it < min)
            min = *(it + 1) - *it;
    }
    return min;
}
int Span::longestSpan()
{
    if (this->container.empty() || this->container.size() < 2)
        throw Span::NoSpanFoundException();
    int max = *std::max_element(this->container.begin(), this->container.end());
    int min = *std::min_element(this->container.begin(), this->container.end());
    return (max - min);
}

const char *Span::ReachedMaxException::what() const throw()
{
    return "Reached max number of elements";
}

const char *Span::NoSpanFoundException::what() const throw()
{
    return "No span found";
}