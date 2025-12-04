/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 08:56:30 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/04 09:11:54 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>
#include <string>

Weapon::Weapon(std::string initial_type) : type(initial_type) {}

const std::string& Weapon::getType() const {
    return this->type;
}

void Weapon::setType(std::string new_type) {
    this->type = new_type;
}