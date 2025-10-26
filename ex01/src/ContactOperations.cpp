/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactOperations.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 00:00:00 by halmuhis          #+#    #+#             */
/*   Updated: 2025/10/27 01:56:49 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ContactOperations.hpp"


void addContact(PhoneBook &phoneBook) {
    Contact newContact;
    std::string input;

    std::cout << "You chose ADD command\n";

    // First Name - loop until non-empty
    do {
        std::cout << "First Name: ";
        if (!std::getline(std::cin, input)) {
            std::cout << "\nInput aborted.\n";
            return;
        }
        if (input.empty()) {
            std::cout << "First Name cannot be empty. Please try again.\n";
        }
    } while (input.empty());
    newContact.setFirstName(input);

    // Last Name - loop until non-empty
    do {
        std::cout << "Last Name: ";
        if (!std::getline(std::cin, input)) {
            std::cout << "\nInput aborted.\n";
            return;
        }
        if (input.empty()) {
            std::cout << "Last Name cannot be empty. Please try again.\n";
        }
    } while (input.empty());
    newContact.setLastName(input);

    // Nickname - loop until non-empty
    do {
        std::cout << "Nickname: ";
        if (!std::getline(std::cin, input)) {
            std::cout << "\nInput aborted.\n";
            return;
        }
        if (input.empty()) {
            std::cout << "Nickname cannot be empty. Please try again.\n";
        }
    } while (input.empty());
    newContact.setNickname(input);

    // Phone Number - loop until non-empty
    do {
        std::cout << "Phone Number: ";
        if (!std::getline(std::cin, input)) {
            std::cout << "\nInput aborted.\n";
            return;
        }
        if (input.empty()) {
            std::cout << "Phone Number cannot be empty. Please try again.\n";
        }
    } while (input.empty());
    newContact.setPhoneNumber(input);

    // Darkest Secret - loop until non-empty
    do {
        std::cout << "Darkest Secret: ";
        if (!std::getline(std::cin, input)) {
            std::cout << "\nInput aborted.\n";
            return;
        }
        if (input.empty()) {
            std::cout << "Darkest Secret cannot be empty. Please try again.\n";
        }
    } while (input.empty());
    newContact.setDarkestSecret(input);

    phoneBook.addContact(newContact);
    std::cout << "Contact added successfully!\n";
}


void searchContact(PhoneBook &phoneBook) {
    std::cout << "You chose SEARCH command\n";
    if (!phoneBook.displayContacts())
        return;

    // Get and validate index
    std::string input;
    std::cout << "Enter the index of the contact to display: ";
    if (!std::getline(std::cin, input)) return;
    int index = input[0] - '0';
    if (input.empty() || input.length() > 1 || !std::isdigit(input[0]) || input[0] < '0' || input[0] > '7' || index >= phoneBook.getContactCount()) {
        std::cout << "Error: Index cannot be empty, must be a digit between 0 and 7.\n";
        return;
    }
    // Display contact details
    Contact contact = phoneBook.getContact(index);
    std::cout << "\nFirst Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}