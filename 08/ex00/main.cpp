/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:16:55 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/10 16:20:31 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <set>
#include <deque>
#include <list>

int main()
{
    std::vector<int> vec;
    std::list<int> lst;
    std::set<int> st;
    std::deque<int> dq;
    
    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i);
        lst.push_back(i * 10);
        st.insert(i * 100);
        dq.push_back(i * 1000);
    }

    try {
        std::cout << easyfind(vec, 3) << std::endl;
        std::cout << easyfind(lst, 40) << std::endl;
        std::cout << easyfind(st, 500) << std::endl;
        std::cout << easyfind(dq, 6000) << std::endl;
        std::cout << easyfind(vec, 600) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Element not found in container" << std::endl;
    }

    return 0;
}