#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Error: more/less then 2 arguments" << std::endl;
		return 1;
	}
	std::ifstream inFile(argv[1]);
	if (!inFile) {
		std::cout << "Error: could not open input file" << std::endl;
		return 1;
	}
	BitcoinExchange b;
	std::string line;

	std::getline(inFile, line);
	if (line != "date | value") {
		inFile.close();
		return 1;
	}
	while (std::getline(inFile, line)) {

		if (!b.genKeyValueForDVM(line)) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}

		std::string key = b.getUserDVM().begin()->first;
		double value = b.getUserDVM().begin()->second;

		if (value < 0) 
			std::cout << "Error: negative number" << std::endl;
		else if (value > 1000)
			std::cout << "Error: to big of a number" << std::endl;
		else {
			if (b.bitcoinValue() == false) {
				std::cout << "You Corrupted the data.csv!" << std::endl;
				std::cout << "Or it's missing... to lazy to write more specific errors for that..." << std::endl;
				return 1;
			}
			std::cout << key << " => " << value << " = " << b.getBitcoin() * value << std::endl;
		}
		b.eraseUserDVM();
	}

	inFile.close();
	return 0;
}