/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:15:21 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/13 15:55:22 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
    _type = "Dog";
    _brain = new Brain();
    std::cout << "[Dog] Default Constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "[Dog] Copy Constructor called" << std::endl;
    _brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "[Dog] Copy Assignment Operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

Dog::~Dog() {
    delete _brain;
    std::cout << "[Dog] Destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Dog: Woof! Woof!" << std::endl;
}

const std::string& Dog::getIdea(int index) const {
    return _brain->getIdea(index);
}

void Dog::setIdea(int index, const std::string& idea) {
    _brain->setIdea(index, idea);
}