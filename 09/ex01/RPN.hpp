/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:00:30 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/14 10:15:54 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

class RPN 
{
private:
    double result;
    std::stack<double> stack;
public:
    RPN();
    RPN(std::string str);
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    double calculate(std::string str);
    double getResult();
};

