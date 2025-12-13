/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:54:44 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/13 14:41:28 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include "ScavTrap.hpp"

int main() {
	std::cout << "--- Testing ScavTrap Constructors ---" << std::endl;
	
	ScavTrap scav1;
	ScavTrap scav2("Guardian");

	std::cout << "\n--- Testing Special ScavTrap Actions ---" << std::endl;
	
	scav1.attack("No One");
	scav2.guardGate();

	std::cout << "\n--- Testing Polymorphism/Inheritance ---" << std::endl;
	scav2.takeDamage(50);
	scav2.beRepaired(20);

	std::cout << "\n--- Testing Destructors (Watch the Order!) ---" << std::endl;
	
	return 0;
}