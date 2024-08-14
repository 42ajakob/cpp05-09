#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter( const ScalarConverter& other );
		ScalarConverter& operator=( const ScalarConverter& other );
		~ScalarConverter();
		static void toChar( double dbl );
		static void toInt( double dbl );
		static void toFloat( double dbl );
		static void toDouble( double dbl );

	public:
		static void convert( std::string str );
};

#endif