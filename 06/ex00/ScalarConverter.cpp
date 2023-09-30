/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:32:51 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/30 16:07:02 by yelaissa         ###   ########.fr       */
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

const char *ScalarConverter::ImpossibleException::what() const throw()
{
    return "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible";
}

void    ScalarConverter::convert(std::string str)
{
    char    *endPtr;
    double  d;

    d = strtod(str.c_str(), &endPtr);  
    if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inf" || str == "-inf" || str == "-inf")
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : " << d << 'f' << std::endl;
		std::cout << "double : " << d << std::endl;
		return ;
	}
    
    if (*endPtr != '\0' && str.length() == 1)
        d = static_cast<double>(str[0]);
    else if (*endPtr != '\0' && str[str.length() - 1] == 'f')
        str.erase(str.length() - 1);

    if ((*endPtr != '\0' && str.length() == 1) \
        || (*endPtr != '\0' && str[str.length() - 1] == 'f') \
        || (*endPtr == '\0' && str.find('.') != std::string::npos) \
        || (*endPtr == '\0'))
    {
        std::cout << std::fixed << std::setprecision((str.find('.') != std::string::npos && str.find('.') != str.length() - 1) ? str.length() - str.find('.') - 1 : 1);
        printChar(d);
        printInt(d);
        printFloat(d);
        printDouble(d);
    }
    else
        throw ScalarConverter::ImpossibleException();
}

void ScalarConverter::printChar(double d)
{
    std::cout << "char: ";
    if (d >= 0 && d <= 127)
    {
        if (std::isprint(d))
            std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
}

void ScalarConverter::printInt(double d)
{
    std::cout << "int: ";
    if (d > INT_MAX || d < INT_MIN)
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(d);
    std::cout << std::endl;
}

void    ScalarConverter::printFloat(double d)
{
    std::cout << "float: ";
    if (d > FLT_MAX && d < FLT_MIN)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<float>(d) << "f" << std::endl;
}

void    ScalarConverter::printDouble(double d)
{
    std::cout << "double: " << d << std::endl;
}

