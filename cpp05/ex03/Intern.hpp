/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:36:34 by halmuhis          #+#    #+#             */
/*   Updated: 2026/02/20 16:37:39 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern {
public:
    Intern();
    Intern(const Intern &src);
    Intern &operator=(const Intern &src);
    ~Intern();

    AForm* makeForm(std::string formName, std::string target);

private:
    AForm* createShrubbery(std::string target);
    AForm* createRobotomy(std::string target);
    AForm* createPresidential(std::string target);
};

#endif