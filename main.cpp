#include <iostream>
#include <list>
#include "vector.hpp"
#include <vector>


#define TESTED_TYPE int
template <typename T>
void it_vec(ft::vector<T> vec)
{
	typename ft::vector<T>::iterator it = vec.begin();
	for (; it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename T>
void it_vec_std(std::vector<T> vec)
{
	typename std::vector<T>::iterator it = vec.begin();
	for (; it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}


int		main(void)
{
	{
		const int size = 5;
		ft::vector<TESTED_TYPE> vct(size);
		ft::vector<TESTED_TYPE>::reverse_iterator it = vct.rbegin();
		ft::vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();

		for (int i = 0; i < size; ++i)
			it[i] = (size - i) * 5;

		it = it + 5;
		it = 1 + it;
		it = it - 4;
		std::cout << *(it += 2) << std::endl;
		std::cout << *(it -= 1) << std::endl;

		*(it -= 2) = 42;
		*(it += 2) = 21;

		std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

		std::cout << "(it == const_it): " << (ite == it) << std::endl;
		std::cout << "(const_ite - it): " << (ite - it) << std::endl;
		std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

		it_vec(vct);
	}
		std::cout << "*********************************************" << std::endl;

	{
		const int size = 5;
		std::vector<TESTED_TYPE> vct(size);
		std::vector<TESTED_TYPE>::reverse_iterator it = vct.rbegin();
		std::vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();

		for (int i = 0; i < size; ++i)
			it[i] = (size - i) * 5;

		it = it + 5;
		it = 1 + it;
		it = it - 4;
		std::cout << *(it += 2) << std::endl;
		std::cout << *(it -= 1) << std::endl;

		*(it -= 2) = 42;
		*(it += 2) = 21;

		std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

		std::cout << "(it == const_it): " << (ite == it) << std::endl;
		std::cout << "(const_ite - it): " << (ite - it) << std::endl;
		std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

		it_vec_std(vct);
	}
	return (0);
}