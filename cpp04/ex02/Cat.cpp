/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:22:01 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/13 15:58:16 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    _type = "Cat";
    _brain = new Brain();
    std::cout << "[Cat] Default Constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "[Cat] Copy Constructor called" << std::endl;
    _brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "[Cat] Copy Assignment Operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "[Cat] Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat: Meow! Meow!" << std::endl;
}

const std::string& Cat::getIdea(int index) const {
    return _brain->getIdea(index);
}

void Cat::setIdea(int index, const std::string& idea) {
    _brain->setIdea(index, idea);
}