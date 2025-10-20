/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactOperations.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 00:00:00 by halmuhis          #+#    #+#             */
/*   Updated: 2025/10/20 00:00:00 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ContactOperations.hpp"

void addContact(PhoneBook &phoneBook) {
    Contact newContact;
    string input;

    cout << "You chose ADD command\n";

    // First Name - loop until non-empty
    do {
        cout << "First Name: ";
        if (!getline(cin, input)) {
            cout << "\nInput aborted.\n";
            return;
        }
        if (input.empty()) {
            cout << "First Name cannot be empty. Please try again.\n";
        }
    } while (input.empty());
    newContact.setFirstName(input);

    // Last Name - loop until non-empty
    do {
        cout << "Last Name: ";
        if (!getline(cin, input)) {
            cout << "\nInput aborted.\n";
            return;
        }
        if (input.empty()) {
            cout << "Last Name cannot be empty. Please try again.\n";
        }
    } while (input.empty());
    newContact.setLastName(input);

    // Nickname - loop until non-empty
    do {
        cout << "Nickname: ";
        if (!getline(cin, input)) {
            cout << "\nInput aborted.\n";
            return;
        }
        if (input.empty()) {
            cout << "Nickname cannot be empty. Please try again.\n";
        }
    } while (input.empty());
    newContact.setNickname(input);

    // Phone Number - loop until non-empty
    do {
        cout << "Phone Number: ";
        if (!getline(cin, input)) {
            cout << "\nInput aborted.\n";
            return;
        }
        if (input.empty()) {
            cout << "Phone Number cannot be empty. Please try again.\n";
        }
    } while (input.empty());
    newContact.setPhoneNumber(input);

    // Darkest Secret - loop until non-empty
    do {
        cout << "Darkest Secret: ";
        if (!getline(cin, input)) {
            cout << "\nInput aborted.\n";
            return;
        }
        if (input.empty()) {
            cout << "Darkest Secret cannot be empty. Please try again.\n";
        }
    } while (input.empty());
    newContact.setDarkestSecret(input);

    phoneBook.addContact(newContact);
    cout << "Contact added successfully!\n";
}


void searchContact(PhoneBook &phoneBook) {
    cout << "You chose SEARCH command\n";
    if (!phoneBook.displayContacts())
        return;

    // Get and validate index
    string input;
    cout << "Enter the index of the contact to display: ";
    if (!getline(cin, input)) return;
    int index = input[0] - '0';
    if (input.empty() || input.length() > 1 || !isdigit(input[0]) || input[0] < '0' || input[0] > '7' || index >= phoneBook.getContactCount()) {
        cout << "Error: Index cannot be empty, must be a digit between 0 and 7.\n";
        return;
    }
    // Display contact details
    Contact contact = phoneBook.getContact(index);
    cout << "\nFirst Name: " << contact.getFirstName() << endl;
    cout << "Last Name: " << contact.getLastName() << endl;
    cout << "Nickname: " << contact.getNickname() << endl;
    cout << "Phone Number: " << contact.getPhoneNumber() << endl;
    cout << "Darkest Secret: " << contact.getDarkestSecret() << endl;
}