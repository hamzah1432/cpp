#include "../include/Contact.hpp"

bool Contact::setFirstName(const std::string &firstName) {
    if (firstName.empty()) {
        return false;
    }
    this->firstName = firstName;
    return true;
}

bool Contact::setLastName(const std::string &lastName) {
    if (lastName.empty()) {
        return false;
    }
    this->lastName = lastName;
    return true;
}

bool Contact::setNickname(const std::string &nickname) {
    if (nickname.empty()) {
        return false;
    }
    this->nickname = nickname;
    return true;
}

bool Contact::setPhoneNumber(const std::string &phoneNumber) {
    if (phoneNumber.empty()) {
        return false;
    }
    this->phoneNumber = phoneNumber;
    return true;
}

bool Contact::setDarkestSecret(const std::string &darkestSecret) {
    if (darkestSecret.empty()) {
        return false;
    }
    this->darkestSecret = darkestSecret;
    return true;
}

std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickname() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return darkestSecret;
}