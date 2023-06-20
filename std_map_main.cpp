#include <map>
#include <iomanip>
#include <vector>
#include <array>
#include <iostream>
#include <string>

template <typename U, typename T>
void view_map(std::map<U, T> map1)
{
	typename std::map<U, T>::iterator it;
	for (it = map1.begin(); it != map1.end(); ++it)
		std::cout << it->second << " " ;
	std::cout << std::endl;
	
}

template <typename key, typename value>
std::ostream& operator<<(std::ostream& os, std::map<key, value>& m)
{
	for (auto const&p : m)
		os <<"[ " << p.first << " ] -> "<< " " << p.second << std::endl;
	return os;
}


int main()
{
	/********** EMPTY CONSTRUCTOR*****************/
	std::cout << "Empty constructor " << std::endl;
	std::map<char, int> map1;

	map1['a'] = 1;
	map1['d'] = 4;
	map1['b'] = 2;
	map1['e'] = 5;
	map1['c'] = 3;

	view_map(map1);
	std::cout << "copy constructor " << std::endl;
	std::map<char, int> map2(map1);
	view_map(map2);

	std::cout << "<< overload constructor " << std::endl;
	std::cout << map2;

	std::cout << "<< overload constructor " << std::endl;

	std::map<std::string , int> map4;
	map4["one"] = 1;
	map4["two"] = 2;
	map4["three"] = 3;
	map4["four"] = 66;
	map4["five"] = 43;
	map4["six"] = 97;

	std::cout << map4;

	std::cout << "<< Iterator constructor " << std::endl;

	std::map<std::string, int> map5(map4.find("one"), map4.end());
	std::cout << map5;

	return (0);
}
