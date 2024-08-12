#include "Bureaucrat.hpp"

/* Constructor */

Bureaucrat::Bureaucrat() {
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade) {
	if (grade < 1) {
        throw GradeTooHighException();
    }
	else if (grade > 150) {
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) {
	*this = other;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other ) {
	if (this != &other) {
		this->~Bureaucrat();
        new (this) Bureaucrat(other._name, other._grade);
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
}


/* Getters */

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}


/* Functions */

void Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1) {
        throw GradeTooHighException();	}
    else
        _grade -= 1;
}

void Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150) {
		throw GradeTooLowException();
	}
    else
        _grade += 1;
}


/* Exceptions */

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}


/* Overload */

std::ostream& operator<<( std::ostream& os, const Bureaucrat& other ) {
    os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
    return os;
}