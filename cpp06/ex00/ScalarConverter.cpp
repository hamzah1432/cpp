/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhesn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:14:34 by halmuhis          #+#    #+#             */
/*   Updated: 2026/05/30 17:14:34 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "TypeHandler.hpp"
#include "TypeCheck.hpp"

#include <cctype>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <cmath>
#include <cfloat>

// =============================================================================
// 1. Orthodox Canonical Form
// =============================================================================

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

// =============================================================================
// 2. Public Core Method
// =============================================================================

void ScalarConverter::convert(const std::string &literal)
{
    if (TypeCheck::isPseudoLiteral(literal))
    {
        TypeHandler::handlePseudo(literal);
    }
    else if (TypeCheck::isChar(literal))
    {
        TypeHandler::handleChar(literal);
    }
    else if (TypeCheck::isInt(literal))
    {
        TypeHandler::handleInt(literal);
    }
    else if (TypeCheck::isFloat(literal))
    {
       TypeHandler::handleFloat(literal);
    }
    else if (TypeCheck::isDouble(literal))
    {
       TypeHandler::handleDouble(literal);
    }
    else
    {
        TypeHandler::handleImpossible();
    }
}