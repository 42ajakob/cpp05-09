#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool _isSigned;
		const int _toSign;
        const int	_toGrade;

	public:
		/* Constructors */
		AForm();
        AForm( std::string name, int toSign, int toGrade );
		AForm( const AForm& other );
		AForm& operator=( const AForm& other );
		virtual ~AForm();

		/* Getters */
        std::string getName() const;
        bool getIsSigned() const;
		int	getToSign() const;
		int getToGrade() const;

		/* Functions */
		void beSigned( Bureaucrat other );
		virtual void execute(Bureaucrat const & executor) const = 0;

		/* Exceptions */
		class IsntSignedException : public std::exception {
			const char* what() const throw();
		};
		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};
};

std::ostream& operator<<( std::ostream& os, const AForm& other );

#endif