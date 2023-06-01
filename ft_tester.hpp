#ifndef FT_TESTER_HPP
#define FT_TESTER_HPP

#include <iostream>
#include <typeinfo>
#include <string>
#include <type_traits>
#include "utils/is_integral.hpp"
#include <vector>
#include <array>
#include "vector.hpp"

template <typename T>
void empty_vector()
{
	std::cout << "vector empty constructor" << std::endl;
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

void range_vector()
{
	std::cout << "vector range constructor" << std::endl;
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
	std::cout << "vector iterator constructor" << std::endl;

	std::vector<int> vec(5, 8);
	std::vector<int>::iterator it;
	for (it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;	

	ft::vector<int> vec1(vec.begin(), vec.end());

	if (vec1.empty())
		std::cout << "iterator empty" << std::endl;
	else
		std::cout << "iterator not empty" << std::endl;
	ft::vector<int>::iterator it1;
	for (it1 = vec1.begin(); it1 != vec1.end(); ++it1)
		std::cout << *it1 << " ";
	std::cout << std::endl;

	std::cout << "***********************************" << std::endl;
	int arint[] = {3,4,6,2,3,8,9};
	ft::vector<int> vec2(arint, arint + (sizeof(arint) / sizeof(int)) );
	ft::vector<int>::iterator it2;

	for (it2 = vec2.begin(); it2 != vec2.end(); ++it2)
		std::cout << *it2 << " ";
	std::cout << std::endl;
}

void copy_vector()
{
	std::cout << "vector copy constructor" << std::endl;
	ft::vector<int> vec(4, 6);
	ft::vector<int> vec1(vec);

	ft::vector<int>::iterator it;
	for (it = vec1.begin(); it != vec1.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void assignment_vector()
{
	std::cout << "vector assignment constructor" << std::endl;
	ft::vector<int> vec(7, 2);
	ft::vector<int> vec1;

	vec1 = vec;
	ft::vector<int>::iterator it;
	for (it = vec1.begin(); it != vec1.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

}

void reverse_traverse()
{
	std::array<int, 7> myarr = {2, 4, 5, 6, 7, 8, 12};
	std::cout << "reverse iterator" << std::endl;
	ft::vector<int> vec(myarr.begin(), myarr.end());
	ft::vector<int>::reverse_iterator rit;
	for (rit = vec.rbegin(); rit != vec.rend();++rit)
		std::cout << *rit << " ";
}

void capacity_vector()
{
	std::cout << "vector capacity" << std::endl;
	ft::vector<int> vec(7, 2);
	std::cout << "size of vector is : " << vec.size() << std::endl;
	std::cout << "maximum size of vector is : " << vec.max_size() << std::endl;
	std::cout << "capacity of vector is : " << vec.capacity() << std::endl;
	vec.reserve(20);
	std::cout << "size of vector after reserve is : " << vec.size() << std::endl;
	std::cout << "maximum size of vector after reverser is : " << vec.max_size() << std::endl;
	std::cout << "capacity of vector after reserve is : " << vec.capacity() << std::endl;
}

void access_vector()
{
	std::cout << "vector element access" << std::endl;
	std::array<int, 7> myarr = {3, 44, 5, 32, 87, 23, 98};
	ft::vector<int> vec(myarr.begin(), myarr.end());
	std::cout << "************Access element using [] operator***********" << std::endl;
	// std::cout << "The fifth index element is: " << vec[5] << std::endl;
	// std::cout << "The tenth index element is: " << vec[10] << std::endl;
	std::cout << "************Access element using at ***********" << std::endl;
	try
	{
		std::cout << "The fifth index element is: " << vec.at(5) << std::endl;
		std::cout << "The tenth index element is: " << vec.at(10) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Index out of range" << std::endl;

	}
	std::cout << "The front element is " << vec.front() << std::endl;
	std::cout << "The back element is " << vec.back() << std::endl;
}

template <typename T>
void it_vec(ft::vector<T> vec)
{
	typename ft::vector<T>::iterator it = vec.begin();
	for (; it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void assign_vector()
{
	std::cout << "Assign vector" << std::endl;
	std::array<int, 6> myarr = {4, 6, 32, 76, 12, 88};

	ft::vector<int> vec;
	vec.assign(myarr.rbegin(), myarr.rend());
	ft::vector<int>::reverse_iterator it;
	for (it = vec.rbegin(); it != vec.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Assign range vector" << std::endl;
	ft::vector<int> vec1(6, 89);
	ft::vector<int>::iterator fit;
	for (fit = vec1.begin(); fit != vec1.end(); ++fit)
		std::cout << *fit << " ";
	std::cout << std::endl;
	std::cout << "Access push_back" << std::endl;
	vec1.push_back(53);
	vec1.push_back(583);
	it_vec<int>(vec1);
	std::cout << "Access pop_back" << std::endl;
	vec1.pop_back();
	vec1.pop_back();
	vec1.pop_back();
	it_vec<int>(vec1);
}

template <typename T>
void arr_assign_vector(T myarr[5], int n)
{

	std::cout << "Assign template vector" << std::endl;
	ft::vector<T> vec;
	vec.assign(myarr, myarr + n);
	typename ft::vector<T>::reverse_iterator it;
	for (it = vec.rbegin(); it != vec.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

}

void insert_vector(int val)
{
	std::cout << "Insert single element to vector" << std::endl;
	int myarr[5] = {3, 3,3,3,3};
	ft::vector<int> vec(myarr, myarr + 5);
	ft::vector<int>::iterator it;
	it_vec<int>(vec);
	vec.insert(vec.begin(), val);
	it_vec<int>(vec);
	std::cout << "Insert multiple elements to vector" << std::endl;
	vec.insert(vec.begin() + 5, 4, 55);
	it_vec<int>(vec);
	std::cout << "Insert range of elements to vector" << std::endl;
	int myarr1[] = {8,7,7,7,7};
	vec.insert(vec.begin() + 3, myarr1, myarr1 + 3);
	it_vec<int>(vec);
}

void erase_vector()
{
	std::cout << "Erase single element to vector" << std::endl;
	int myarr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	ft::vector<int> vec(myarr, myarr + 10);
	it_vec<int>(vec);
	vec.erase(vec.begin());
	it_vec<int>(vec);
	std::cout << "Erase multiple element to vector" << std::endl;
	vec.erase(vec.begin() + 3, vec.begin() + 6);
	it_vec<int>(vec);
}

void clear_vector()
{
	std::cout << "Erase single element to vector" << std::endl;
	int myarr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	ft::vector<int> vec(myarr, myarr + 10);
	it_vec<int>(vec);
	vec.clear();
	if (vec.empty())
		std::cout << "Vector cleared" << std::endl;
	else
		it_vec<int>(vec);

}

void swap_vector()
{
	std::cout << "Swap element of two vector" << std::endl;
	int myarr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int myarr2[10] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
	ft::vector<int> vec1(myarr1, myarr1 + 10);
	ft::vector<int> vec2(myarr2, myarr2 + 10);
	std::cout << "Before swap" << std::endl;
	it_vec<int>(vec1);
	it_vec<int>(vec2);
	std::cout << "After swap" << std::endl;
	vec1.swap(vec2);
	it_vec<int>(vec1);
	it_vec<int>(vec2);
}
#endif
