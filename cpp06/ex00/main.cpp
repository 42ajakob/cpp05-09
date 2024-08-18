#include "ScalarConverter.hpp"

/*
CHAR_MIN = -128, CHAR_MAX = 127
INT_MIN = -2147483648, INT_MAX = 2147483647
FLOAT_MIN = -1.234e+38f, FLOAT_MAX = 1.234e+38f
DOUBLE_MIN = -1.234e+308, DOUBLE_MAX = 1.234e+308
*/
int main(int argc, char **argv) {
	if (argc == 2 && argv[1] != NULL) 
		ScalarConverter::convert(argv[1]);
	return 0;
}