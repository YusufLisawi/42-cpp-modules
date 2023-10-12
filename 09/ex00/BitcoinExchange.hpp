/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:49:23 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/12 15:07:57 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange 
{
private:
    std::ifstream fileData;
    std::map<std::string, double> data;
    std::map<std::string, double> input;
public:
    BitcoinExchange();
    BitcoinExchange(std::string datafile, std::string inputfile);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void readData();

    bool checkDateValidity(std::string date);
    void checkDatePattern(std::string date);
    void checkMonthLimit(std::string year, std::string month, std::string day);
};

