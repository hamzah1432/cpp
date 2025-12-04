/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:35:14 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/04 08:13:29 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

#define HORDE_SIZE 5

int main() {
    std::cout << "Creating a horde of " << HORDE_SIZE << " zombies named 'Hordie'..." << std::endl;
    Zombie* zombie_horde = zombieHorde(HORDE_SIZE, "Hordie");

    if (zombie_horde == NULL) {
        std::cerr << "Failed to create the zombie horde." << std::endl;
        return 1;
    }

    std::cout << "\n--- Zombies Announce Themselves ---" << std::endl;

    for (int i = 0; i < HORDE_SIZE; ++i) {
        zombie_horde[i].announce();
    }

    std::cout << "\n--- Destroying the Zombie Horde ---" << std::endl;

    delete[] zombie_horde; 
    zombie_horde = NULL;

    std::cout << "--- Horde successfully destroyed. ---" << std::endl;
    
    std::cout << "\n--- Testing Edge Case (N=0) ---" << std::endl;
    Zombie* null_horde = zombieHorde(0, "Invalid");
    if (null_horde == NULL) {
        std::cout << "zombieHorde handles N <= 0 correctly (returned NULL)." << std::endl;
    }

    return 0;
}