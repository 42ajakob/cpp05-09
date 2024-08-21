#include "PmergeMe.hpp"

int main(int argc, char **argv) {

	if (argc < 2) {
		std::cerr << "Error: invalid amount of arguments" << std::endl;
		return 1;
	}

	PmergeMe merge;

	for (int i = 1; i < argc; i++) {

		std::string str = argv[i];

		if (!std::all_of(str.begin(), str.end(), ::isdigit) || std::stoi(argv[i]) < 0) {
			std::cerr << "Error: invalid number" << std::endl;
			return 1;
		}
		merge.addNumVec(std::stoi(str));
		merge.addNumDeq(std::stoi(str));
	}

	std::cout << "Before: ";
	for (int j = 1; j < argc; j++) {
		std::cout << argv[j] << " ";
	}
	std::cout << std::endl;

	merge.timerForVec();
	merge.timerForDeq();
	return 0;
}