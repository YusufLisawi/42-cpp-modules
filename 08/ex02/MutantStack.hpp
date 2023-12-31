/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:58:23 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/13 11:32:07 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <deque>

template <class T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() : std::stack<T>()
    ~MutantStack() {};
    MutantStack(const MutantStack& other) : std::stack<T>() { 
        *this = other;
    };
    MutantStack& operator=(const MutantStack& other) { 
        (void)other;
        return *this;
    };
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() { 
        return std::stack<T>::c.begin();
    };
    iterator end() {
        return std::stack<T>::c.end();
    };
};

