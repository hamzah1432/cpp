/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhesn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 10:07:00 by halmuhis          #+#    #+#             */
/*   Updated: 2026/05/31 10:07:04 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    // التأكد من أن المستخدم مرر وسيطاً واحداً فقط للبرنامج (اسم البرنامج + المدخل)
    if (argc != 2)
    {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return (1);
    }

    // استدعاء دالة التحويل مباشرة دون الحاجة لإنشاء كائن (Object) لأن الدالة static
    ScalarConverter::convert(argv[1]);

    return (0);
}