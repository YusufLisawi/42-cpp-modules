/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:49:23 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/13 16:52:59 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

class BitcoinExchange 
{
private:
    std::map<std::string, double> data;
public:
    BitcoinExchange();
    BitcoinExchange(std::string datafile);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void exchange(std::string inputfile);
    void handleExchange(std::string date, std::string value);

    void readData(std::ifstream &fileData);

    bool checkDateValidity(std::string date);
    bool checkDatePattern(std::string date);
    bool checkMonthLimit(std::string year, std::string month, std::string day);
};

