#include <map>
#include "containers/map.hpp"
#include <iostream>

int main()
{
	NAMESPACE::map<int, int> map1;
	NAMESPACE::map<int, int>::iterator it;

	map1[2] = 354;
	map1[3] = 554;
	map1[5] = 324;
	map1[6] = 24;

	for (it = map1.begin(); it != map1.end(); ++it)
		std::cout << it->first << " => " << it->second ;
	std::cout << std::endl;
	return (0);
}
