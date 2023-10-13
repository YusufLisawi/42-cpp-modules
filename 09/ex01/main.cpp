/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:06:34 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/13 15:21:41 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

std::vector<std::string> ft_split(const std::string &s, const std::string &delimiters)
{
    std::vector<std::string> splited;
    size_t i = 0;

    while (i < s.length())
    {
        i = s.find_first_not_of(delimiters, i);
        
        if (i == std::string::npos)
            break;
        size_t wordEnd = s.find_first_of(delimiters, i);
        
        splited.push_back(s.substr(i, wordEnd - i));
        
        i = wordEnd;
    }
    return splited;
}