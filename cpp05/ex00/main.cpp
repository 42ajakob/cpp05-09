#include "Bureaucrat.hpp"

int main() {
    
    Bureaucrat APerson("Steve", 5);
	Bureaucrat TooHigh("Alex", 0);
	Bureaucrat TooLow("John", 151);

    std::cout << APerson;
	TooHigh.incrementGrade();
	TooLow.decrementGrade();

    try {
		TooHigh.incrementGrade();
    }
    catch (std::exception & e) {
		std::cout << "A Exception happened" << std::endl;
    }
	try {
		TooLow.decrementGrade();
    }
    catch (std::exception & e) {
		std::cout << "A Exception happened" << std::endl;
    }
    return 0;
}