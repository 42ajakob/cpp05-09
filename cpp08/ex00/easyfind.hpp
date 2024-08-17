#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>

template <typename T>
bool isContainerOfInt() {
    return std::is_same<typename T::value_type, int>::value;
}

template <typename T>
typename T::iterator easyfind( T& container, int i ) {
	typename T::iterator it = std::find(container.begin(), container.end(), i);

	if (it != container.end()) {
			return it;
	}
	std::cout << "Error: the number was not found in container!" << std::endl;
	std::cout << "Returning: 0!" << std::endl;
	return container.end();
}

#endif