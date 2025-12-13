/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:54:44 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/13 14:41:49 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
	std::cout << "--- Testing FragTrap Constructors ---" << std::endl;
	
	FragTrap frag1;
	FragTrap frag2("NO ONE");

	std::cout << "\n--- Testing Stats & Inheritance ---" << std::endl;
	frag2.attack("Wall"); 

	frag2.takeDamage(20);
	frag2.beRepaired(10);

	std::cout << "\n--- Testing Special Ability (High Fives) ---" << std::endl;
	
	frag1.highFivesGuys();
	frag2.highFivesGuys();

	std::cout << "\n--- Testing Destructors ---" << std::endl;
	
	return 0;
}