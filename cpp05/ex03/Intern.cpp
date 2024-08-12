#include "Intern.hpp"

/* Constructor */

Intern::Intern() {
	_formName[0] = "Shrubbery";
	_formName[1] = "Robotomy";
	_formName[2] = "Presidential";
}

Intern::Intern( const Intern& other ) {
	(void)other;
}

Intern& Intern::operator=( const Intern& other ) {
	if (this != &other) {
		
	}
	return *this;
}

Intern::~Intern() {
}

/* Functions */

AForm*	Intern::makeForm(std::string formName, std::string formTarget) {
	AForm* form = NULL;
	int i = 0;

	while (i < 3) {
		if (formName == _formName[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			break;
		}
		i++;
	}
	switch (i) {
		case 0:
			form = new ShrubberyCreationForm(formTarget);
			break ;
		case 1:
			form = new RobotomyRequestForm(formTarget);
			break ;
		case 2:
			form = new PresidentialPardonForm(formTarget);
			break ;
		default:
			std::cout << "Form " << formName << " doesn't exist!" << std::endl;
	}
	return form;
}