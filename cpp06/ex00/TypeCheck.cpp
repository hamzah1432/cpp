/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeCheck.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhesn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 09:21:30 by halmuhis          #+#    #+#             */
/*   Updated: 2026/05/31 09:25:01 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeCheck.hpp"

// =============================================================================
// 1. Orthodox Canonical Form
// =============================================================================

TypeCheck::TypeCheck() {}

TypeCheck::TypeCheck(const TypeCheck &other) {
    (void)other;
}

TypeCheck &TypeCheck::operator=(const TypeCheck &other) {
    (void)other;
    return *this;
}

TypeCheck::~TypeCheck() {}


// =============================================================================
// 2. Static Checker Methods
// =============================================================================


bool TypeCheck::isPseudoLiteral(const std::string &literal)
{
    return (literal == "nan"   || literal == "nanf"  ||
            literal == "inf"   || literal == "+inf"  || literal == "-inf" ||
            literal == "inff"  || literal == "+inff" || literal == "-inff");
}

bool TypeCheck::isChar(const std::string &literal)
{
    return (literal.length() == 1 && !std::isdigit(literal[0]));
}

bool TypeCheck::isInt(const std::string &literal)
{
    if (literal.empty())
        return false;

    size_t start = 0;

    if (literal[0] == '-' || literal[0] == '+')
    {
        if (literal.length() == 1)
            return false;
        start = 1;
    }

    return (literal.find_first_not_of("0123456789", start) == std::string::npos);
}

bool TypeCheck::isFloat(const std::string &literal)
{
    if (literal.empty())
        return false;

    char lastChar = literal[literal.length() - 1];
    if (lastChar != 'f' && lastChar != 'F')
        return false;

    size_t start = 0;
    
    if (literal[0] == '-' || literal[0] == '+')
    {
        start = 1;
    }

    size_t firstDot = literal.find('.');
    size_t lastDot = literal.rfind('.');
    
    if (firstDot == std::string::npos || firstDot != lastDot)
        return false;

    if (literal.length() - start == 2 && literal[start] == '.')
        return false;

    return (literal.find_first_not_of("0123456789.", start) == literal.length() - 1);
}

bool TypeCheck::isDouble(const std::string &literal)
{
    if (literal.empty())
        return false;

    if (literal[literal.length() - 1] == 'f' || literal[literal.length() - 1] == 'F')
        return false;

    size_t start = 0;
    
    if (literal[0] == '-' || literal[0] == '+')
    {
        if (literal.length() == 1)
            return false;
        start = 1;
    }

    size_t firstDot = literal.find('.');
    size_t lastDot = literal.rfind('.');
    
    if (firstDot == std::string::npos || firstDot != lastDot)
        return false;

    if (literal.length() - start == 1 && literal[start] == '.')
        return false;

    return (literal.find_first_not_of("0123456789.", start) == std::string::npos);
}