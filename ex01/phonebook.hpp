/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:52:41 by halmuhis          #+#    #+#             */
/*   Updated: 2025/10/19 17:14:35 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

using namespace std;

class PhoneBook {
private:
    Contact contacts[8];
    int contactCount;  // number of contacts stored so far (max 8)
    int nextIndex;     // where to insert the next contact

public:
    PhoneBook() : contactCount(0), nextIndex(0) {}

    void addContact(const Contact& newContact) {
        contacts[nextIndex] = newContact;
        nextIndex = (nextIndex + 1) % 8;
        if (contactCount < 8)
            ++contactCount;
    }

    int getContactCount() const {
        return contactCount;
    }

    Contact getContact(int index) const {
        return contacts[index];
    }

    bool displayContacts() const {
        if (contactCount == 0) {
            cout << "No contacts available.\n";
            return false;
        }

        // Display header
        cout << setw(10) << right << "Index" << "|" << setw(10) << right << "First Name" << "|"
             << setw(10) << right << "Last Name" << "|" << setw(10) << right << "Nickname" << endl;

        // Display all contacts
        for (int i = 0; i < contactCount; i++) {
            const Contact& contact = contacts[i];
            string firstName = contact.getFirstName().length() > 10 ? 
                contact.getFirstName().substr(0, 9) + "." : contact.getFirstName();
            string lastName = contact.getLastName().length() > 10 ? 
                contact.getLastName().substr(0, 9) + "." : contact.getLastName();
            string nickname = contact.getNickname().length() > 10 ? 
                contact.getNickname().substr(0, 9) + "." : contact.getNickname();
            
            cout << setw(10) << right << i << "|" << setw(10) << right << firstName << "|"
                 << setw(10) << right << lastName << "|" << setw(10) << right << nickname << endl;
        }
        return true;
    }
};

#endif /* PHONEBOOK_HPP */
