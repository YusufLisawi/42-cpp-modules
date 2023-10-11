/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:09:30 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/11 16:29:56 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <iterator>

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
    typename T::iterator ptr = std::find(container.begin(), container.end(), n);

    if (ptr == container.end())
        throw std::exception();
    return ptr;
}