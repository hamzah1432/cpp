/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 00:07:22 by halmuhis          #+#    #+#             */
/*   Updated: 2026/02/20 00:10:12 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>


RobotomyRequestForm::RobotomyRequestForm()
: AForm("Robotomy Request Form", "default_target", 72, 45){}


RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("Robotomy Request Form", target, 72, 45){}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src){}


RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    if (this != &src)
    {
        AForm::operator=(src);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}


void RobotomyRequestForm::executeAction() const
{
    std::cout << "* Vrrrrr... Bzzzzzt... Bzzzzzt... (drilling noises) *" << std::endl;

    if (std::rand() % 2 == 0)
        std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "The robotomy failed on " << this->getTarget() << "." << std::endl;
}