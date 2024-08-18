#include "PresidentialPardonForm.hpp"

/* Constructor */

PresidentialPardonForm::PresidentialPardonForm() : AForm("President", 25, 5) {
	_target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("President", 25, 5) {
	_target = target;
}

// This is retarded
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) : AForm("President", 25, 5) {
	_target = other._target;
}

// This as well
PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& other ) {
	if (this != &other) {
		this->~PresidentialPardonForm();
		new (this) PresidentialPardonForm(other._target);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}


/* Functions */

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned() == false) {
		throw IsntSignedException();
	}
	else if (executor.getGrade() > this->getToGrade()) {
		throw GradeTooLowException();
	}
	else {
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}