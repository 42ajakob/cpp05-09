
#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>

class Array {
	private:
		T* _arr;
		unsigned int _sizeArr;

	public:
		Array();
		Array( unsigned int n );
		Array( const Array& other );
		Array& operator=( const Array& other );
		~Array();

		/* Functions */
		unsigned int size() const;

		/* Operators */
		T& operator[]( unsigned int n ) const;
};

#endif