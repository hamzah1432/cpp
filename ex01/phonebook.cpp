/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:05:46 by halmuhis          #+#    #+#             */
/*   Updated: 2025/10/19 17:25:48 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "Contact.hpp"
#include "ContactOperations.hpp"

void commandLoop(PhoneBook &phoneBook) {
    string command;

    while (true) {
        cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!getline(cin, command)) {
            cout << "\nExiting program.\n";
            break;
        }

        if (command == "ADD") {
             addContact(phoneBook);
        }
        else if (command == "SEARCH") {
            searchContact(phoneBook);
        }
        else if (command == "EXIT") {
            cout << "Exiting program.\n";
            break;
        }
        // Any other input is ignored (no error message as per documentation)
    }
}

int main() {
    PhoneBook phoneBook;
    commandLoop(phoneBook);
    return 0;
}