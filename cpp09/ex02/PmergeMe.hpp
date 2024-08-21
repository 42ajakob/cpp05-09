#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <algorithm>

#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>

class PmergeMe {
	private:
		std::vector<int> vecCon;
		std::deque<int> deqCon;

		PmergeMe( const PmergeMe& other );
		PmergeMe& operator=( const PmergeMe& other );

		std::vector<int> mergeConVec( std::vector<int> left, std::vector<int> right );
		std::deque<int> mergeConDeq( std::deque<int> left, std::deque<int> right );
		std::vector<int> recSplitVecCon( std::vector<int> con );
		std::deque<int> recSplitDeqCon( std::deque<int> con );

	public:
		PmergeMe();
		~PmergeMe();

		void addNumVec( int num );
		void addNumDeq( int num );
		void timerForVec();
		void timerForDeq();
};

#endif