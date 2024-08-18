#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
typename T::iterator easyfind( T& container, int i ) {
	typename T::iterator it = std::find(container.begin(), container.end(), i);

	if (it != container.end()) {
			return it;
	}
	throw std::runtime_error("Error: Failed to find ");
}

#endif