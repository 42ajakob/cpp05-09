#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include "OldClass/AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;

	public:
		/* Constructors */
		RobotomyRequestForm();
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm& other );
		RobotomyRequestForm& operator=( const RobotomyRequestForm& other );
		~RobotomyRequestForm();

		/* Functions */
		void execute(Bureaucrat const & executor) const;
};

#endif