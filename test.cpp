#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
#include <time.h>
#include <map>
#include "containers/map.hpp"

int main()
{
	{
		ft::map<int, int> map1;
		ft::map<int, int>::iterator it;
		size_t sum = 0;
		for (int i = 0; i < 10000; i++)
			map1.insert(ft::pair<int, int>(i, rand()));
		
		for (it = map1.begin(); it != map1.end(); ++it)
		{
			std::cout << it->first << " -> " << it->second << std::endl;
			sum += it->second;
		}
		std::cout << "The sum of value is " << sum << std::endl;
	}
	return (0);
}

/* int main()
{


	std::cout << "Initializing using large elements " << std::endl;
	std::vector<int> vec;
	std::vector<int>::iterator vit;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
		// std::cout << vec[i] << std::endl;

	}
	
	// Execution time using clock
	ft::map<int, int> map8;
	ft::map<int, int>::iterator it;



	for (vit = vec.begin(); vit != vec.end(); ++vit)
		map8.insert(ft::pair<int, int>(*vit, *vit));

	for (it = map8.begin(); it != map8.end(); ++it)
		std::cout << it->second << std::endl;
	

	// std::map<int, int> map9;

	// for (vit = vec.begin(); vit != vec.end(); ++vit)
	// 	map9.insert(std::pair<int, int>(*vit, *vit));

	return (0);
} */