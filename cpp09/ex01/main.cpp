#include "RPN.hpp"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr << "Error: Invalid amount of arguments" << std::endl;
	}

	RPN rpn;
	rpn.calculation(argv[1]);
	
	if (rpn.getResult() == -1)
		return (1);
	std::cout << rpn.getResult() << std::endl;
	return 0;
}