#include "PmergeMe.hpp"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr << "Error: Invalid amount of arguments" << std::endl;
	}

	PmergeMe merge;
	merge.calculation(argv[1]);
	
	if (merge.getResult() == -1)
		return (1);
	std::cout << merge.getResult() << std::endl;
	return 0;
}