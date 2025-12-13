/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:11:54 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/11 12:43:05 by halmuhis         ###   ########.fr       */
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

void Animal::makeSound() const {
    std::cout << "Animal: *generic animal noise*" << std::endl;
}

std::string Animal::getType() const {
    return this->_type;
}