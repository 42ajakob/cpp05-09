#include "Array.hpp"
#include "Array.tpp"

int main( void ) {
	Array<std::string> strArr(3);
	Array<int> intArr(5);
	
	strArr[0] = "Hello";
	strArr[1] = "World";
	strArr[2] = "!";

	std::cout << "Size of strArr: " << strArr.size() << std::endl;
	std::cout << "Size of intArr: " << intArr.size() << std::endl;

	Array<std::string> secStrArr = strArr;
	Array<std::string> thrStrArr(20);

	thrStrArr = secStrArr;

	std::cout << "Size of secStrArr: " << secStrArr.size() << std::endl;
	std::cout << "Size of thrStrArr: " << thrStrArr.size() << std::endl;

	for (unsigned int i = 0; i < thrStrArr.size(); i++) {
		std::cout << "thrStrArr[" << i << "]: " << thrStrArr[i] << std::endl;
	}

	try {
        intArr[10] = 5;
    } catch ( std::exception &e ) {
        std::cerr << "Error: operator[] failed!" << std::endl;
    }
}