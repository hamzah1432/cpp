/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:54:31 by halmuhis          #+#    #+#             */
/*   Updated: 2026/02/11 07:40:37 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	std::cout << "--- Test 1: Valid Bureaucrat ---" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;

		bob.incrementGrade();
		std::cout << "After increment: " << bob << std::endl;

		bob.decrementGrade();
		std::cout << "After decrement: " << bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2: Grade Too High (Constructor) ---" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mException caught: " << e.what() << "\033[0m" << std::endl;
	}

	std::cout << "\n--- Test 3: Grade Too Low (Constructor) ---" << std::endl;
	try
	{
		Bureaucrat john("John", 151);
		}
		catch (std::exception &e)
	{
		std::cout << "\033[1;31mException caught: " << e.what() << "\033[0m" << std::endl;
	}

	std::cout << "\n--- Test 4: Increment Beyond Limit ---" << std::endl;
	try
	{
		Bureaucrat king("Big Modeer", 1);
		std::cout << king << std::endl;

		king.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mException caught: " << e.what() << "\033[0m" << std::endl;
	}

	std::cout << "\n--- Test 5: Decrement Beyond Limit ---" << std::endl;
	try
	{
		Bureaucrat lowest("Small Moder", 150);
		std::cout << lowest << std::endl;
		lowest.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mException caught: " << e.what() << "\033[0m" << std::endl;
	}

	return (0);
}