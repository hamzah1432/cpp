/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeCheck.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhesn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 09:19:15 by halmuhis          #+#    #+#             */
/*   Updated: 2026/05/31 09:22:22 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPECHECK_HPP
# define TYPECHECK_HPP

# include <string>

class TypeCheck {
private:
    TypeCheck();
    TypeCheck(const TypeCheck &other);
    TypeCheck &operator=(const TypeCheck &other);
    ~TypeCheck();
    
public:
    static bool isPseudoLiteral(const std::string &literal);
    static bool isChar(const std::string &literal);
    static bool isInt(const std::string &literal);
    static bool isFloat(const std::string &literal);
    static bool isDouble(const std::string &literal);

};

#endif