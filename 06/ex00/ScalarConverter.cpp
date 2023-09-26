/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:32:51 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/26 21:34:42 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    // std::cout << "Constructor called for ScalarConverter"<< std::endl;
}

ScalarConverter::~ScalarConverter() {
    // std::cout << "Destructor called for ScalarConverter"<< std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    // std::cout << "Copy constructor called for ScalarConverter"<< std::endl;
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    // std::cout << "Assignment operator called for ScalarConverter" << std::endl;
    if (this != &other) {
        // Copy data here
    }
    return *this;
}

void    ScalarConverter::convert(std::string str)
{
    std::cout << "char: ";
    try
    {
        char c = static_cast<char>(std::stoi(str));
        if (c < 32 || c > 126)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << c << "'" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "impossible" << std::endl;
    }

    std::cout << "int: ";
    try
    {
        int i = static_cast<int>(std::stoi(str));
        std::cout << i << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "impossible" << std::endl;
    }

    std::cout << "float: ";
    try
    {
        float f = static_cast<float>(std::stof(str));
        std::cout << f << "f" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "impossible" << std::endl;
    }

    std::cout << "double: ";
    try
    {
        double d = static_cast<double>(std::stod(str));
        std::cout << d << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "impossible" << std::endl;
    }

}