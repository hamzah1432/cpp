/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeHandler.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhesn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 09:27:30 by halmuhis          #+#    #+#             */
/*   Updated: 2026/05/31 10:10:54 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEHANDLER_HPP
# define TYPEHANDLER_HPP

#include <string>

class TypeHandler {
private:
    TypeHandler();
    TypeHandler(const TypeHandler &other);
    TypeHandler &operator=(const TypeHandler &other);
    ~TypeHandler();

    static void printFloating(double value, bool isFloatType, int prec);

public:
    static void handlePseudo(const std::string &literal);
    static void handleChar(const std::string &literal);
    static void handleInt(const std::string &literal);
    static void handleFloat(const std::string &literal);
    static void handleDouble(const std::string &literal);
    static void handleImpossible();
};

#endif