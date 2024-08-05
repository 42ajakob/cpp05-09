#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name) {
	std::cout << "Bureaucrat: Default constructor called" << std::endl;
	if (grade > 150) {
        std::cout << "Bureaucrat::GradeTooLowException" << std::endl;
    }
    else if (grade < 1) {
        std::cout << "Bureaucrat::GradeTooHighException" << std::endl;
    }
    else {
        _grade = grade;
    }
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) {
	std::cout << "Bureaucrat: Copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other ) {
	if (this != &other) {
		std::cout << "Bureaucrat: Copy assignment operator called" << std::endl;
		this->~Bureaucrat();
        new (this) Bureaucrat(other.getName(), other.getGrade());
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat: Deconstructor called" << std::endl;
}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1) {
        throw MyException();
		std::cout << "Bureaucrat::GradeTooHighException" << std::endl;
	}
    else
        _grade -= 1;
}

void Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150) {
		throw MyException();
		std::cout << "Bureaucrat::GradeTooLowException" << std::endl;
	}
    else
        _grade += 1;
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& other ) {
    os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
    return os;
}