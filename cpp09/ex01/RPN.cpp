#include "RPN.hpp"

/* Constructors */

RPN::RPN() : result(-1) {
}

RPN::RPN( const RPN& other ) {
	*this = other;
}

RPN& RPN::operator=( const RPN& other ) {
	if (this != &other) {
	}
	return *this;
}

RPN::~RPN() {
}

/* Getters */

int RPN::getResult() {
	return result;
}

/* Functions */

bool RPN::isNum() {
	if (c.empty())
		return false;

	for (size_t i = 0; i < c.length(); i++)
		if (!std::isdigit(c[i]))
			return false;

	double num = std::stod(c);
	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		return false;
	return true;
}

bool RPN::isOperator() {
	if (c != "+" && c != "-" && c != "*" && c != "/")
		return false;
	op = c;
	return true;
}

int RPN::operation( int a, int b) {
	if (op == "+")
		return a + b;
	else if (op == "-")
		return a - b;
	else if (op == "*")
		return a * b;
	else if (op == "/") {
		if (b == 0)
			return -1;
		return a / b;
	}
	return -1;
}

void RPN::calculation( std::string line ) {

	std::istringstream iss(line);

	while (iss >> c) {
		if (isNum()) {
			intCon.push(std::stoi(c));
		}
		else if (isOperator()) {
			if (intCon.size() < 2) {
				std::cerr << ("Error: Invalid amount of numbers for operation!") << std::endl;
				return ;
			}

			int b = intCon.top();
			intCon.pop();
			int a = intCon.top();
			intCon.pop();

			intCon.push(operation(a, b));
		}
		else {
			std::cerr << ("Error: Invalid character!") << std::endl;
			return ;
		}
	}
	if (intCon.size() != 1) {
		std::cerr << ("Error: Invalid amount of numbers for operation!") << std::endl;
		return ;
	}
	result = intCon.top();
}