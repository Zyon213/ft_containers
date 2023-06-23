#include <iostream>
#include <iostream>
#include <ctime>
#include <map>
#include <iomanip>
#include <vector>
#include <climits>
#include <chrono>
#include "../containers/map.hpp"

class Timer
{
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> _start;
		std::chrono::time_point<std::chrono::high_resolution_clock> _end;
	public:
		Timer()
		{
			_start = std::chrono::high_resolution_clock::now();
		}
		~Timer()
		{
			stop();
		}
		void stop()
		{
			_end = std::chrono::high_resolution_clock::now();
			auto start_t = std::chrono::time_point_cast<std::chrono::microseconds>(_start).time_since_epoch().count();
			auto end_t = std::chrono::time_point_cast<std::chrono::microseconds>(_end).time_since_epoch().count();

			auto duration = end_t - start_t;
			double ms = duration * 0.000001;
			std::cout << "Execution time is " << ms << std::endl;
		}
};

template<typename T>
void exec_time(T t2, T t1, int n)
{
	double t = static_cast<double>(t2 - t1) / static_cast<double>(CLOCKS_PER_SEC);
	if (n == 1)
		std::cout << "STD map execution time is " << std::setprecision(8) << t << std::endl;
	else
		std::cout << "FT map execution time is " << std::setprecision(8) << t << std::endl;
}

template<typename U>
void chron_time(U u2, U u1, int n)
{
	auto exec_time = std::chrono::duration_cast<std::chrono::nanoseconds>(u2 - u1).count() * 1e-9;
	if (n == 1)
		std::cout << "STD map execution time is " << std::setprecision(6) << exec_time << std::endl;
	else
		std::cout << "FT map execution time is " << std::setprecision(6) << exec_time << std::endl;
}

template<typename V>
void chron_exet(V v2, V v1, int n, int rep = 100)
{
	auto et{std::chrono::duration_cast<std::chrono::microseconds>(v2 - v1).count()};
	float exect{ et/static_cast<float>(rep)};
	if (n == 1)
		std::cout << "STD map execution time is " << std::setprecision(6) << exect << std::endl;
	else
		std::cout << "FT map execution time is " << std::setprecision(6) << exect << std::endl;
}

int main()
{
	std::cout << "Initializing using large elements " << std::endl;
	std::vector<int> vec;
	std::vector<int>::iterator vit;
	for (int i = 0; i < INT_MAX / 1000; i++)
		vec.push_back(i);
	
	// Execution time using clock
	ft::map<int, int> map8;
	std::clock_t tm1 = clock();
	for (vit = vec.begin(); vit != vec.end(); ++vit)
		map8.insert(ft::pair<int, int>(*vit, *vit));
	std::clock_t tm2 = clock();
	exec_time(tm2, tm1, 2);

	std::map<int, int> map9;
	tm1 = clock();
	for (vit = vec.begin(); vit != vec.end(); ++vit)
		map9.insert(std::pair<int, int>(*vit, *vit));
	tm2 = clock();
	exec_time(tm2, tm1, 1);

	// Execution time using chrono
	ft::map<int, int> map10;
	auto ch1 = std::chrono::high_resolution_clock::now();
	for (vit = vec.begin(); vit != vec.end(); ++vit)
		map10.insert(ft::pair<int, int>(*vit, *vit));
	auto  ch2 = std::chrono::high_resolution_clock::now();
	chron_time(ch2, ch1, 2);

	std::map<int, int> map11;
	ch1 = std::chrono::high_resolution_clock::now();
	for (vit = vec.begin(); vit != vec.end(); ++vit)
		map11.insert(std::pair<int, int>(*vit, *vit));
	ch2 = std::chrono::high_resolution_clock::now();
	chron_time(ch2, ch1, 1);


	// Execution time using class
	{
		ft::map<int, int> map10;
		Timer t;
		for (vit = vec.begin(); vit != vec.end(); ++vit)
			map10.insert(ft::pair<int, int>(*vit, *vit));
		std::cout << "FT ";
	}
	{
		std::map<int, int> map11;
		Timer t;
		for (vit = vec.begin(); vit != vec.end(); ++vit)
			map11.insert(std::pair<int, int>(*vit, *vit));
		std::cout << "STD ";

	}


	return (0);

}