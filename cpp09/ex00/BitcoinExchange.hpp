/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhesn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 04:11:56 by halmuhis          #+#    #+#             */
/*   Updated: 2026/08/12 05:47:55 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <exception>
#include <map>

class BitcoinExchange
{
public:
	static std::string isValidDate(std::string dateStr);
	static void processInputLine(const std::string &line, const std::map<std::string, float> &btcData);

	class NegativeNumberException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class TooLargeNumberException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class BadInputException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	static float isValidValue(std::string valStr);
	static bool isLeapYear(int year);
};

#endif