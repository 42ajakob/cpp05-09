#ifndef INTERN_HPP
# define INTERN_HPP

#include "OldClass/AForm.hpp"
#include "OldClass/ShrubberyCreationForm.hpp"
#include "OldClass/RobotomyRequestForm.hpp"
#include "OldClass/PresidentialPardonForm.hpp"

class AForm;

class Intern {
	private:
		std::string _formName[3];

	public:
		/* Constructors */
		Intern();
		Intern( const Intern& other );
		Intern& operator=( const Intern& other );
		~Intern();

		/* Functions */
		AForm*	makeForm(std::string formName, std::string formTarget);
};

#endif