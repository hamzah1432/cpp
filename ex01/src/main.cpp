/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 01:50:16 by halmuhis          #+#    #+#             */
/*   Updated: 2025/10/27 02:03:09 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"
#include "../include/Contact.hpp"
#include "../include/ContactOperations.hpp"


void commandLoop(PhoneBook &phoneBook) {
    std::string command;

    while (true) {
       std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) {
            std::cout << "\nExiting program.\n";
            break;
        }

        if (command == "ADD") {
             addContact(phoneBook);
        }
        else if (command == "SEARCH") {
            searchContact(phoneBook);
        }
        else if (command == "EXIT") {
            std::cout << "Exiting program.\n";
            break;
        }
    }
}

int main() {
    PhoneBook phoneBook;
    commandLoop(phoneBook);
    return 0;
}