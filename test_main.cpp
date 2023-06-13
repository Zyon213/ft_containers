#include <iostream>
#include "containers/map.hpp"

int main()
{
	ft::map<int, int> map1;
	ft::map<int, int>::iterator it;

	map1[1] = 3;
	map1[2] = 3;
	map1[3] = 3;
	map1[4] = 3;
	map1[5] = 3;

	for (it = map1.begin(); it != map1.end(); ++it)
		std::cout << *it << std::endl;
	return (0);
}
