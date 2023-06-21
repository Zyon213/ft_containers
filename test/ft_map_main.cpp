#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>
#include "../containers/map.hpp"

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

template<typename T>
void exec_time(T t2, T t1)
{
	double t = static_cast<double>(t2 - t1) / static_cast<double>(CLOCKS_PER_SEC);
	std::cout << "Execution time is " << std::setprecision(8) << t << std::endl;
}

template <typename T>
void is_empty(T t)
{
	if (t.empty())
		std::cout << "Map is Empty" << std::endl;
	else
		std::cout << "Map is not Empty" << std::endl;
}

int main()
{
	{
		std::cout << "************** CONSTRUCTOR *******************\n";
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
		ft::map<int, test>::iterator it1;
		for (it1 = map7.begin(); it1 != map7.end(); ++it1)
			std::cout << "[" << it1->first << " ] -> " << it1->second.getNum() << " " << it1->second.getName() << std::endl;

		std::cout << "Initializing using large elements " << std::endl;
		std::vector<int> vec;
		std::vector<int>::iterator vit;
		for (int i = 0; i < INT_MAX / 10000; i++)
			vec.push_back(i);
		
		ft::map<int, int> map8;
		for (vit = vec.begin(); vit != vec.end(); ++vit)
			map8.insert(ft::pair<int, int>(*vit, *vit));

		std::cout << "************** ITERATOR *******************\n";
		/********** ITERATOR *****************/
		std::cout << "Iterators begin, end..." << std::endl;
		ft::map<char, int>::iterator it2 = map1.begin();

		for (; it2 != map1.end(); ++it2)
			std::cout << it2->first << " " << it2->second << "  ";
		std::cout << std::endl;

		std::cout << "Reverse Iterators rbegin, rend..." << std::endl;
		ft::map<char, int>::reverse_iterator rit = map1.rbegin();

		for (; rit != map1.rend(); ++rit)
			std::cout << rit->first << " " << rit->second << "  ";
		std::cout << std::endl;

		/********** CAPACITY *****************/
		std::cout << "************** CAPACITY *******************\n";

		ft::map<int, int> emap;
		is_empty(map1);
		is_empty(emap);
		std::cout << "Size of map1 " << map1.size() << std::endl;
		std::cout << "Max size of map1 " << map1.max_size() << std::endl;
		std::cout << "Size of emap " << emap.size() << std::endl;
		std::cout << "Max size of emap " << emap.max_size() << std::endl;

		/********** ELEMENT ACCESS *****************/
		std::cout << "************** ELEMENT ACCESS*******************\n";

		std::cout << "Element at map1[a] " << map1.at('a') << std::endl;
		std::cout << "Element at map4[four] " << map4.at("four") << std::endl;

		map1['f'] = 532;
		std::cout << "Element at map1[a] " << map1.at('f') << std::endl;
		map4["seven"] = 893;
		std::cout << "Element at map4[seven] " << map4.at("seven") << std::endl;
		test t4(53, "fight club");
		map7[9] = t4;
		std::cout << "Element at map7[9] " << map7.at(9).getNum() << " " << map7.at(9).getName() << std::endl;

		/********** MODIFIER *****************/
		std::cout << "************** MODIFIER *******************\n";
		
		ft::map<char, int> mapi;
		mapi.insert(ft::pair<char, int>('z', 54));
		mapi.insert(ft::pair<char, int>('t', 78));
		mapi.insert(ft::pair<char, int>('y', 12));
		mapi.insert(ft::pair<char, int>('n', 96));
		mapi.insert(ft::pair<char, int>('u', 214));
		std::cout << mapi;

		ft::pair<ft::map<char, int>::iterator, bool> pr;

		pr = mapi.insert(ft::pair<char, int>('n', 12));
		if (pr.second == false)
			std::cout << "Element '"<< pr.first->first<< "' exist with value " << pr.first->second << std::endl;
		
		std::cout << "*****Insert Element with iterator position*****\n";
		ft::map<int, std::string> mapi1;
		ft::map<int, std::string>::iterator itb = mapi1.begin();

		mapi1.insert(itb, ft::pair<int, std::string>(32, "one"));
		mapi1.insert(itb, ft::pair<int, std::string>(6, "two"));
		mapi1.insert(itb, ft::pair<int, std::string>(54, "three"));
		mapi1.insert(itb, ft::pair<int, std::string>(81, "seven"));
		mapi1.insert(itb, ft::pair<int, std::string>(11, "nine"));
		mapi1.insert(itb, ft::pair<int, std::string>(28, "ten"));
		mapi1.insert(itb, ft::pair<int, std::string>(67, "eight"));
		std::cout << mapi1;

		std::cout << "*****Insert Element with iterator *****\n";
		ft::map<int, std::string> mapi2(mapi1.begin(), mapi1.find(81));
		std::cout << mapi2;

		std::cout << "*****Erase Element with iterator *****\n";
		mapi1.erase(mapi1.begin());
		mapi1.erase(mapi1.find(81));
		std::cout << mapi1;
		std::cout << "*****Erase Element by key *****\n";
		mapi1.erase(54);
		std::cout << mapi1;
		std::cout << "*****Erase Element by range *****\n";
		mapi2.erase(mapi2.begin(), mapi2.find(28));
		std::cout << mapi2;
		std::cout << "*****Swap map *****\n";
		ft::map<int, int> smap1;
		smap1[1] = 100;
		smap1[2] = 200;
		smap1[3] = 300;
		smap1[4] = 400;
		smap1[5] = 500;

		ft::map<int, int> smap2;
		smap2[5] = 500;
		smap2[4] = 400;
		smap2[3] = 300;
		smap2[2] = 200;

		std::cout << "****** Before swap ********\n";
		for (ft::map<int, int>::iterator x = smap1.begin(); x != smap1.end(); ++x)
			std::cout << x->first << " -> " << x->second << " ";
		std::cout << std::endl;
		smap2.swap(smap1);
		std::cout << "****** After swap *******\n";
		for (ft::map<int, int>::iterator y = smap1.begin(); y != smap1.end(); ++y)
			std::cout << y->first << " -> " << y->second << " ";
		std::cout << std::endl;

		std::cout << "********** Clear map **********\n";
		is_empty(smap1);
		smap1.clear();
		is_empty(smap1);

		std::cout << "********** key - value compare **********\n";
		ft::map<char, int> cmap;
		cmap['z'] = 423;
		cmap['t'] = 87;
		cmap['v'] = 96;
		cmap['o'] = 54;
		cmap['f'] = 32;
		ft::map<char, int>::key_compare kcmp = cmap.key_comp();
		ft::map<char, int>::iterator cit = cmap.begin();
		char c = cmap.rbegin()->first;
		do
		{
			std::cout << cit->first << " " << cit->second << "\n";
		}while (kcmp((*cit++).first, c ));

		std::cout << "********** find key **********\n";
		std::cout << "Find element with key z " << cmap.find('z')->second << std::endl;
		std::cout << "Count element with key z " << cmap.count('z')<< std::endl;
		std::cout << "Count element with key a " << cmap.count('a')<< std::endl;
		std::cout << "Lower-bound element to key t " << cmap.lower_bound('t')->second<< std::endl;
		std::cout << "Lower-bound element to key t " << cmap.upper_bound('t')->second<< std::endl;
		ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> pr1;
		pr1 = cmap.equal_range('t');
		std::cout << "Equal range element to key t " << pr1.first->second << std::endl;
	}
	return (0);
}
