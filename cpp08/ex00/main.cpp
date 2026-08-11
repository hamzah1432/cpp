/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhesn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 16:07:45 by halmuhis          #+#    #+#             */
/*   Updated: 2026/08/11 20:55:08 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::cout << "--- Testing with std::vector ---" << std::endl;
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	int target = 20;

	std::vector<int>::iterator vec_it1 = easyfind(vec, target);
	if (vec_it1 != vec.end())
	{
		std::cout << "Success: Found in vector -> " << *vec_it1 << std::endl;
	}
	else
	{
		std::cout << "Failed to find  " << target << " in vector." << std::endl;
	}

	target = 100;
	std::vector<int>::iterator vec_it2 = easyfind(vec, target);
	if (vec_it2 != vec.end())
	{
		std::cout << "Success: Found in vector -> " << *vec_it2 << std::endl;
	}
	else
	{
		std::cout << "Failed to find " << target << " in vector." << std::endl;
	}

	std::cout << "\n";

	std::cout << "--- Testing with std::list ---" << std::endl;
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);

	target = 3;
	std::list<int>::iterator lst_it1 = easyfind(lst, target);
	if (lst_it1 != lst.end())
	{
		std::cout << "Success: Found in list -> " << *lst_it1 << std::endl;
	}
	else
	{
		std::cout << "Failed to find " << target << " in list." << std::endl;
	}

	target = 99;
	std::list<int>::iterator lst_it2 = easyfind(lst, target);
	if (lst_it2 != lst.end())
	{
		std::cout << "Success: Found in list -> " << *lst_it2 << std::endl;
	}
	else
	{
		std::cout << "Failed to find " << target << " in list." << std::endl;
	}

	return 0;
}