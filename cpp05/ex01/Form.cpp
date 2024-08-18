#include "Form.hpp"

/* Constructor */

Form::Form() : _name("Default"), _isSigned(false), _toSign(150), _toGrade(150) {
}

Form::Form( std::string name, int toSign, int toGrade )
	: _name(name), _isSigned(false), _toSign(toSign), _toGrade(toGrade) {
	if (toSign < 1 || toGrade < 1) {
		throw GradeTooHighException();
	}
	else if (toSign > 150 || toGrade > 150) {
		throw GradeTooLowException();
	}
}

Form::Form( const Form& other ) : _name(other._name), _isSigned(false), _toSign(other._toSign), _toGrade(other._toGrade) {
}

Form& Form::operator=( const Form& other ) {
	if (this != &other) {
		this->~Form();
		new (this) Form(other._name, other._toSign, other._toGrade);
	}
	return *this;
}

Form::~Form() {
}


/* Getters */

std::string Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

int Form::getToSign() const {
	return _toSign;
}

int Form::getToGrade() const {
	return _toGrade;
}


/* Functions */

void Form::beSigned( Bureaucrat other ) {
	if (other.getGrade() > _toSign) {
		throw GradeTooLowException();
		return ;
	}
	_isSigned = true;
}


/* Exceptions */

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}
const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}


/* Overload */

std::ostream& operator<<( std::ostream& os, const Form& other ) {
	os << "Form: " << other.getName()
	<< ", signed " << other.getIsSigned()
	<< ", to sign " << other.getToSign()
	<< ", to grade " << other.getToGrade();
	return os;
}