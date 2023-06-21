#include <iostream>
#include <iostream>
#include <ctime>
#include <map>
#include <iomanip>
#include <vector>
#include <climits>
#include "../containers/map.hpp"

template<typename T>
void exec_time(T t2, T t1, int n)
{
	if (n == 1)
	{
		double t = static_cast<double>(t2 - t1) / static_cast<double>(CLOCKS_PER_SEC);
		std::cout << "STD map execution time is " << std::setprecision(8) << t << std::endl;
	}
	else
	{
		double t = static_cast<double>(t2 - t1) / static_cast<double>(CLOCKS_PER_SEC);
		std::cout << "FT map execution time is " << std::setprecision(8) << t << std::endl;
	}
}

int main()
{
	std::cout << "Initializing using large elements " << std::endl;
	std::vector<int> vec;
	std::vector<int>::iterator vit;
	for (int i = 0; i < INT_MAX / 1000; i++)
		vec.push_back(i);
	
	std::clock_t tm1 = clock();
	ft::map<int, int> map8;
	for (vit = vec.begin(); vit != vec.end(); ++vit)
		map8.insert(ft::pair<int, int>(*vit, *vit));
	std::clock_t tm2 = clock();
	exec_time(tm2, tm1, 2);

	tm1 = clock();
	std::map<int, int> map9;
	for (vit = vec.begin(); vit != vec.end(); ++vit)
		map9.insert(std::pair<int, int>(*vit, *vit));
	tm2 = clock();
	exec_time(tm2, tm1, 1);
	return (0);

}