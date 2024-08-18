#include "Span.hpp"

/* Constructors */

Span::Span() {
}

Span::Span( unsigned int n ) : _size(n) {
	_integers.reserve(n);
}

Span::Span( const Span& other ) {
	*this = other;
}

Span& Span::operator=( const Span& other ) {
	if (this != &other) {
	}
	return *this;
}

Span::~Span() {
}


/* Exceptions */

const char* Span::spanFull::what() const throw()
{
	return "Span is full!";
}

const char* Span::notEnoughInts::what() const throw()
{
	return "Not enough numbers to find a span!";
}


/* Functions */

void Span::addNumber( unsigned int i ) {
	if (_integers.size() == _size) 
		throw spanFull();
	else
		_integers.push_back(i);
}

int Span::shortestSpan() const {
	if (_integers.size() < 2)
		throw notEnoughInts();

	std::vector<int> sortedNumbers = _integers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int shortest = sortedNumbers[1] - sortedNumbers[0];

	for (size_t i = 2; i < sortedNumbers.size(); ++i) {
		int span = sortedNumbers[i] - sortedNumbers[i - 1];

		if (span < shortest) {
			shortest = span;
		}
	}
	return shortest;
}

int Span::longestSpan() const {
	if (_integers.size() < 2)
		throw notEnoughInts();

	auto minMax = std::minmax_element(_integers.begin(), _integers.end());
	return *minMax.second - *minMax.first;
}

void Span::fillSpan() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, _size + 1000000);

	while (_integers.size() < _size) {
		_integers.push_back(dis(gen));
	}
}