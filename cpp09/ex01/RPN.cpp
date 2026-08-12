/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhesn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 06:44:02 by halmuhis          #+#    #+#             */
/*   Updated: 2026/08/12 06:46:55 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype> 

// Orthodox Canonical Form
RPN::RPN() {}
RPN::RPN(const RPN& other) { *this = other; }
RPN& RPN::operator=(const RPN& other) { (void)other; return *this; }
RPN::~RPN() {}

bool RPN::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::applyOperation(char op, std::stack<long>& calcStack) {
    if (calcStack.size() < 2) {
        throw std::runtime_error("Error");
    }

    long right = calcStack.top();
    calcStack.pop();
    long left = calcStack.top();
    calcStack.pop();

    long result = 0;

    switch (op) {
        case '+': result = left + right; break;
        case '-': result = left - right; break;
        case '*': result = left * right; break;
        case '/': 
            if (right == 0) throw std::runtime_error("Error");
            result = left / right; 
            break;
    }

    calcStack.push(result);
}

void RPN::evaluate(const std::string& expression) {
    std::stack<long> calcStack;

    try {
        for (size_t i = 0; i < expression.length(); ++i) {
            char c = expression[i];

            if (c == ' ') {
                continue;
            } else if (isdigit(c)) {
                calcStack.push(c - '0');
            } else if (isOperator(c)) {
                applyOperation(c, calcStack);
            } else {
                throw std::runtime_error("Error");
            }
        }

        if (calcStack.size() != 1) {
            throw std::runtime_error("Error");
        }

        std::cout << calcStack.top() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}