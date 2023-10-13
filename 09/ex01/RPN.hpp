/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:00:30 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/13 18:02:03 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

class RPN 
{
private:
    std::string str;
    std::stack<double> stack;
public:
    RPN();
    RPN(std::string str);
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    double calculate();
};

