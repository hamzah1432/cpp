/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:42:48 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/03 12:28:30 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) {
    this->name = name;
    std::cout << "Zombie " << this->name << " has been created." << std::endl;
}

Zombie::Zombie() {}

void Zombie::setName(std::string new_name) {
    this->name = new_name;
}

Zombie::~Zombie() {
    std::cout << this->name << " has been destroyed." << std::endl;
}

void Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}