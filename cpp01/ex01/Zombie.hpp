/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:15:53 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/03 12:28:31 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
private:
    std::string name;

public:
    Zombie(); 
    Zombie(std::string name);
    void setName(std::string name);
    void announce(void);
    ~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif