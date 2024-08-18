#include "MutantStack.hpp"

int main() {
	MutantStack<int> mstack;

	mstack.push(37);
	mstack.push(42);
	mstack.push(69);
	mstack.push(73);
	mstack.pop();

	std::cout << mstack.top() << std::endl;
	std::cout << mstack.size() << std::endl;

	MutantStack<int>::iterator itBegin = mstack.begin();
	MutantStack<int>::iterator itEnd = mstack.end();
	
	while (itBegin != itEnd) {
		std::cout << *itBegin << std::endl;
		itBegin++;
	}

	return 0;
}