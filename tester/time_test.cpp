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
	ft::map<int, int> map_f;
	ft::map<int, int>::iterator it_f;
	std::map<int, int> map_s;
	std::map<int, int>::iterator it_s;
	{
		std::cout << "***********************************************\n" ;
		{
			std::cout << "FT  (insert pair) ";
			Timer t;
			for (int i = 0; i < 100000; i++)
				map_f.insert(ft::pair<int, int>(i, rand()));
		}
		{
			std::cout << "STD (insert pair) ";
			Timer t;
			for (int i = 0; i < 100000; i++)
				map_s.insert(std::pair<int, int>(i, rand()));
		}
		std::cout << "***********************************************\n" ;
		{
			std::cout << "FT  (insert it pos) ";
			Timer t;
			map_f.insert(map_f.end(), ft::pair<int, int>(122222, 545455));
		}
		{
			std::cout << "STD (insert it pos) ";
			Timer t;
			map_s.insert(map_s.end(), std::pair<int, int>(122222, 545455));
		}
		std::cout << "***********************************************\n" ;
		{
			ft::map<int, int> map_s1;
			map_s1[2144454] = 987684545;
			map_s1[2144455] = 98765545;
			map_s1[2144456] = 987645545;
			map_s1[2144457] = 987645545;
			map_s1[2144458] = 987645415;
			std::cout << "FT  (insert range) ";
			Timer t;
			map_f.insert(map_s1.begin(), map_s1.end());
		}
		{
			std::map<int, int> map_f1;
			map_f1[2144454] = 987684545;
			map_f1[2144455] = 98765545;
			map_f1[2144456] = 987645545;
			map_f1[2144457] = 987645545;
			map_f1[2144458] = 987645415;
			std::cout << "STD (insert range) ";
			Timer t;
			map_s.insert(map_f1.begin(), map_f1.end());
		}

		std::cout << "***********************************************\n" ;
		{
			std::cout << "FT  (at) ";
			Timer t;
			map_f.at(100);
		}
		{
			std::cout << "STD (at) ";
			Timer t;
			map_s[5241];
		}
		std::cout << "***********************************************\n" ;
		{
			std::cout << "FT  ([]) ";
			Timer t;
			map_s[5241];
		}
		{
			std::cout << "STD ([]) ";
			Timer t;
			map_s.at(100);
		}
		std::cout << "***********************************************\n" ;
		{
			std::cout << "FT  (erase by key) ";
			Timer t;
			map_f.erase(12542);
		}
		{
			std::cout << "STD (erase by key) ";
			Timer t;
			map_s.erase(12542);
		}
		std::cout << "***********************************************\n" ;
		{
			std::cout << "FT  (erase by iter) ";
			ft::map<int, int>::iterator f_it = map_f.find(2154);
			Timer t;
			map_f.erase(f_it);
		}
		{
			std::cout << "STD (erase by iter) ";
			std::map<int, int>::iterator s_it = map_s.find(2154);
			Timer t;
			map_s.erase(s_it);
		}
		std::cout << "***********************************************\n" ;
		{
			std::cout << "FT  (erase by range) ";
			ft::map<int, int>::iterator f_it1 = map_f.find(1);
			ft::map<int, int>::iterator f_it2 = map_f.find(500);
			Timer t;
			map_f.erase(f_it1, f_it2);
		}
		{
			std::cout << "FT  (erase by range) ";
			std::map<int, int>::iterator s_it1 = map_s.find(1);
			std::map<int, int>::iterator s_it2 = map_s.find(500);
			Timer t;
			map_s.erase(s_it1, s_it2);
		}
		std::cout << "***********************************************\n" ;
		{
			
		}


	}
	return (0);
}


