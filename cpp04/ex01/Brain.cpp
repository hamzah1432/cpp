/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:15:44 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/12 19:17:55 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "[Brain] Default Constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "[Brain] Copy Constructor called" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "[Brain] Copy Assignment Operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            _ideas[i] = other._ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "[Brain] Destructor called" << std::endl;
}

const std::string& Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return _ideas[index];
    }
    static const std::string empty = "";
    return empty;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        _ideas[index] = idea;
    }
}