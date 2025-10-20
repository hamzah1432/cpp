/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:04:08 by halmuhis          #+#    #+#             */
/*   Updated: 2025/10/19 17:24:09 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
using namespace std;

class Contact
{
private:
    string firstName;
    string lastName;
    string nickname;
    string phoneNumber;
    string darkestSecret;

public:
    bool setFirstName(const string &firstName) {
        if (firstName.empty()) {
            return false;
        }
        this->firstName = firstName;
        return true;
    }

    bool setLastName(const string &lastName) {
        if (lastName.empty()) {
            return false;
        }
        this->lastName = lastName;
        return true;
    }

    bool setNickname(const string &nickname) {
        if (nickname.empty()) {
            return false;
        }
        this->nickname = nickname;
        return true;
    }

    bool setPhoneNumber(const string &phoneNumber) {
        if (phoneNumber.empty()) {
            return false;
        }
        this->phoneNumber = phoneNumber;
        return true;
    }

    bool setDarkestSecret(const string &darkestSecret) {
        if (darkestSecret.empty()) {
            return false;
        }
        this->darkestSecret = darkestSecret;
        return true;
    }

    string getFirstName() const {
        return firstName;
    }

    string getLastName() const {
        return lastName;
    }

    string getNickname() const {
        return nickname;
    }

    string getPhoneNumber() const {
        return phoneNumber;
    }

    string getDarkestSecret() const {
        return darkestSecret;
    }

    // bool isValid() const {
    //     return !firstName.empty() && !lastName.empty() && !nickname.empty() && 
    //            !phoneNumber.empty() && !darkestSecret.empty();
    // }
};

#endif /* CONTACT_HPP */
