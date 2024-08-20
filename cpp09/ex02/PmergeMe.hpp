#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib>
#include <limits>

class PmergeMe {
	private:
		std::stack<int> intCon;
		std::string op;
		std::string c;
		int result;

		PmergeMe( const PmergeMe& other );
		PmergeMe& operator=( const PmergeMe& other );

	public:
		PmergeMe();
		~PmergeMe();

		int getResult();
};

#endif