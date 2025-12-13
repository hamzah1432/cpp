/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:54:44 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/13 16:11:15 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
   const int N_ANIMALS = 6;
    std::cout << "🔷 --- PART 1: Array of Animals Test --- 🔷" << std::endl;
    
    const Animal* animals[N_ANIMALS];

    std::cout << "\n--> Constructing Animals..." << std::endl;
    for (int i = 0; i < N_ANIMALS; i++)
    {
        if (i < N_ANIMALS / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n--> Testing Sounds..." << std::endl;
    for (int i = 0; i < N_ANIMALS; i++)
    {
        animals[i]->makeSound();
    }

    std::cout << "\n--> Deleting Animals (Check Destructors)..." << std::endl;
    for (int i = 0; i < N_ANIMALS; i++)
    {
        delete animals[i];
    }

    std::cout << "\n----------------------------------------------------\n" << std::endl;


    std::cout << "🔷 --- PART 2: Deep Copy Proof --- 🔷" << std::endl;
    
    std::cout << "\n1. Create Original Dog and set idea..." << std::endl;
    Dog originalDog;
    originalDog.setIdea(0, "I love bones! 🦴");
    
    std::cout << "Original Idea: " << originalDog.getIdea(0) << std::endl;

    std::cout << "\n2. Create Copy Dog (Copy Constructor)..." << std::endl;
    Dog copyDog = originalDog; 

    std::cout << "\n3. Change Original Dog's idea..." << std::endl;
    originalDog.setIdea(0, "I hate cats! 😡"); 

    std::cout << "\n4. Check Ideas (Should be different if Deep Copy works):" << std::endl;
    std::cout << "Original Dog says: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copy Dog says:     " << copyDog.getIdea(0) << std::endl;

    if (copyDog.getIdea(0) == "I love bones! 🦴")
        std::cout << "\n✅ SUCCESS: Deep Copy verified!" << std::endl;
    else
        std::cout << "\n❌ FAILURE: Shallow Copy detected!" << std::endl;

    std::cout << "\n--> End of main (Destructors for Stack objects)..." << std::endl;
    return 0;
}