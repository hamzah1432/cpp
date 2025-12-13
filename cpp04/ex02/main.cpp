/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:54:44 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/13 19:31:41 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"



int main()
{
    // Animal test;
    // Animal* test2 = new Animal();  


    std::cout << "\033[1;33m" << "Subject Mandatory Test" << "\033[0m" << std::endl;
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "J type: " << j->getType() << " | Sound: "; j->makeSound();
    std::cout << "I type: " << i->getType() << " | Sound: "; i->makeSound();

    delete j; 
    delete i;
    std::cout << "--------------------------------------------\n" << std::endl;
    return 0;
}