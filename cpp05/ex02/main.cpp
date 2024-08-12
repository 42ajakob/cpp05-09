#include "OldClass/Bureaucrat.hpp"
#include "OldClass/AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    
	/* Constructor */
    Bureaucrat Steve("Steve", 1);
	Bureaucrat Alex("Alex", 150);

	ShrubberyCreationForm Shrub("Shrub");
	RobotomyRequestForm Robotomy("Robotomy");
	PresidentialPardonForm President("President");

	/* execute without it be signed */
	Steve.executeForm(Shrub);
	Steve.executeForm(Robotomy);
	Steve.executeForm(President);

	/* try to sign with to low of a grade */
	try {
		Shrub.beSigned(Alex);
	}
	catch (std::exception & e) {
		std::cout << "Alex: Failed to sign " << Shrub.getName() << " because " << e.what() << std::endl;
	}
	try {
		Robotomy.beSigned(Alex);
	}
	catch (std::exception & e) {
		std::cout << "Alex: Failed to sign " << Shrub.getName() << " because " << e.what() << std::endl;
	}
	try {
		President.beSigned(Alex);
	}
	catch (std::exception & e) {
		std::cout << "Alex: Failed to sign " << Shrub.getName() << " because " << e.what() << std::endl;
	}
	std::cout << std::endl;

	/* sign form */
	try {
		Shrub.beSigned(Steve);
	}
	catch (std::exception & e) {
		std::cout << "Steve: Failed to sign " << Shrub.getName() << " because " << e.what() << std::endl;
	}
	try {
		Robotomy.beSigned(Steve);
	}
	catch (std::exception & e) {
		std::cout << "Steve: Failed to sign " << Robotomy.getName() << " because " << e.what() << std::endl;
	}
	try {
		President.beSigned(Steve);
	}
	catch (std::exception & e) {
		std::cout << "Steve: Failed to sign " << Robotomy.getName() << " because " << e.what() << std::endl;
	}
	std::cout << "Steve: Signed all 3 Forms for Alex if he has Grade level 1" << std::endl;
	std::cout << std::endl;

	/* execute form with */
	Alex.executeForm(Robotomy);
	Steve.executeForm(Robotomy);
	Steve.executeForm(Robotomy);
	Steve.executeForm(Robotomy);
	Steve.executeForm(Robotomy);
	Steve.executeForm(Robotomy);
	Steve.executeForm(Robotomy);
	Steve.executeForm(Robotomy);
	Steve.executeForm(Robotomy);

	Alex.executeForm(President);
	Steve.executeForm(President);
	std::cout << std::endl;

	/* So sign and grade level work properly */
	Bureaucrat bob("Bob", 72);
	Bureaucrat bobsBrother("Bob's Brother", 45);
	Bureaucrat evilBob("Evil Bob", 73);
	Bureaucrat evilBobsBrother("Evil Bob's Brother", 46);

	try {
		Shrub.beSigned(evilBob);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		}
	try {
		Shrub.beSigned(bob);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	evilBobsBrother.executeForm(Shrub);
	bobsBrother.executeForm(Shrub);

    return 0;
}