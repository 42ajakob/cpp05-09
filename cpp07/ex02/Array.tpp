#include "Array.hpp"

/* Constructor */

template <typename T>
Array<T>::Array() : _arr(new T[0]), _sizeArr(0) {

}

template <typename T>
Array<T>::Array( unsigned int n ) : _arr(new T[n]), _sizeArr(n) {

}

template <typename T>
Array<T>::Array( const Array& other ) {
	_sizeArr = other._sizeArr;
	_arr = new T[_sizeArr];

	for (unsigned int i = 0; i < _sizeArr; i++)
		_arr[i] = other._arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=( const Array& other ) {
	if (this != &other) {
		if (_arr) {
			delete[] _arr;
		}
		_sizeArr = other._sizeArr;
		_arr = new T[_sizeArr];

		for (unsigned int i = 0; i < _sizeArr; i++)
			_arr[i] = other._arr[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] _arr;
}

/* Functions */

template <typename T>
unsigned int Array<T>::size() const {
	return _sizeArr;
}

/* Operators */

template <typename T>
T&	Array<T>::operator[]( unsigned int n ) const {
	if ( n >= _sizeArr )
		throw std::out_of_range("Your out of bounce");
	return _arr[n];
}