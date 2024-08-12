#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "OldClass/AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;

	public:
		/* Constructors */
		ShrubberyCreationForm();
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm& other );
		ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other );
		~ShrubberyCreationForm();

		/* Functions */
		void execute(Bureaucrat const & executor) const;
};

#endif