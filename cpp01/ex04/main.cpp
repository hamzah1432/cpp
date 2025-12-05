/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 08:19:38 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/05 17:53:47 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{

	if (argc != 4)
	{
		std::cerr << "Error: Program requires exactly three parameters." << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "Error: s1 (search string) cannot be empty." << std::endl;
		return 1;
	}

	Replacer replacer(filename, s1, s2, filename + ".replace");


	return replacer.execute();
}