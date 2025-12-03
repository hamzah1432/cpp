/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:54:44 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/03 12:08:09 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main() {
    std::cout << "--- Testing Stack Allocation (randomChump) ---" << std::endl;
    randomChump("Stacky");
    std::cout << "--- randomChump finished. Stack Zombie is gone. ---" << std::endl;
    
    std::cout << "\n--- Testing Heap Allocation (newZombie) ---" << std::endl;
    Zombie* heapZombie = newZombie("Heapy");
    heapZombie->announce();
    delete heapZombie;
    std::cout << "--- Heap Zombies deleted. Program finished. ---" << std::endl;
    
    return 0; 
}