#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
	private:
		const std::string	_name;
        int	_grade;

	public:
		/* Constructors */
		Bureaucrat();
        Bureaucrat( std::string name, int grade );
		Bureaucrat( const Bureaucrat& other );
		Bureaucrat& operator=( const Bureaucrat& other );
		~Bureaucrat();

		/* Getters */
        std::string getName() const;
        int getGrade() const;

		/* Functions */
        void incrementGrade();
        void decrementGrade();

		/* Exceptions */
		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& other );

#endif