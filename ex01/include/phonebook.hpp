/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:52:41 by halmuhis          #+#    #+#             */
/*   Updated: 2025/10/27 01:52:53 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int contactCount;  // number of contacts stored so far (max 8)
    int nextIndex;     // where to insert the next contact

public:
    PhoneBook();
    void addContact(const Contact& newContact);
    int getContactCount() const;
    Contact getContact(int index) const;
    bool displayContacts() const;
};

#endif
