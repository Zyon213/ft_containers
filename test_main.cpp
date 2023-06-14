#include <iostream>
#include "containers/map.hpp"
#include <map>
#include <vector>
#include <string>

int main()
{
	ft::map<char, int> map1;
	ft::map<char, int>::iterator it;

	map1['a'] = 3;
	map1['b'] = 3;
	map1['c'] = 3;
	map1['d'] = 3;
	map1['e'] = 3;

	for (it = map1.begin(); it != map1.end(); ++it)
		std::cout << it->second << std::endl;
	return (0);
}

