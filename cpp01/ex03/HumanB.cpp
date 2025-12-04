/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:17:11 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/04 13:33:30 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
    : name(name) {}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack()
{
    if (this->weapon)
    {
        std::cout << this->name << " attacks with their "
                  << this->weapon->getType() << std::endl;
    }
    else
    {
        std::cout << this->name << " cannot attack because it is unarmed!" << std::endl;
    }
}