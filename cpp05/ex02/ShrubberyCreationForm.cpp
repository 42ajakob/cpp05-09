#include "ShrubberyCreationForm.hpp"

/* Constructor */

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 72, 45) {
	_target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("Shrubbery", 72, 45) {
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) : AForm("Shrubbery", 72, 45) {
	_target = other._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other ) {
	if (this != &other) {
		this->~ShrubberyCreationForm();
        new (this) ShrubberyCreationForm(other._target);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}


/* Functions */

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned() == false) {
		throw IsntSignedException();
	}
	else if (executor.getGrade() > this->getToGrade()) {
		throw GradeTooLowException();
	}
	else {
		std::ofstream outfile((_target + "_shrubbery").c_str());
		if (outfile.is_open()) {
    	    outfile << "     ccee88oo          " << std::endl;
			outfile << "  C8O8O8Q8PoOb o8oo    " << std::endl;
			outfile << " dOB69QO8PdUOpugoO9bD  " << std::endl;
			outfile << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
			outfile << "   6OuU  /p u gcoUodpP " << std::endl;
			outfile << "      \\\\//  /douUP   " << std::endl;
			outfile << "        \\\\////       " << std::endl;
			outfile << "         |||/\\        " << std::endl;
			outfile << "         |||\\/        " << std::endl;
			outfile << "         |||||         " << std::endl;
			outfile << "  .....\\//||||\\....  " << std::endl;
    	    outfile.close();
		}
		else {
        	std::cout << "Unable to open file." << std::endl;
    	}
	}
}