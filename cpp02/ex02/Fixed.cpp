/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 08:43:14 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/09 10:40:46 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0) {}

Fixed::Fixed(const int value) {
    _fixedPoint = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    _fixedPoint = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        _fixedPoint = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

int Fixed::getRawBits(void) const {
    return _fixedPoint;
}

void Fixed::setRawBits(int const raw) {
    _fixedPoint = raw;
}

float Fixed::toFloat(void) const {
    return (float)_fixedPoint / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _fixedPoint >> _fractionalBits;
}


// Comparison Operators

bool Fixed::operator>(const Fixed &other) const {
    return _fixedPoint > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
    return _fixedPoint < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
    return _fixedPoint >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
    return _fixedPoint <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
    return _fixedPoint == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
    return _fixedPoint != other.getRawBits();
}

// Arithmetic Operators

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result.setRawBits(_fixedPoint + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result.setRawBits(_fixedPoint - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

// Increment/Decrement

Fixed &Fixed::operator++() {
    _fixedPoint++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    _fixedPoint++;// نعدل الكائن الحالي
    return temp; 
}

Fixed &Fixed::operator--() {
    _fixedPoint--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    _fixedPoint--;
    return temp;
}


// Static Member Functions: Min / Max


Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}