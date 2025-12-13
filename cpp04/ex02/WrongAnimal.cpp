/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:22:58 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/11 12:23:26 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
    std::cout << "[WrongAnimal] Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other)
        _type = other._type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "[WrongAnimal] Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal: *weird wrong noise*" << std::endl;
}

std::string WrongAnimal::getType() const {
    return _type;
}