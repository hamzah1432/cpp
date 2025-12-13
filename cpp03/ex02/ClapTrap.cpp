/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 22:50:48 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/13 14:41:27 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("CLAP-TP"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap Default Constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    std::cout << "ClapTrap Copy Constructor called" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "ClapTrap Copy Assignment Operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap Destructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap Parameterized Constructor called for " << _name << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " attacks " << target 
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " cannot attack (No energy or hit points left)!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {    
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
        return;
    }

    if (amount >= _hitPoints) {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " takes " << amount << " damage and dies!" << std::endl;
    } else {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount << " damage! Current HP: " << _hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        _energyPoints--;
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " repairs itself, recovering " << amount 
                  << " hit points! Current HP: " << _hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " cannot repair itself (No energy or hit points left)!" << std::endl;
    }
}