/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:32:55 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/27 20:34:04 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cfloat>

class ScalarConverter 
{
private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
public:
    static void convert(std::string str);
    static char  type;
    static void printChar(std::string str);
    static void printInt(std::string str);
    static void printFloat(std::string str);
    static void printDouble(std::string str);
};

#endif
