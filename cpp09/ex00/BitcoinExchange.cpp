/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhesn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 04:11:52 by halmuhis          #+#    #+#             */
/*   Updated: 2026/08/12 05:50:04 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    (void)other;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isLeapYear(int year)
{
    if (year % 4 != 0)
        return false;
    if (year % 100 != 0)
        return true;
    if (year % 400 != 0)
        return false;
    return true;
}

std::string BitcoinExchange::isValidDate(std::string dateStr)
{
    if (dateStr.length() != 10 || dateStr[4] != '-' || dateStr[7] != '-')
    {
        return "";
    }

    std::string yearStr = dateStr.substr(0, 4);
    std::string monthStr = dateStr.substr(5, 2);
    std::string dayStr = dateStr.substr(8, 2);

    for (size_t i = 0; i < yearStr.length(); i++)
    {
        if (!isdigit(yearStr[i]))
            return "";
    }
    for (size_t i = 0; i < monthStr.length(); i++)
    {
        if (!isdigit(monthStr[i]))
            return "";
    }
    for (size_t i = 0; i < dayStr.length(); i++)
    {
        if (!isdigit(dayStr[i]))
            return "";
    }

    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());

    if (year < 0)
        return "";
    if (month < 1 || month > 12)
        return "";
    if (day < 1 || day > 31)
        return "";

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(year))
    {
        daysInMonth[1] = 29;
    }

    if (day > daysInMonth[month - 1])
    {
        return "";
    }

    return dateStr;
}

const char *BitcoinExchange::NegativeNumberException::what() const throw()
{
    return "Error: not a positive number.";
}

const char *BitcoinExchange::TooLargeNumberException::what() const throw()
{
    return "Error: too large a number.";
}

const char *BitcoinExchange::BadInputException::what() const throw()
{
    return "Error: bad input.";
}

float BitcoinExchange::isValidValue(std::string valStr)
{
    if (valStr.empty())
    {
        throw BadInputException();
    }

    char *endPtr;
    double val = std::strtod(valStr.c_str(), &endPtr);

    if (*endPtr != '\0' && *endPtr != 'f')
    {
        throw BadInputException();
    }

    if (val < 0.0)
    {
        throw NegativeNumberException();
    }

    if (val > 1000.0)
    {
        throw TooLargeNumberException();
    }

    return static_cast<float>(val);
}

void BitcoinExchange::processInputLine(const std::string &line, const std::map<std::string, float> &btcData)
{
    size_t sepPos = line.find(" | ");
    if (sepPos == std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    std::string datePart = line.substr(0, sepPos);
    std::string valuePart = line.substr(sepPos + 3);

    std::string cleanDate = isValidDate(datePart);
    if (cleanDate.empty())
    {
        std::cerr << "Error: bad input => " << datePart << std::endl;
        return;
    }

    try
    {
        float value = isValidValue(valuePart);

        std::map<std::string, float>::const_iterator it = btcData.lower_bound(cleanDate);

        if (it != btcData.end() && it->first == cleanDate)
        {
            std::cout << cleanDate << " => " << value << " = " << (value * it->second) << std::endl;
        }
        else
        {
            if (it == btcData.begin())
            {
                std::cerr << "Error: no data available for date => " << cleanDate << std::endl;
            }
            else
            {
                --it;
                std::cout << cleanDate << " => " << value << " = " << (value * it->second) << std::endl;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}