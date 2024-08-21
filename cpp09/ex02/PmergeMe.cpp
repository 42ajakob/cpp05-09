#include "PmergeMe.hpp"

/* Constructors */

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe( const PmergeMe& other ) {
	*this = other;
}

PmergeMe& PmergeMe::operator=( const PmergeMe& other ) {
	if (this != &other) {
	}
	return *this;
}

PmergeMe::~PmergeMe() {
}

/* Functions */

void PmergeMe::addNumVec( int num ) {
	vecCon.push_back(num);
}

void PmergeMe::addNumDeq( int num ) {
	deqCon.push_back(num);
}

std::vector<int> PmergeMe::mergeConVec( std::vector<int> left, std::vector<int> right ) {

	std::vector<int> res;
	std::vector<int>::iterator itL = left.begin();
	std::vector<int>::iterator itR = right.begin();

	while (itL != left.end() && itR != right.end()) {
		if (*itL < *itR) {
			res.push_back(*itL);
			itL++;
		}
		else {
			res.push_back(*itR);
			itR++;
		}
	}
	res.insert(res.end(), itL, left.end());
	res.insert(res.end(), itR, right.end());
	return res;
}

std::deque<int> PmergeMe::mergeConDeq( std::deque<int> left, std::deque<int> right ) {

	std::deque<int> res;
	std::deque<int>::iterator itL = left.begin();
	std::deque<int>::iterator itR = right.begin();

	while (itL != left.end() && itR != right.end()) {
		if (*itL < *itR) {
			res.push_back(*itL);
			itL++;
		}
		else {
			res.push_back(*itR);
			itR++;
		}
	}
	res.insert(res.end(), itL, left.end());
	res.insert(res.end(), itR, right.end());
	return res;
}

std::vector<int> PmergeMe::recSplitVecCon( std::vector<int> con ) {
	if (con.size() < 2)
		return con;

	std::vector<int> left;
	std::vector<int> right;
	size_t half = con.size() / 2;

	std::copy(con.begin(), con.begin() + half, std::back_inserter(left));
	std::copy(con.begin() + half, con.end(), std::back_inserter(right));

	left = recSplitVecCon(left);
	right = recSplitVecCon(right);

	return mergeConVec(left, right);
}

std::deque<int> PmergeMe::recSplitDeqCon( std::deque<int> con ) {
	if (con.size() < 2)
		return con;

	std::deque<int> left;
	std::deque<int> right;
	size_t half = con.size() / 2;

	std::copy(con.begin(), con.begin() + half, std::back_inserter(left));
	std::copy(con.begin() + half, con.end(), std::back_inserter(right));

	left = recSplitDeqCon(left);
	right = recSplitDeqCon(right);

	return mergeConDeq(left, right);
}

void PmergeMe::timerForVec() {
	std::clock_t start = std::clock();
	vecCon = recSplitVecCon(vecCon);
	std::clock_t end = std::clock();

	std::cout << "After: ";
	for (size_t i = 0; i < vecCon.size(); i++)
		std::cout << vecCon[i] << " "; 
	std::cout << std::endl;

	double elapsed = double(end - start) / CLOCKS_PER_SEC;

	std::cout << "Time elapsed for Vec: " << std::fixed << std::setprecision(6) << elapsed << std::endl;
}

void PmergeMe::timerForDeq() {
	std::clock_t start = std::clock();
	deqCon = recSplitDeqCon(deqCon);
	std::clock_t end = std::clock();

	double elapsed = double(end - start) / CLOCKS_PER_SEC;

	std::cout << "Time elapsed for Deq: " << std::fixed << std::setprecision(6) << elapsed << std::endl;
}