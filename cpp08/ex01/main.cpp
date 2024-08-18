#include "Span.hpp"

int main()
{
	std::cout << "|| SPAN ||" << std::endl;
	Span sp(5);

	// 17 - 3 = 14
	// 11 - 9 = 2
	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9); 
		sp.addNumber(11);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		sp.addNumber(42);
		std::cout << "THIS TEXT DOES NOT APPEAR" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		sp.addNumber(42);
		std::cout << "THIS TEXT DOES NOT APPEAR" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}



	std::cout << "|| SPAN1 ||" << std::endl;
	Span sp1(2);

	try {
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9); 
		sp1.addNumber(11);
		
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << sp1.shortestSpan() << std::endl;
		std::cout << sp1.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "|| SPAN2 ||" << std::endl;
	Span sp2(5);

	try {
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	


	std::cout << "|| SPAN3 ||" << std::endl;
	Span sp3(1);

	try {
		sp3.addNumber(6);
		sp3.addNumber(3);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << sp3.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << sp3.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}



	Span sp4(15000);
	sp4.fillSpan();

	try {
		std::cout << sp4.shortestSpan() << std::endl;
		std::cout << sp4.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}