#ifndef TESTER_HPP
#define TESTER_HPP

#include <iostream>
#include <typeinfo>
#include <string>
#include <type_traits>
#include "utils/is_integral.hpp"
#include <vector>
#include <array>
#include "vector.hpp"

/* 
int
float
double
char
wchar_t
bool
void
signed int
unsigned int
short
unsigned short
long
unsigned long
long long
unsigned long
long long
unsigned long long
long double
signed char
unsigned char 
*/


template <typename T>
void empty_vector()
{
	{	
		T t;
		std::vector<T> vec;
		std::cout << typeid(t).name() << " ";
		if (vec.empty())
			std::cout << "Empty" << "\t\t";
		else
			std::cout << "Not Empty" << "\t\t";
	}
	{	
		T t;
		ft::vector<T> vec;
		std::cout << typeid(t).name() << " ";
		if (vec.empty())
			std::cout << "Empty" << "\t\t";
		else
			std::cout << "Not Empty" << "\t\t";
	}
	std::cout << std::endl;
}

void is_empty_vector()
{
	empty_vector<int>();
	empty_vector<float>();
	empty_vector<double>();
	empty_vector<char>();
	empty_vector<wchar_t>();
	empty_vector<bool>();
	empty_vector<signed int>();
	empty_vector<unsigned int>();
	empty_vector<short>();
	empty_vector<unsigned short>();
	empty_vector<long>();
	empty_vector<unsigned long>();
	empty_vector<long long>();
	empty_vector<unsigned long long>();
	empty_vector<long double>();
	empty_vector<signed char>();
	empty_vector<unsigned char>();
}

void ft_vector()
{

}

void range_vector()
{
	{
		std::vector<int> vec;
		std::vector<int> vec1(4,3);
		std::vector<int>::iterator it;
		for (it = vec1.begin(); it != vec1.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}	
	{
		ft::vector<int> vec;
		ft::vector<int> vec1(4,3);
		ft::vector<int>::iterator it;
		for (it = vec1.begin(); it != vec1.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
}

void iterator_vector()
{
	// {		
	// 	std::vector<int> vec(5, 8);
	// 	std::vector<int> vec1(vec.begin(), vec.end());
	// 	std::vector<int>::iterator it;
	// 	for (it = vec1.begin(); it != vec1.end(); ++it)
	// 		std::cout << *it << " ";
	// 	std::cout << std::endl;
	// }
	{		
		ft::vector<int> vec(5, 8);
		if (vec.empty())
			std::cout << "range empty" << std::endl;
		else
			std::cout << "range not empty" << std::endl;

		ft::vector<int> vec1(vec.begin(), vec.end());
		if (vec1.empty())
			std::cout << "iterator empty" << std::endl;
		else
			std::cout << "iterator not empty" << std::endl;
		// ft::vector<int>::iterator it;
		// for (it = vec1.begin(); it != vec1.end(); ++it)
		// 	std::cout << *it << " ";
		// std::cout << std::endl;
	}
}

#endif