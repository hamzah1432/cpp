/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 08:19:38 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/04 08:43:30 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string the_string = "HI THIS IS BRAIN";
	std::string *stringPTR = &the_string;
	std::string &stringREF = the_string;

	std::cout << "--- Memory Addresses ---" << std::endl;
	std::cout << "Address of the string variable:  " << &the_string << std::endl;
	std::cout << "Address held by stringPTR:       " << stringPTR << std::endl;
	std::cout << "Address held by stringREF:       " << &stringREF << std::endl;
	std::cout << std::endl;
	
	std::cout << "--- Values ---" << std::endl;
	std::cout << "Value of the string variable:    " << the_string << std::endl;
	std::cout << "Value pointed to by stringPTR:   " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF:   " << stringREF << std::endl;

	return 0;
}