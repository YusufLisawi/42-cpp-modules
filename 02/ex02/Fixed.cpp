/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:00:10 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/13 16:36:42 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	// std::cout << "Int constructor called" << std::endl;
	this->value = n << Fixed::bits;
}

Fixed::Fixed(const float n)
{
	// std::cout << "Float constructor called" << std::endl;
	this->value = (int)roundf(n * (1 << Fixed::bits));	
}

Fixed::Fixed(const Fixed& other) 
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		// std::cout << "Copy assignment operator called" << std::endl;
		this->value = other.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits(void) const {
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float Fixed::toFloat(void) const {
	return (float)this->value / (float)(1 << Fixed::bits);
}

int Fixed::toInt(void) const {
	return this->value >> Fixed::bits;
}

// Operators

std::ostream &operator<<(std::ostream &stream, const Fixed &other) {
	stream << other.toFloat();
	return stream;
}	

bool Fixed::operator>(const Fixed &other) const {
	return this->value > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
	return this->value < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->value >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->value <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
	return this->value == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->value != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++() {
	this->value += 1;
	return *this;
}

Fixed &Fixed::operator--() {
	this->value -= 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	this->value += 1;
	return tmp;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	this->value -= 1;
	return tmp;
}

// Static

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return ((a < b) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return ((a < b) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return ((a > b) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return ((a > b) ? a : b);
}

