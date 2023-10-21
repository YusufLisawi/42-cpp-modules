
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:17:09 by htalhaou          #+#    #+#             */
/*   Updated: 2023/10/20 18:28:12 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int comp = 0;

bool Compare(const std::deque<int>& d1, const std::deque<int>& d2)
{
    comp++;
    return (d1.back() < d2.back());
}
std::vector<int> Jacobsthal(int n)
{
    std::vector<int> arr(n);
    if (n == 0)
        return (arr);
    if (n == 1)
    {
        arr[0] = 1;
        return (arr);
    }
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 1] + 2 * arr[i - 2];
    }
    return (arr);
}
void split_deque_into_pairs(std::deque<int>& d, size_t size)
{
    //print d 
    // std::cout << "d : ";
    // for (std::deque<int>::iterator it = d.begin(); it != d.end(); it++)
    //     std::cout << *it << " ";
    std::cout << "d.size :" << d.size() << std::endl;
    if (d.size() < size * 2)
        return;
    std::deque<std::pair<std::deque<int>, std::deque<int> > > pairs;
    std::deque<int> tmp;
    if (d.size() % (size * 2) != 0)
    {
        for (size_t i = d.size() - (d.size() % (size * 2)); i < d.size(); i++)
            tmp.push_back(d[i]);
        d.erase(d.end() - (d.size() % (size * 2)), d.end());
        std::cout << std::endl;
    }
    for (size_t i = 0; i < d.size(); i += size * 2)
    {
        std::deque<int> first_deque;
        std::deque<int> second_deque;
        if (d.size() - i < size * 2)
        {
            for (size_t j = i; j < d.size(); j++)
            {
                if (j < i + size)
                    first_deque.push_back(d[j]);
                else
                    second_deque.push_back(d[j]);
            }
        }
        else
        {
            for (size_t j = i; j < i + size; j++)
                first_deque.push_back(d[j]);
            for (size_t j = i + size; j < i + size * 2; j++)
                second_deque.push_back(d[j]);
            comp++;
            if (first_deque.back() > second_deque.back())
            {
                std::swap(first_deque, second_deque);
            }
        }
        pairs.push_back(std::make_pair(first_deque, second_deque));
    }
    d.clear();
    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::deque<int>& first_subdeque = pairs[i].first;
        std::deque<int>& second_subdeque = pairs[i].second;
        for (size_t j = 0; j < size; j++)
            d.push_back(first_subdeque[j]);
        for (size_t j = 0; j < size; j++)
            d.push_back(second_subdeque[j]);
    }
    std::cout << "size : " << size << std::endl;
    split_deque_into_pairs(d, size * 2);
    pairs.clear();
    // std::deque<std::deque<int> > main_chain;
    // std::deque<std::deque<int> > pend_chain;
    // for (size_t i = 0; i < d.size(); i += size * 2)
    // {
    //     if (size > d.size() - i)
    //     {
    //         std::deque<int> first_deque;
    //         std::deque<int> second_deque;
    //         for (size_t j = i; j < d.size(); j++)
    //         {
    //             if (j < i + size)
    //                 first_deque.push_back(d[j]);
    //             else
    //                 second_deque.push_back(d[j]);
    //         }
    //         pairs.push_back(std::make_pair(first_deque, second_deque));
    //     }
    //     else
    //     {
    //         std::deque<int> first_deque;
    //         std::deque<int> second_deque;
    //         for (size_t j = i; j < i + size; j++)
    //             first_deque.push_back(d[j]);
    //         for (size_t j = i + size; j < i + size * 2; j++)
    //             second_deque.push_back(d[j]);
    //         pairs.push_back(std::make_pair(first_deque, second_deque));
    //     }
    //     main_chain.push_back(pairs.back().second);
    //     pend_chain.push_back(pairs.back().first);
    // }
    // if(!tmp.empty())
    //     pend_chain.push_back(tmp);
    // for (std::deque<std::deque<int> >::iterator p_it = pend_chain.begin(); p_it != pend_chain.end(); ++p_it)
    // {
    //     std::deque<std::deque<int> >::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), *p_it, Compare);
    //     main_chain.insert(it, *p_it);
    // }
    // d.clear();
    // for (std::deque<std::deque<int> >::iterator it = main_chain.begin(); it != main_chain.end(); ++it)
    //     d.insert(d.end(), it->begin(), it->end());
}


int main (int ac, char **av)
{
	std::deque<int> d;
	std::deque<std::pair<std::deque<int>, std::deque<int> > > pairs;

	if (ac < 2)
	{
		std::cout << "Error : please give me a list of integers pleaaaseee" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++)
		d.push_back(atoi(av[i]));
	std::cout << "before : ";
	for (std::deque<int>::iterator it = d.begin(); it != d.end(); it++)
		std::cout << *it << " ";
	// std::cout << std::endl;
	split_deque_into_pairs(d, 1);
    std::cout << "after : ";
    for (std::deque<int>::iterator it = d.begin(); it != d.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
	std::cout << "\ncomp : " << comp << std::endl;
	return (0);
}