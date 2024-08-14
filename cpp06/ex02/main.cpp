#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
	std::srand(static_cast<unsigned int>(std::time(0)));
	int i = std::rand() % 3;

	switch (i) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p) {
	std::cout << "Pointer: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
	else if (p == NULL)
		std::cout << "is NULL!";
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Pointer: A" << std::endl;
		return ;
	}
	catch (const std::exception &e) {
	}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Pointer: B" << std::endl;
		return ;
	}
	catch (const std::exception &e) {
	}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Pointer: C" << std::endl;
		return ;
	}
	catch (const std::exception &e) {
	}
}

int main() {
	Base* ptr = generate();

	identify(ptr);
	identify(*ptr);

	delete ptr;
    return 0;
}