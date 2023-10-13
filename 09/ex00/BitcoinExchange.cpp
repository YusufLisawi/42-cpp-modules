/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:49:32 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/13 16:52:48 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : data()
{
    // std::cout << "Constructor called for BitcoinExchange"<< std::endl;
}

BitcoinExchange::BitcoinExchange(std::string datafile)
{
    // std::cout << "Constructor called for BitcoinExchange"<< std::endl;
    std::ifstream fileData(datafile);
    if (!fileData.is_open())
    {
        std::cerr << "Error: could not open data file." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    try
    {
        readData(fileData);
        fileData.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        fileData.close();
        std::exit(EXIT_FAILURE);
    }
}

BitcoinExchange::~BitcoinExchange() {
    // std::cout << "Destructor called for BitcoinExchange"<< std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    // std::cout << "Copy constructor called for BitcoinExchange"<< std::endl;
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    // std::cout << "Assignment operator called for BitcoinExchange" << std::endl;
    if (this != &other)
    {
        this->data = other.data;
    }
    return *this;
}

void BitcoinExchange::exchange(std::string inputfile)
{
    std::ifstream fileInput(inputfile);
    if (!fileInput.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    std::getline(fileInput, line);
    if (line != "date | value")
        throw std::invalid_argument("Error: Invalid input file, invalid header");
    while (std::getline(fileInput, line))
    {
        std::string date = line.substr(0, line.find('|'));
        std::string value = line.substr(line.find('|') + 1);
        
        try
        {
            handleExchange(date, value);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    fileInput.close();
}

void BitcoinExchange::handleExchange(std::string date, std::string value)
{
    date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
    value.erase(std::remove(value.begin(), value.end(), ' '), value.end());

    if (date.empty() || value.empty())
        throw std::invalid_argument("Error: Invalid input file");
    
    std::map<std::string, double>::iterator itData = data.lower_bound(date);
    if (itData == data.end() || itData->first != date)
    {
        if (itData == data.begin())
            throw std::invalid_argument("Error: bad input => " + date);
        itData--;
    }
    
    char *end;
    double d;
    d = std::strtod(value.c_str(), &end);
    if (*end != '\0')
        throw std::invalid_argument("Error: bad input => " + value);

    if (d < 0)
        throw std::invalid_argument("Error: not a positive number.");

    if (d > INT_MAX || d > 1000)
        throw std::invalid_argument("Error: too large a number.");

    double res = d * itData->second;
    std::cout << itData->first << " => " << d << " = " << res << std::endl;
}


void BitcoinExchange::readData(std::ifstream &fileData)
{
    std::string line;
    std::getline(fileData, line);
    if (line != "date,exchange_rate")
        throw std::invalid_argument("Error: Invalid data file, invalid header");
    while (std::getline(fileData, line))
    {
        std::string date = line.substr(0, line.find(','));
        std::string value = line.substr(line.find(',') + 1);

        if (date.empty() || value.empty())
            throw std::invalid_argument("Error: Invalid data file");

        if (data.find(date) != data.end())
            throw std::invalid_argument("Error: Invalid data file, duplicate date => " + date);

        char *end;
        double d;
        d = std::strtod(value.c_str(), &end);
        if (*end != '\0' || d < 0)
            throw std::invalid_argument("Error: Invalid data file, invalid value => " + value);

        if (!checkDateValidity(date))
            throw std::invalid_argument("Error: bad data => " + date);
        data[date] = d;
    }
}

bool BitcoinExchange::checkDateValidity(std::string date)
{
    if (!checkDatePattern(date))
        return false;
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);
    if (!checkMonthLimit(year, month, day))
        return false;
    if (year < "2009" || (year == "2009" && (month < "01" || (month == "01" && day < "02"))))
        return false;
    if (month < "01" || month > "12")
        return false;
    if (day < "01" || day > "31")
        return false;
    return true;
}

bool BitcoinExchange::checkDatePattern(std::string date)
{
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; i++)
    {
        if (i != 4 && i != 7 && !std::isdigit(date[i]))
            return false;
    }
    return true;
}

bool BitcoinExchange::checkMonthLimit(std::string year, std::string month, std::string day)
{
    int y = std::atoi(year.c_str());
    if (month == "02" && y % 4 == 0)
    {
        if (y % 100 != 0 || (y % 100 == 0 && y % 400 == 0))
        {
            if (day > "29")
                return false;
        }
    }
    else if (month == "02" && day > "28")
        return false;
    else if ((month == "04" || month == "06" || month == "09" || month == "11") && day > "30")
        return false;
    return true;
}
