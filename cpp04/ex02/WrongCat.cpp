/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:23:47 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/11 12:40:34 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    _type = "WrongCat";
    std::cout << "[WrongCat] Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "[WrongCat] Copy Constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other)
        WrongAnimal::operator=(other);
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "[WrongCat] Destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "WrongCat: Meow (but you won't hear this from a pointer!)" << std::endl;
}