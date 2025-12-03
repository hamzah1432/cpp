/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:28:54 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/03 12:31:39 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0) {
        std::cerr << "Error: N must be a positive number." << std::endl;
        return NULL;
    }

    Zombie* horde = new Zombie[N]; 

    for (int i = 0; i < N; ++i) {
        horde[i].setName(name);
    }

    return horde;
}