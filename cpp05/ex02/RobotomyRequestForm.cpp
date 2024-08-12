#include "RobotomyRequestForm.hpp"

/* Constructor */

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 145, 137) {
	_target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("Robotomy", 145, 137) {
	_target = target;
}

// This is retarded
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) : AForm("Robotomy", 145, 137) {
	_target = other._target;
}

// This as well
RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& other ) {
	if (this != &other) {
		this->~RobotomyRequestForm();
        new (this) RobotomyRequestForm(other._target);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}


/* Functions */

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned() == false) {
		throw IsntSignedException();
	}
	else if (executor.getGrade() > this->getToGrade()) {
		throw GradeTooLowException();
	}
	else {
		int i = std::rand() % 2; // Worst RNG I ever seen. Too bad!
		std::cout << "some drilling noises..." << std::endl;
		if (i == 1) {
			std::cout << _target << " has been robotomized successfully" << std::endl;
		}
		else {
			std::cout << "The robotomy failed" << std::endl;
		}
	}
}