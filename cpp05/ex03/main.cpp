#include "OldClass/Bureaucrat.hpp"
#include "OldClass/AForm.hpp"
#include "OldClass/ShrubberyCreationForm.hpp"
#include "OldClass/RobotomyRequestForm.hpp"
#include "OldClass/PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    
	/* Constructor */
    Bureaucrat Steve("Steve", 1);
	Bureaucrat Alex("Alex", 150);

	/* execute without it be signed */
	Intern someRandomIntern;
	AForm* form;

	form = someRandomIntern.makeForm("Robotomy", "Bender");
	if (form) {
		std::cout << *form << std::endl;
		delete form;
	}
    return 0;
}