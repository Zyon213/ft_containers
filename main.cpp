#include <iostream>
#include <list>
#include "vector.hpp"


template <typename T>
void it_vec(ft::vector<T> vec)
{
	typename ft::vector<T>::iterator it = vec.begin();
	for (; it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int		main(void)
{
	const int size = 5;
	// int size = 5;
	ft::vector<int> vct(size);
	ft::vector<int>::iterator it(vct.begin());
	ft::vector<int>::const_iterator ite(vct.end());

	for (int i = 1; it != ite; ++i)
		*it++ = i;
	it_vec(vct);

 	it = vct.begin();
	ite = vct.begin();

	std::cout << *(++ite) << std::endl;
	std::cout << *(ite++) << std::endl;
	std::cout << *ite++ << std::endl;
	std::cout << *++ite << std::endl;

	it->m();
	ite->m();

	std::cout << *(++it) << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *it++ << std::endl;
	std::cout << *++it << std::endl;

	std::cout << *(--ite) << std::endl;
	std::cout << *(ite--) << std::endl;
	std::cout << *--ite << std::endl;
	std::cout << *ite-- << std::endl;

	(*it).m();
	(*ite).m();

	std::cout << *(--it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *it-- << std::endl;
	std::cout << *--it << std::endl; 
	it_vec(vct);

	return (0);
}
