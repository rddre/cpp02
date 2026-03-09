#include "Fixed.hpp"
#include <cmath>
#include <iostream>

// --- constructeurs et destructeur ---

Fixed::Fixed() : _fixedPointValue(0)
{}

Fixed::Fixed(const int value) : _fixedPointValue(value << _fractionalBits)
{}

Fixed::Fixed(const float value) : _fixedPointValue(roundf(value * (1 << _fractionalBits)))
{}

Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue)
{}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_fixedPointValue = other._fixedPointValue;
	return *this;
}

Fixed::~Fixed()
{}

// --- getters et setters ---

int Fixed::getRawBits() const
{
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

// --- conversions ---

float Fixed::toFloat(void) const
{
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _fixedPointValue >> _fractionalBits;
}

// --- operateurs de comparaison ---

bool Fixed::operator>(const Fixed& other) const
{
	return _fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed& other) const
{
	return _fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return _fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return _fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed& other) const
{
	return _fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return _fixedPointValue != other._fixedPointValue;
}

// --- operateurs arithmetiques ---

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(_fixedPointValue + other._fixedPointValue);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(_fixedPointValue - other._fixedPointValue);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(((long long)_fixedPointValue * other._fixedPointValue) >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	// check division par zero, pas obligatoire mais je le rajoute quand meme
	if (other._fixedPointValue == 0)
	{
		std::cerr << "Error: division par 0 mathematiquement imposible" << std::endl;
		std::cerr << "pour des raisons de securite, le resultat est 0" << std::endl;
		return Fixed();
	}
	Fixed result;
	result.setRawBits(((long long)_fixedPointValue << _fractionalBits) / other._fixedPointValue);
	return result;
}

// --- incrementation et decrementation ---
// le plus petit epsilon representable est 1 unite brute (soit 1 / 2^8)

Fixed& Fixed::operator++()
{
	++_fixedPointValue;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++_fixedPointValue;
	return tmp;
}

Fixed& Fixed::operator--()
{
	--_fixedPointValue;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--_fixedPointValue;
	return tmp;
}

// --- min et max ---

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

// --- operateur d'insertion dans le flux de sortie ---
// affiche la valeur en virgule flottante de l'objet Fixed

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}