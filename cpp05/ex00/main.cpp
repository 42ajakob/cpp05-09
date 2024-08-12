#include "Bureaucrat.hpp"

int main() {
    
    Bureaucrat Steve("Steve", 1);
	Bureaucrat Alex("Alex", 150);

	/* Bob */
	try {
		Bureaucrat TooHigh("Bob", 0);
	}
	catch (std::exception & e) {
		std::cout << "Bob: " << e.what() << std::endl;
	}

	/* AnotherBob */
	try {
	Bureaucrat TooLow("AnotherBob", 151);
	}
	catch (std::exception & e) {
		std::cout << "AnotherBob: " << e.what() << std::endl;
	}

	/* Steve */
    try {
		std::cout << "Steve: Try to increment" << std::endl;
		Steve.incrementGrade();
    }
    catch (std::exception & e) {
		std::cout << "Steve: " << e.what() << std::endl;
    }

	/* Alex */
	try {
		std::cout << "Alex: Try to decrement" << std::endl;
		Alex.decrementGrade();
    }
    catch (std::exception & e) {
		std::cout << "Alex: " << e.what() << std::endl;
    }

	/* Overload */
    std::cout << Steve;
	std::cout << Alex;

    return 0;
}