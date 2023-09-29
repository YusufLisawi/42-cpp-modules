/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:52:50 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/29 12:39:39 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./convert [value]" << std::endl;
        return 1;
    }
    try {
        ScalarConverter::convert(argv[1]);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}