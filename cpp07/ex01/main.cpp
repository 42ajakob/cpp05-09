#include "iter.hpp"

static void printer(std::string& printer) {
	std::cout << printer << std::endl;
}

static void inter(const int& inter) {
	std::cout << inter << std::endl;
}

int main( void ) {
	std::string strArr[] = {"Hello", "World", "!"};
	int intArr[] = {37, 69, 42};

	::iter(strArr, std::size(strArr), printer);
	::iter(intArr, std::size(intArr), inter);
}