/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:36:53 by halmuhis          #+#    #+#             */
/*   Updated: 2026/02/20 16:37:40 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &src) { (void)src; }

Intern &Intern::operator=(const Intern &src) {
    (void)src;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubbery(std::string target) { return new ShrubberyCreationForm(target); }
AForm* Intern::createRobotomy(std::string target) { return new RobotomyRequestForm(target); }
AForm* Intern::createPresidential(std::string target) { return new PresidentialPardonForm(target); }

AForm* Intern::makeForm(std::string formName, std::string target) {
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };


    AForm* (Intern::*formCreators[])(std::string) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(target); 
        }
    }

    std::cout << "Error: Intern cannot create form '" << formName << "' because it doesn't exist." << std::endl;
    return NULL;
}