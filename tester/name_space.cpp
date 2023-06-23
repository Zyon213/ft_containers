#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
#include <time.h>
#include <map>
#include <chrono>
#include "../containers/map.hpp"
#include "../containers/vector.hpp"

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
			double ms =  duration * 0.001;
			std::cout << "execution time is " << ms << " ms" << std::endl;
		}
};

int main()
{
	NAMESPACE::map<int, int> map_f;
	NAMESPACE::map<int, int>::iterator it_f;
	{
		std::cout << "***********************************************\n" ;
		{
			std::cout << "FT  (insert pair) ";
			Timer t;
			for (int i = 0; i < 100000; i++)
				map_f.insert(NAMESPACE::pair<int, int>(i, rand()));
		}

		std::cout << "***********************************************\n" ;
		{
			std::cout << "FT  (insert it pos) ";
			Timer t;
			map_f.insert(map_f.end(), NAMESPACE::pair<int, int>(122222, 545455));
		}
		std::cout << "***********************************************\n" ;
		{
			NAMESPACE::map<int, int> map_s1;
			map_s1[2144454] = 987684545;
			map_s1[2144455] = 98765545;
			map_s1[2144456] = 987645545;
			map_s1[2144457] = 987645545;
			map_s1[2144458] = 987645415;
			std::cout << "FT  (insert range) ";
			Timer t;
			map_f.insert(map_s1.begin(), map_s1.end());
		}
		std::cout << "***********************************************\n" ;
		{
			std::cout << "FT  (at) ";
			Timer t;
			map_f.at(100);
		}
		std::cout << "***********************************************\n" ;
		{
			std::cout << "FT  ([]) ";
			Timer t;
			map_f[5241];
		}
		std::cout << "***********************************************\n" ;
		{
			std::cout << "FT  (erase by key) ";
			Timer t;
			map_f.erase(12542);
		}
		std::cout << "***********************************************\n" ;
		{
			std::cout << "FT  (erase by iter) ";
			NAMESPACE::map<int, int>::iterator f_it = map_f.find(2154);
			Timer t;
			map_f.erase(f_it);
		}
		std::cout << "***********************************************\n" ;
		{
			std::cout << "FT  (erase by range) ";
			NAMESPACE::map<int, int>::iterator f_it1 = map_f.find(1);
			NAMESPACE::map<int, int>::iterator f_it2 = map_f.find(500);
			Timer t;
			map_f.erase(f_it1, f_it2);
		}
		std::cout << "***********************************************\n" ;
	}
	return (0);
}


