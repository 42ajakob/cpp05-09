#include "easyfind.hpp"

int main() {
	int container[] = {37, 42, 69};
	size_t size(sizeof(container) / sizeof(int));

	std::vector<int> intVect(container, container + size);

	std::vector<int>::iterator it = easyfind(intVect, 42);
	std::cout << "Found: " << *it << std::endl;

	std::vector<int>::iterator it2 = easyfind(intVect, 73);
	std::cout << "Found: " << *it2 << std::endl;
	
    return 0;
}