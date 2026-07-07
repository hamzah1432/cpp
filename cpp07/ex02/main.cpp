/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhesn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 17:39:43 by halmuhis          #+#    #+#             */
/*   Updated: 2026/07/07 17:40:03 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "array.hpp"

int main()
{
    std::cout << "--- Test 1: Default Constructor & size() ---" << std::endl;
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;
    std::cout << std::endl;

    std::cout << "--- Test 2: Parameterized Constructor & Default Initialization ---" << std::endl;
    Array<int> intArray(5);
    std::cout << "Int array size: " << intArray.size() << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        std::cout << "intArray[" << i << "] = " << intArray[i] << " (Default initialized)" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 3: Modifying Elements using operator[] ---" << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        intArray[i] = (i + 1) * 10;
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 4: Deep Copy Constructor ---" << std::endl;
    Array<int> copyArray(intArray);
    std::cout << "Modifying copyArray[0] to 999..." << std::endl;
    copyArray[0] = 999;
    std::cout << "copyArray[0]: " << copyArray[0] << std::endl;
    std::cout << "intArray[0] : " << intArray[0] << " (Should remain 10 - Deep Copy Works!)" << std::endl;
    std::cout << std::endl;

    std::cout << "--- Test 5: Assignment Operator ---" << std::endl;
    Array<int> assignedArray = copyArray; // Using Assignment
    std::cout << "Modifying assignedArray[1] to 888..." << std::endl;
    assignedArray[1] = 888;
    std::cout << "assignedArray[1]: " << assignedArray[1] << std::endl;
    std::cout << "copyArray[1]    : " << copyArray[1] << " (Should remain 20 - Deep Copy Works!)" << std::endl;
    std::cout << std::endl;

    std::cout << "--- Test 6: Out of Bounds Exception ---" << std::endl;
    try
    {
        std::cout << "Trying to access index 5 in a 5-element array (Valid indices: 0-4)..." << std::endl;
        std::cout << intArray[5] << std::endl; // This should throw
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 7: Array with Strings ---" << std::endl;
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "42";
    stringArray[2] = "Network";
    for (unsigned int i = 0; i < stringArray.size(); i++)
    {
        std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
    }

    return 0;
}