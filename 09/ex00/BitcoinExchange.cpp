/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:49:32 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/12 15:19:21 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : data(), input()
{
    // std::cout << "Constructor called for BitcoinExchange"<< std::endl;
}

BitcoinExchange::BitcoinExchange(std::string datafile, std::string inputfile)
{
    // std::cout << "Constructor called for BitcoinExchange"<< std::endl;
    fileData.open(datafile);
    if (!fileData.is_open())
    {
        throw std::invalid_argument("Error: Invalid data file");
    }
    try
    {
        readData();
    }
    catch (const std::exception &e)
    {
        throw std::invalid_argument("Error: Invalid data file");
    }
    (void)inputfile;
}

BitcoinExchange::~BitcoinExchange()
{
    fileData.close();
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
        this->input = other.input;
    }
    return *this;
}

void BitcoinExchange::readData()
{
    std::string line;
    std::getline(fileData, line);
    if (line != "date,exchange_rate")
    {
        throw std::invalid_argument("Error: Invalid data file, invalid header");
    }
    while (std::getline(fileData, line))
    {
        std::string date = line.substr(0, line.find(','));
        std::string value = line.substr(line.find(',') + 1);
        if (date.empty() || value.empty())
        {
            throw std::invalid_argument("Error: Invalid data file");
        }
        if (data.find(date) != data.end())
        {
            throw std::invalid_argument("Error: Invalid data file, duplicate date");
        }
        char *end;
        double d;
        try
        {
            d = std::strtod(value.c_str(), &end);
            if (*end != '\0' || d < 0)
            {
                throw std::invalid_argument("Error: Invalid data file, invalid value");
            }
        }
        catch (const std::exception &e)
        {
            throw std::invalid_argument("Error: Invalid data file, invalid value");
        }
        if (!checkDateValidity(date))
        {
            throw std::invalid_argument("Error: Invalid data file, invalid date");
        }
        data[date] = d;
    }
}

bool BitcoinExchange::checkDateValidity(std::string date)
{
    try
    {
        checkDatePattern(date);
        std::string year = date.substr(0, 4);
        std::string month = date.substr(5, 2);
        std::string day = date.substr(8, 2);
        checkMonthLimit(year, month, day);
        if (year < "2009" || year > "2023" || (year == "2009" && (month < "01" || (month == "01" && day < "02"))))
            throw std::invalid_argument("Error: Invalid date, date should be between 2009-01-02 and 2023-12-31.");
        if (month < "01" || month > "12")
            throw std::invalid_argument("Error: Invalid date, month should be between 01 and 12.");
        if (day < "01" || day > "31")
            throw std::invalid_argument("Error: Invalid date, day should be between 01 and 31.");
        return true;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
        return false;
    }
}

void BitcoinExchange::checkDatePattern(std::string date)
{
    if (date.size() != 10)
        throw std::invalid_argument("Error: Invalid date format, date should be in the format YYYY-MM-DD.");
    if (date[4] != '-' || date[7] != '-')
        throw std::invalid_argument("Error: Invalid date format, date should be in the format YYYY-MM-DD.");
    for (int i = 0; i < 10; i++)
    {
        if (i != 4 && i != 7 && !std::isdigit(date[i]))
            throw std::invalid_argument("Error: Invalid date format, date should be in the format YYYY-MM-DD.");
    }
}

void BitcoinExchange::checkMonthLimit(std::string year, std::string month, std::string day)
{
    int y = std::atoi(year.c_str());
    if (month == "02" && y % 4 == 0)
    {
        if (y % 100 != 0 || (y % 100 == 0 && y % 400 == 0))
        {
            if (day > "29")
                throw std::invalid_argument("Error: Invalid date, February has only 29 days in leap years.");
        }
    }
    else if (month == "02" && day > "28")
        throw std::invalid_argument("Error: Invalid date, February has only 28 days in non-leap years.");
    else if ((month == "04" || month == "06" || month == "09" || month == "11") && day > "30")
        throw std::invalid_argument("Error: Invalid date, This month has only 30 days.");
}
