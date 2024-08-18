#ifndef Form_HPP
# define Form_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool _isSigned;
		const int _toSign;
		const int	_toGrade;

	public:
		/* Constructors */
		Form();
		Form( std::string name, int toSign, int toGrade );
		Form( const Form& other );
		Form& operator=( const Form& other );
		~Form();

		/* Getters */
		std::string getName() const;
		bool getIsSigned() const;
		int	getToSign() const;
		int getToGrade() const;

		/* Functions */
		void beSigned( Bureaucrat other );

		/* Exceptions */
		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};
};

std::ostream& operator<<( std::ostream& os, const Form& other );

#endif