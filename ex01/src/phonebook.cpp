/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:05:46 by halmuhis          #+#    #+#             */
/*   Updated: 2025/10/27 01:52:51 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"

PhoneBook::PhoneBook() : contactCount(0), nextIndex(0) {}

void PhoneBook::addContact(const Contact& newContact) {
    contacts[nextIndex] = newContact;
    nextIndex = (nextIndex + 1) % 8;
    if (contactCount < 8)
        ++contactCount;
}

int PhoneBook::getContactCount() const {
    return contactCount;
}

Contact PhoneBook::getContact(int index) const {
    return contacts[index];
}

bool PhoneBook::displayContacts() const {
    if (contactCount == 0) {
        std::cout << "No contacts available.\n";
        return false;
    }

    // Display header
    std::cout << std::setw(10) << std::right << "Index" << "|" << std::setw(10) << std::right << "First Name" << "|"
         << std::setw(10) << std::right << "Last Name" << "|" << std::setw(10) << std::right << "Nickname" << std::endl;

    // Display all contacts
    for (int i = 0; i < contactCount; i++) {
        const Contact& contact = contacts[i];
        std::string firstName = contact.getFirstName().length() > 10 ? 
            contact.getFirstName().substr(0, 9) + "." : contact.getFirstName();
        std::string lastName = contact.getLastName().length() > 10 ? 
            contact.getLastName().substr(0, 9) + "." : contact.getLastName();
        std::string nickname = contact.getNickname().length() > 10 ? 
            contact.getNickname().substr(0, 9) + "." : contact.getNickname();
        
        std::cout << std::setw(10) << std::right << i << "|" << std::setw(10) << std::right << firstName << "|"
             << std::setw(10) << std::right << lastName << "|" << std::setw(10) << std::right << nickname << std::endl;
    }
    return true;
}

