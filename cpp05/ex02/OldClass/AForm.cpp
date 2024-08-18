#include "AForm.hpp"

/* Constructor */

AForm::AForm() : _name("Default"), _isSigned(false), _toSign(150), _toGrade(150) {
}

AForm::AForm( std::string name, int toSign, int toGrade )
	: _name(name), _isSigned(false), _toSign(toSign), _toGrade(toGrade) {
	if (toSign < 1 || toGrade < 1) {
		throw GradeTooHighException();
	}
	else if (toSign > 150 || toGrade > 150) {
		throw GradeTooLowException();
	}
}

AForm::AForm( const AForm& other ) : _name(other._name), _isSigned(false), _toSign(other._toSign), _toGrade(other._toGrade) {
}

AForm& AForm::operator=( const AForm& other ) {
	if (this != &other) {
		this->_isSigned = other.getIsSigned();
	}
	return *this;
}

AForm::~AForm() {
}


/* Getters */

std::string AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

int AForm::getToSign() const {
	return _toSign;
}

int AForm::getToGrade() const {
	return _toGrade;
}


/* Functions */

void AForm::beSigned( Bureaucrat other ) {
	if (other.getGrade() > _toSign) {
		throw GradeTooLowException();
		return ;
	}
	_isSigned = true;
}


/* Exceptions */

const char* AForm::IsntSignedException::what() const throw() {
	return "is not signed";
}
const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}
const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}


/* Overload */

std::ostream& operator<<( std::ostream& os, const AForm& other ) {
	os << "AForm: " << other.getName()
	<< ", signed " << other.getIsSigned()
	<< ", to sign " << other.getToSign()
	<< ", to grade " << other.getToGrade();
	return os;
}