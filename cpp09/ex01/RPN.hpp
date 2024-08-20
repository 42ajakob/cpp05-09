#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib>
#include <limits>

class RPN {
	private:
		std::stack<int> intCon;
		std::string op;
		std::string c;
		int result;

		RPN( const RPN& other );
		RPN& operator=( const RPN& other );

		bool isOperator();
		bool isNum();
		int operation( int a, int b );

	public:
		RPN();
		~RPN();

		int getResult();
		void calculation( std::string line );
};

#endif