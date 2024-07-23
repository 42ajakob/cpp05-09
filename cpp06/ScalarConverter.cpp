#include "Stupid.hpp"

Stupid::Stupid() {
	std::cout << "Stupid: Default constructor called" << std::endl;
}

Stupid::Stupid( const Stupid& other ) {
	std::cout << "Stupid: Copy constructor called" << std::endl;
	*this = other;
}

Stupid& Stupid::operator=( const Stupid& other ) {
	if (this != &other) {
		std::cout << "Stupid: Copy assignment operator called" << std::endl;
	}
	return *this;
}

Stupid::~Stupid() {
	std::cout << "Stupid: Deconstructor called" << std::endl;
}

static void Stupid::Stupidity() {
	std::cout << "Stupidity times 10" << std::endl;
}

static void ExtraStupid() {
	std::cout << "BECAUSE STUPIDITY IS NOT ENOUGH" << std::endl;
}