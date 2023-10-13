/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:21:41 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/13 11:32:18 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main()
{
    MutantStack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    std::cout << "Elements in stack: ";
    for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Top element: " << stack.top() << std::endl;

    stack.pop();
    std::cout << "Elements in stack after pop(): ";
    for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Size of stack: " << stack.size() << std::endl;

    return 0;
}