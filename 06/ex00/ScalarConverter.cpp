/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:32:51 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/27 21:09:00 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char ScalarConverter::type = '\0';

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
    char    *endPtr;
    
    strtod(str.c_str(), &endPtr);
    // if (*endPtr != '\0' && str.length() == 1)
    // {
    //     str = static_cast<int>(str[0]);
    //     std::cout << "char: '" << str << "'" << std::endl;  
    // }
    if (*endPtr != '\0' && str[str.length() - 1] == 'f')
        str.erase(str.length() - 1);

    std::cout << std::fixed << std::setprecision((str.find('.') != std::string::npos) ? str.length() - str.find('.') - 1 : 1);
    printChar(str);
    printInt(str);
    printFloat(str);
    // printDouble(str);
}