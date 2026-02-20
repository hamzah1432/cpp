/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 05:07:53 by halmuhis          #+#    #+#             */
/*   Updated: 2026/02/20 00:28:32 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation Form", "default_target", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shrubbery Creation Form", target, 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    if (this != &src)
    {
        AForm::operator=(src);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::executeAction() const
{
    std::string filename = this->getTarget() + "_shrubbery";

    std::ofstream outfile(filename.c_str());

    if (!outfile.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    outfile << "       .     .  .      +     .      .          ." << std::endl;
    outfile << "     .       .      .   \"#\"       .           ." << std::endl;
    outfile << "        .      .       \"###\"           .      .      ." << std::endl;
    outfile << "      .      .   \"#:. .:##\"##:. .:#\"  .      ." << std::endl;
    outfile << "          .      . \"####\"###\"####\"  ." << std::endl;
    outfile << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ." << std::endl;
    outfile << "  .             \"#########\"#########\"        .        ." << std::endl;
    outfile << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       ." << std::endl;
    outfile << "     .     .  \"#######\"\"##\"##\"\"#######\"                  ." << std::endl;
    outfile << "                .\"##\"#####\"#####\"##\"           .      ." << std::endl;
    outfile << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     ." << std::endl;
    outfile << "      .     \"#######\"##\"#####\"##\"#######\"      .     ." << std::endl;
    outfile << "    .    .     \"#####\"\"#######\"\"#####\"    .      ." << std::endl;
    outfile << "            .           \"000\"    .     ." << std::endl;
    outfile << "       .         .   .  \"000\"   .        .       ." << std::endl;
    outfile << ".. .. ..................O000O........................ ...... ..." << std::endl;

    outfile.close();
}