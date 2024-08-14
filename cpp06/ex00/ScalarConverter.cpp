#include "ScalarConverter.hpp"

/* Constructor */

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter( const ScalarConverter& other ) {
	*this = other;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& other ) {
	if (this != &other) {

	}
	return *this;
}

ScalarConverter::~ScalarConverter() {
}

/* Functions */

void ScalarConverter::toChar( double dbl ) {
	if (dbl != dbl
			|| dbl == std::numeric_limits<double>::infinity()
			|| dbl < std::numeric_limits<char>::min()
			|| dbl > std::numeric_limits<char>::max())
		std::cout << "Char: Impossible!" << std::endl;
    else if (dbl >= 32 && dbl <= 126)
        std::cout << "Char: " << static_cast<char>(dbl) << std::endl;
	else if (dbl >= std::numeric_limits<char>::min()
			&& dbl <= std::numeric_limits<char>::max())
		std::cout << "Char: Non displayable" << std::endl;
}

void ScalarConverter::toInt( double dbl ) {
	if (dbl != dbl
			|| dbl == std::numeric_limits<double>::infinity()
			|| dbl < std::numeric_limits<int>::min()
			|| dbl > std::numeric_limits<int>::max())
		std::cout << "Int: Impossible!" << std::endl;
    else if (dbl >= std::numeric_limits<int>::min()
			&& dbl <= std::numeric_limits<int>::max())
        std::cout << "Int: " << static_cast<int>(dbl) << std::endl;
}

void ScalarConverter::toFloat( double dbl ) {
	if (dbl != dbl)
		std::cout << "Float: nanf" << std::endl;
	else if (static_cast<float>(dbl) == -std::numeric_limits<float>::infinity())
		std::cout << "Float: -inff" << std::endl;
	else if (static_cast<float>(dbl) == std::numeric_limits<float>::infinity())
	    std::cout << "Float: +inff" << std::endl;
    else {
		std::cout << "Float: " << dbl;
		if (dbl == static_cast<int>(dbl))
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
}

void ScalarConverter::toDouble( double dbl ) {
	if (dbl != dbl)
		std::cout << "Double: nan" << std::endl;
	else if (dbl == -std::numeric_limits<double>::infinity())
		std::cout << "Double: -inf" << std::endl;
	else if (dbl == std::numeric_limits<double>::infinity())
		std::cout << "Double: +inf" << std::endl;
	else {
		std::cout << "Double: " << dbl;
		if (dbl == static_cast<int>(dbl))
			std::cout << ".0";
		std::cout << std::endl;
	}
}

void ScalarConverter::convert( std::string str ) {

	char *ptr = NULL;
	double dbl = std::strtod(str.c_str(), &ptr);

	if (str.length() == 1 && !isdigit(str[0]) && dbl == 0) {
		dbl = str[0];
		ptr[0] = '\0';
	}
	if (ptr == NULL || (ptr[0] == '\0' || (ptr[0] == 'f' && ptr[1] == '\0'))) {
		toChar(dbl);
		toInt(dbl);
		toFloat(dbl);
		toDouble(dbl);
	}
	else
		std::cout << "Wrong input!" << std::endl;
}
