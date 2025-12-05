/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 08:19:38 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/05 18:56:46 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int main() {
    // Create the Harl object
    Harl harl;
    
    // Array of test cases including valid and invalid levels
    std::string testLevels[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR",
        "INFO",
        "debug"
    };

    std::cout << "--- Testing Harl's Complain Function ---" << std::endl;
    std::cout << "--- (Using Pointers to Member Functions) ---" << std::endl;
    
    for (unsigned long i = 0; i < (sizeof(testLevels) / sizeof(testLevels[0])); ++i) {
        std::cout << "\n========================================" << std::endl;
        std::cout << "Attempting to complain at level: " << testLevels[i] << std::endl;
        std::cout << "========================================" << std::endl;

        harl.complain(testLevels[i]);
    }

    std::cout << "\n--- Testing Finished ---" << std::endl;
    return 0;
}