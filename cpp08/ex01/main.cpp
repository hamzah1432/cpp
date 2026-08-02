/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhesn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 15:49:58 by halmuhis          #+#    #+#             */
/*   Updated: 2026/07/07 17:41:05 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Iter.hpp"

template <typename T>
void printElement(const T &element) {
    std::cout << element << " ";
}

void increment(int &n) {
    n++;
}

int main() {
    std::cout << "--- Test 1: Array of Integers ---" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    std::size_t intArrayLen = 5;

    std::cout << "Original: ";
    ::iter(intArray, intArrayLen, printElement<int>);
    std::cout << std::endl;

    ::iter(intArray, intArrayLen, increment);

    std::cout << "After increment: ";
    ::iter(intArray, intArrayLen, printElement<int>);
    std::cout << std::endl << std::endl;


    std::cout << "--- Test 2: Const Array of Strings ---" << std::endl;
    const std::string strArray[] = {"Hello", "42", "Templates!"};
    std::size_t strArrayLen = 3;

    std::cout << "Strings: ";
    ::iter(strArray, strArrayLen, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}