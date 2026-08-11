/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhesn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 20:52:09 by halmuhis          #+#    #+#             */
/*   Updated: 2026/08/11 20:52:37 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>   
#include "Span.hpp"

int main()
{
    std::cout << "========================================" << std::endl;
    std::cout << "          MANDATORY SUBJECT TEST        " << std::endl;
    std::cout << "========================================" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n========================================" << std::endl;
    std::cout << "             EXCEPTION TESTS            " << std::endl;
    std::cout << "========================================" << std::endl;
    
    std::cout << "[Test 1: Adding past the limit]" << std::endl;
    try {
        Span emptySpan = Span(1);
        emptySpan.addNumber(42);
        std::cout << "Added 42 successfully." << std::endl;
        emptySpan.addNumber(43); 
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n[Test 2: Calculating with insufficient numbers]" << std::endl;
    try {
        Span smallSpan = Span(5);
        smallSpan.addNumber(100);
        smallSpan.shortestSpan(); 
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n========================================" << std::endl;
    std::cout << "    15,000 NUMBERS (ITERATOR RANGE)     " << std::endl;
    std::cout << "========================================" << std::endl;
    try {
        Span massiveSpan = Span(15000);
        std::vector<int> randomNumbers;
        
        std::srand(std::time(NULL));
        
        for (int i = 0; i < 15000; i++) {
            randomNumbers.push_back(std::rand());
        }
        
        massiveSpan.addNumbers(randomNumbers.begin(), randomNumbers.end());
        
        std::cout << "Successfully added " << randomNumbers.size() << " elements." << std::endl;
        std::cout << "Shortest Span: " << massiveSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span:  " << massiveSpan.longestSpan() << std::endl;
        
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}