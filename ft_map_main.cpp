#include <iostream>
#include <map>
#include "containers/map.hpp"

template <typename U, typename T>
void view_map(ft::map<U, T> map1)
{
	typename ft::map<U, T>::iterator it;
	for (it = map1.begin(); it != map1.end(); ++it)
		std::cout << it->second << " " ;
	std::cout << std::endl;
	
}

template <typename key, typename value>
std::ostream& operator<<(std::ostream& os, ft::map<key, value>& m)
{
	typename ft::map<key, value>::iterator it;
	for (it = m.begin(); it != m.end(); ++it)
		os << "[" << it->first << "   ] -> " << it->second << std::endl;
	return os;

}

class test
{
	private:
		int _num;
		std::string _name;
	public:
		explicit test(){}
		explicit test(int num, std::string name) : _num(num), _name(name) {}
		test& operator=(const test& t)
		{
			if (this != &t)
			{
				_num = t._num;
				_name = t._name;
			}
			return (*this);
		}

		test(const test& t)
		{
			_num = t._num;
			_name = t._name;
		}

		~test() {}
		int getNum(void) const {return _num;}
		std::string getName(void) const {return _name;}
		void setNum(int num) { _num = num ;}
		void setName(const std::string name) { _name = name ;}
};

struct buf
{
	int num;
	std::string name;
};

int main()
{
	{
		/********** CONSTRUCTOR*****************/
		std::cout << "Empty constructor " << std::endl;
		ft::map<char, int> map1;
		map1['a'] = 1;
		map1['d'] = 4;
		map1['b'] = 2;
		map1['e'] = 5;
		map1['c'] = 3;
		view_map(map1);

		std::cout << "Copy constructor " << std::endl;
		ft::map<char, int> map2(map1);
		view_map(map2);

		std::cout << "Assignment constructor " << std::endl;
		ft::map<char, int> map3;
		map3 = map2;
		view_map(map3);

		std::cout << "Initialize elements with [] operator " << std::endl;
		ft::map<std::string , int> map4;
		map4["one"] = 1;
		map4["two"] = 2;
		map4["thre"] = 3;
		map4["four"] = 66;
		map4["five"] = 43;
		map4["six"] = 97;
		view_map(map4);

		std::cout << "Iterator constructor " << std::endl;
		ft::map<std::string, int> map5(map4.find("one"), map4.end());
		view_map(map5);

		std::cout << "Overload operator " << std::endl;
		std::cout << map5;

		ft::map<int, buf> map6;

		buf b1 =  {43, "add"};
		map6[1] = b1;
		buf b2 = {12, "minus"};
		map6[1] = b2;
		buf b3 = {87, "multi"};
		map6[1] = b3;
		buf b4 = {52, "div"};
		map6[1] = b4;

		std::cout << "Initializing using struct " << std::endl;
		ft::map<int, buf>::iterator it;
		for (it = map6.begin(); it != map6.end(); ++it)
			std::cout << "[" << it->first << " ] -> " << it->second.num << " " << it->second.name << std::endl;

		std::cout << "Initializing using class " << std::endl;
		ft::map<int, test> map7;
		test t(1, "one");
		map7[1] = t;
		test t1(2, "five");
		map7[2] = t1;
		test t2(3, "eight");
		map7[3] = t2;
		test t3(4, "ten");
		map7[4] = t3;

		std::cout << map7[1].getName();

		ft::map<int, test>::iterator it1;
		for (it1 = map7.begin(); it1 != map7.end(); ++it1)
			std::cout << "[" << it1->first << " ] -> " << it1->second.getNum() << " " << it1->second.getName() << std::endl;

	}
	return (0);
}
