/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:10:39 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/04 13:14:21 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
    : name(name), weapon(weapon) {}


void HumanA::attack()
{
    std::cout << this->name << " attacks with their " 
              << this->weapon.getType() << std::endl;
}