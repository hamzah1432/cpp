/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeHandler.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhesn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 09:28:38 by halmuhis          #+#    #+#             */
/*   Updated: 2026/05/31 10:10:32 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeHandler.hpp"
#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <cmath>
#include <cfloat>

// =============================================================================
// 1. Orthodox Canonical Form
// =============================================================================

TypeHandler::TypeHandler() {}

TypeHandler::TypeHandler(const TypeHandler &other) {
    (void)other;
}

TypeHandler &TypeHandler::operator=(const TypeHandler &other) {
    (void)other;
    return *this;
}

TypeHandler::~TypeHandler() {}

// =============================================================================
// 2. Helper: print a float/double value. Whole numbers are shown as "N.0"
//    (no scientific notation), fractional values keep their natural precision.
// =============================================================================

void TypeHandler::printFloating(double value, bool isFloatType)
{
    std::cout << (isFloatType ? "float: " : "double: ");

    if (value == 0.0)
        value = 0.0; // normalize negative zero

    if (value == std::floor(value))
        std::cout << std::fixed << std::setprecision(1) << value;
    else
    {
        std::cout.unsetf(std::ios::floatfield);
        std::cout << std::setprecision(6) << value;
    }

    if (isFloatType)
        std::cout << "f";
    std::cout << std::endl;

    // restore default stream formatting for the next line
    std::cout.unsetf(std::ios::floatfield);
    std::cout << std::setprecision(6);
}

// =============================================================================
// 3. handle* Methods for Each Type
// =============================================================================

void TypeHandler::handlePseudo(const std::string &literal)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (literal == "inf" || literal == "+inf" || literal == "inff" || literal == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void TypeHandler::handleChar(const std::string &literal)
{
    char c = literal[0];

    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    printFloating(static_cast<float>(c), true);
    printFloating(static_cast<double>(c), false);
}

void TypeHandler::handleInt(const std::string &literal)
{
    double val = std::strtod(literal.c_str(), NULL);

    if (val < 0 || val > 127 || val == HUGE_VAL || val == -HUGE_VAL)
        std::cout << "char: impossible" << std::endl;
    else
    {
        char c = static_cast<char>(val);
        if (std::isprint(static_cast<unsigned char>(c)))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }

    if (val < INT_MIN || val > INT_MAX || val == HUGE_VAL || val == -HUGE_VAL)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;

    if (val == HUGE_VAL || val == -HUGE_VAL || val > FLT_MAX || val < -FLT_MAX)
        std::cout << "float: impossible" << std::endl;
    else
        printFloating(static_cast<float>(val), true);

    if (val == HUGE_VAL || val == -HUGE_VAL)
        std::cout << "double: impossible" << std::endl;
    else
        printFloating(val, false);
}

void TypeHandler::handleFloat(const std::string &literal)
{
    double val = std::strtod(literal.c_str(), NULL);
    float f = static_cast<float>(val);

    if (val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else
    {
        char c = static_cast<char>(val);
        if (std::isprint(static_cast<unsigned char>(c)))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }

    if (val < INT_MIN || val > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;

    printFloating(f, true);
    printFloating(static_cast<double>(f), false);
}

void TypeHandler::handleDouble(const std::string &literal)
{
    double d = std::strtod(literal.c_str(), NULL);

    if (d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else
    {
        char c = static_cast<char>(d);
        if (std::isprint(static_cast<unsigned char>(c)))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }

    if (d < INT_MIN || d > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    printFloating(static_cast<float>(d), true);
    printFloating(d, false);
}

void TypeHandler::handleImpossible()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}
