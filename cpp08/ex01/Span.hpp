#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <random>

class Span {
	private:
		std::vector<int> _integers;
		unsigned int _size;

		Span();
		Span( const Span& other );
		Span& operator=( const Span& other );

	public:
		Span( unsigned int n );
		~Span();

		void addNumber( unsigned int i );
		int shortestSpan() const;
		int longestSpan() const;

		void fillSpan();

		class spanFull : public std::exception
		{
			virtual const char* what() const throw();
		};
		class notEnoughInts : public std::exception
		{
			virtual const char* what() const throw();
		};
};

#endif