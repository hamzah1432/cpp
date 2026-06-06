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
#include <ostream>
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
// 2. handle* Methods for Each Type
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


    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << ".0f" << std::endl;
    std::cout << "double: " << d << ".0" << std::endl;
}

void TypeHandler::handleInt(const std::string &literal)
{
    double val = std::strtod(literal.c_str(), NULL);

    if (val < 0 || val > 127 || val == HUGE_VAL || val == -HUGE_VAL) 
    {
        std::cout << "char: impossible" << std::endl;
    }
    else
    {
        char c = static_cast<char>(val);
        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }

    if (val < INT_MIN || val > INT_MAX || val == HUGE_VAL || val == -HUGE_VAL)
    {
        std::cout << "int: impossible" << std::endl; 
    }
    else
    {
        int i = static_cast<int>(val);
        std::cout << "int: " << i << std::endl;
    }

    if (val == HUGE_VAL || val == -HUGE_VAL || val > FLT_MAX || val < -FLT_MAX)
    {
        std::cout << "float: impossible" << std::endl;
    }
    else
    {
        float f = static_cast<float>(val);
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    }

    if (val == HUGE_VAL || val == -HUGE_VAL)
    {
        std::cout << "double: impossible" << std::endl;
    }
    else
    {
        double d = static_cast<double>(val);
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    }
}

void TypeHandler::handleFloat(const std::string &literal)
{
    double val = std::strtod(literal.c_str(), NULL);
    float f = static_cast<float>(val);
    double d = static_cast<double>(f);

    if (val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else
    {
        char c = static_cast<char>(val);
        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }

    if (val < INT_MIN || val > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;

    std::cout << "float: " << f;
    if (f == static_cast<long>(f))
        std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: " << d;
    if (d == static_cast<long>(d))
        std::cout << ".0";
    std::cout << std::endl;
}

void TypeHandler::handleDouble(const std::string &literal)
{
    double d = std::strtod(literal.c_str(), NULL);
    float f = static_cast<float>(d);

    if (d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else
    {
        char c = static_cast<char>(d);
        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }

    if (d < INT_MIN || d > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    std::cout << "float: " << f;
    if (f == static_cast<long>(f))
        std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: " << d;
    if (d == static_cast<long>(d))
        std::cout << ".0";
    std::cout << std::endl;
}