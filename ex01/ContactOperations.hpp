/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactOperations.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 00:00:00 by halmuhis          #+#    #+#             */
/*   Updated: 2025/10/20 00:00:00 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTOPERATIONS_HPP
#define CONTACTOPERATIONS_HPP

#include "phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>

// Function declarations
void addContact(PhoneBook &phoneBook);
void searchContact(PhoneBook &phoneBook);

#endif /* CONTACTOPERATIONS_HPP */