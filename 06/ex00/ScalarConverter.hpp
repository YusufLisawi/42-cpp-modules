/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:32:55 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/29 12:37:22 by yelaissa         ###   ########.fr       */
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
    static void printChar(double d);
    static void printInt(double d);
    static void printFloat(double d);
    static void printDouble(double d);
public:
    static void convert(std::string str);

    class ImpossibleException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

#endif
