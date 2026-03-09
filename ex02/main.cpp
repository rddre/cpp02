#include <iostream>
#include "Fixed.hpp"

int main_du_pdf()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

int main(void)
{
	Fixed a;
	std::cout << "variable 'a' avec le constructeur par defaut donc a = 0\n\n";

	Fixed const b( Fixed(5.05f) * Fixed(2) );
	std::cout << "On cree 'b' avec : Fixed(5.05f) * Fixed(2)\n";
	std::cout << "Donc b devrait contenir environ 10.10\n\n";

	std::cout << "\n----- Pre-increment (++a) -----\n\n";

	std::cout << "On fait ++a\n";
	std::cout << "Resultat de ++a : " << ++a << std::endl << std::endl;

	std::cout << "Nouvelle valeur de a : " << a << std::endl << std::endl;


	std::cout << "\n----- Post-increment (a++) -----\n\n";

	std::cout << "On fait a++\n";
	std::cout << "Valeur retournee par a++ : " << a++ << std::endl << std::endl;

	std::cout << "Valeur de a apres increment : " << a << std::endl << std::endl;


	std::cout << "\n----- Valeur de b -----\n\n";

	std::cout << "b = " << b << std::endl << std::endl;


	std::cout << "\n----- Test de max -----\n\n";

	std::cout << "Le maximum entre a et b est : ";
	std::cout << Fixed::max(a, b) << std::endl << std::endl;


	std::cout << "\n\n---- autres tests -----\n\n";


	std::cout << "\n----- Comparaisons -----\n\n";

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl << std::endl;

	std::cout << "a > b : " << (a > b) << std::endl;
	std::cout << "a < b : " << (a < b) << std::endl;
	std::cout << "a == b : " << (a == b) << std::endl;
	std::cout << "a != b : " << (a != b) << std::endl << std::endl;


	std::cout << "\n----- Operations arithmetiques -----\n\n";

	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "b / a = " << b / a << std::endl << std::endl;


	std::cout << "\n----- Test de min -----\n\n";

	std::cout << "Le minimum entre a et b est : ";
	std::cout << Fixed::min(a, b) << std::endl << std::endl;


	std::cout << "\n----- Conversion -----\n\n";

	std::cout << "a en float : " << a.toFloat() << std::endl;
	std::cout << "a en int   : " << a.toInt() << std::endl << std::endl;

	std::cout << "b en float : " << b.toFloat() << std::endl;
	std::cout << "b en int   : " << b.toInt() << std::endl << std::endl;

	std::cout << "\n----- calcul un peu complique -----\n\n";
	std::cout << "(((a * b) + (a + a - b)) / a) * b = " << ((((a * b) + (a + a - b)) / a) * b) << std::endl << std::endl;
	std::cout << "division par zero : a / 0 = " << (a / Fixed(0)) << std::endl;

	std::cout << "\n----- aussi l'output du main du pdf -----\n\n";
	main_du_pdf();

	return 0;
}