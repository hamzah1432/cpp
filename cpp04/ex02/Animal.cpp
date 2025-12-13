/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:11:54 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/13 19:17:09 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
    std::cout << "[Animal] Default Constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
    std::cout << "[Animal] Copy Constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "[Animal] Copy Assignment Operator called" << std::endl;
    if (this != &other) {
        this->_type = other._type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "[Animal] Destructor called" << std::endl;
}

std::string Animal::getType() const {
    return this->_type;
}