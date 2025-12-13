/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:54:44 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/13 14:41:29 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	std::cout << "--- Testing Constructors ---" << std::endl;
	
	ClapTrap bot1;
	ClapTrap bot2("Wall-E");
	ClapTrap bot3(bot2);

	std::cout << "\n--- Testing Basic Actions ---" << std::endl;
	
	bot1.attack("Door");
	bot2.attack("Rock");

	bot2.takeDamage(5);
	bot2.beRepaired(3);

	std::cout << "\n--- Testing Energy Depletion ---" << std::endl;
	for (int i = 0; i < 10; i++) {
		bot1.attack("Paper");
	}
	bot1.attack("No One");

	std::cout << "\n--- Testing Death ---" << std::endl;
	bot2.takeDamage(20);
	bot2.attack("Ghost Attack");
	std::cout << "\n--- Testing Destructors (End of Scope) ---" << std::endl;
	
	return 0;
}