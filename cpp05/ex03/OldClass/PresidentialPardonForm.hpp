#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;

	public:
		/* Constructors */
		PresidentialPardonForm();
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( const PresidentialPardonForm& other );
		PresidentialPardonForm& operator=( const PresidentialPardonForm& other );
		~PresidentialPardonForm();

		/* Functions */
		void execute(Bureaucrat const & executor) const;
};

#endif