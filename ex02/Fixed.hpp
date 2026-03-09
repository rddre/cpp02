#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
	    int _fixedPointValue;
	    static const int _fractionalBits = 8;
	
	public:
	    Fixed();
	    Fixed(const int value);
	    Fixed(const float value);
	    Fixed(const Fixed& other);
	    Fixed& operator=(const Fixed& other);
	    ~Fixed();

	    int getRawBits() const;
	    void setRawBits(int const raw);

	    float toFloat( void ) const;
	    int toInt( void ) const;

	    // les operateur pour les comparaisons
	    bool operator>(const Fixed& other) const;
	    bool operator<(const Fixed& other) const;
	    bool operator>=(const Fixed& other) const;
	    bool operator<=(const Fixed& other) const;
	    bool operator==(const Fixed& other) const;
	    bool operator!=(const Fixed& other) const;

	    // les operateur arithmetiques
	    Fixed operator+(const Fixed& other) const;
	    Fixed operator-(const Fixed& other) const;
	    Fixed operator*(const Fixed& other) const;
	    Fixed operator/(const Fixed& other) const;

	    // les operateur d'incrementation et de decrementation
	    Fixed& operator++();    // pre-increment
	    Fixed  operator++(int); // post-increment
	    Fixed& operator--();    // pre-decrement
	    Fixed  operator--(int); // post-decrement

	    // les function de min et max
	    static Fixed&       min(Fixed& a, Fixed& b);
	    static const Fixed& min(const Fixed& a, const Fixed& b);
	    static Fixed&       max(Fixed& a, Fixed& b);
	    static const Fixed& max(const Fixed& a, const Fixed& b);

	    friend std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
};

#endif