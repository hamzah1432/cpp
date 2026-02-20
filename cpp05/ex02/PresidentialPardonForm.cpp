/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 00:24:35 by halmuhis          #+#    #+#             */
/*   Updated: 2026/02/20 00:24:48 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Presidential Pardon Form", "default_target", 25, 5) 
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
    : AForm("Presidential Pardon Form", target, 25, 5) 
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) 
    : AForm(src) 
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    if (this != &src)
    {
        AForm::operator=(src);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() 
{
}

void PresidentialPardonForm::executeAction() const
{
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}