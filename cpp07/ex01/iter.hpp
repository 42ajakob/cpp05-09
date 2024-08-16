#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>

void iter( T *arr, size_t length, void (*func)(T&) ) {
	if (arr == NULL || length == 0 || func == NULL)
		return ;
	for (size_t i = 0; i < length; i++)
		func(arr[i]);
}

template <typename T>

void iter( T *arr, size_t length, void (*func)(const T&) ) {
	if (arr == NULL || length == 0 || func == NULL)
		return ;
	for (size_t i = 0; i < length; i++)
		func(arr[i]);
}

#endif