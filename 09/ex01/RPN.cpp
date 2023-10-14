/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:55:08 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/14 10:16:18 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
    // std::cout << "Constructor called for RPN"<< std::endl;
}

RPN::RPN(std::string str) {
    // std::cout << "Constructor called for RPN"<< std::endl;
    this->result = this->calculate(str);
}

RPN::~RPN() {
    // std::cout << "Destructor called for RPN"<< std::endl;
}

RPN::RPN(const RPN& other) {
    // std::cout << "Copy constructor called for RPN"<< std::endl;
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    // std::cout << "Assignment operator called for RPN" << std::endl;
    if (this != &other) {
        this->stack = other.stack;
        this->result = other.result;
    }
    return *this;
}

double RPN::calculate(std::string str)
{
    std::string::iterator it = str.begin();

    for (; it != str.end(); it++)
    {
        if (*it == ' ')
            continue;
        if (*it >= '0' && *it <= '9')
        {
            std::string num_str = "";
            while (*it >= '0' && *it <= '9')
            {
                num_str += *it;
                it++;
            }
            it--;
            stack.push(std::strtod(num_str.c_str(), NULL));
        }
        else if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
        {
            if (stack.size() < 2)
                throw std::invalid_argument("Error");
            double a = stack.top();
            stack.pop();
            double b = stack.top();
            stack.pop();
            if (*it == '+')
                stack.push(a + b);
            else if (*it == '-')
                stack.push(b - a);
            else if (*it == '*')
                stack.push(a * b);
            else if (*it == '/')
            {
                if (a == 0)
                    throw std::invalid_argument("Error");
                stack.push(b / a);
            }
        }
        else
            throw std::invalid_argument("Error");
    }
    if (stack.size() != 1)
        throw std::invalid_argument("Error");
    return stack.top();
}

double RPN::getResult()
{
    return this->result;
}