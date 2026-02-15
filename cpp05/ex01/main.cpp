/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:54:31 by halmuhis          #+#    #+#             */
/*   Updated: 2026/02/15 04:47:00 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RED "\033[1;31m"
#define RESET "\033[0m"
#define GREEN "\033[1;32m"

int main()
{
	std::cout << "Test 1: Form Construction" << std::endl;
	try
	{
		std::cout << "Attempting to create Form with grade 0..." << std::endl;
		Form f1("TooHigh", 0, 50);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << "Attempting to create Form with grade 151..." << std::endl;
		Form f2("TooLow", 151, 50);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << "Creating valid Form (Tax, 50, 100)..." << std::endl;
		Form f3("Tax Paper", 50, 100);
		std::cout  << f3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Unexpected error: " << e.what() << RESET << std::endl;
	}

	std::cout << "Test 2: Sign Form" << std::endl;

	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat noob("Intern", 150);

		Form contract("Boss Contract", 20, 20);
		Form contract_2("Intern Contract", 150, 150);

		std::cout << "\n--- Before Signing ---" << std::endl;
		std::cout << contract << std::endl;
		std::cout << contract_2 << std::endl;

		std::cout << "\n--- Signing Attempt 1 (Success) ---" << std::endl;
		boss.signForm(contract);

		std::cout << "\n--- Signing Attempt 2 (Failure) ---" << std::endl;
		noob.signForm(contract);

		std::cout << "\n--- Signing Attempt 3 (Success) ---" << std::endl;
		noob.signForm(contract_2);

		std::cout << "\n--- After Signing ---" << std::endl;
		std::cout << contract << std::endl;
		std::cout << contract_2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "CRITICAL ERROR: " << e.what() << RESET << std::endl;
	}

	return (0);
}