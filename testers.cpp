/* 
int
float
double
char
wchar_t
bool
void
signed int
unsigned int
short
unsigned short
long
unsigned long
long long
unsigned long
long long
unsigned long long
long double
signed char
unsigned char 
*/


template <typename T>
void ft_create_vector()
{
	T t;
	ft::vector<T> vec;
	std::cout << typeid(t).name() << " ";
	if (vec.empty())
		std::cout << "Empty" << std::endl;
	else
		std::cout << "Not Empty" << std::endl;

}

template <typename T>
/* void std_create_vector()
{
	T t;
	std::vector<T> vec;
	std::cout << typeid(t).name() << " ";
	if (vec.empty())
		std::cout << "Empty" << std::endl;
	else
		std::cout << "Not Empty" << std::endl;

}

void std_empty_vector()
{
	std_create_vector<int>();
	std_create_vector<float>();
	std_create_vector<double>();
	std_create_vector<char>();
	std_create_vector<wchar_t>();
	std_create_vector<bool>();
	std_create_vector<signed int>();
	std_create_vector<unsigned int>();
	std_create_vector<short>();
	std_create_vector<unsigned short>();
	std_create_vector<long>();
	std_create_vector<unsigned long>();
	std_create_vector<long long>();
	std_create_vector<unsigned long long>();
	std_create_vector<long double>();
	std_create_vector<signed char>();
	std_create_vector<unsigned char>();
} */

void ft_empty_vector()
{
	ft_create_vector<int>();
	ft_create_vector<float>();
	ft_create_vector<double>();
	ft_create_vector<char>();
	ft_create_vector<wchar_t>();
	ft_create_vector<bool>();
	ft_create_vector<signed int>();
	ft_create_vector<unsigned int>();
	ft_create_vector<short>();
	ft_create_vector<unsigned short>();
	ft_create_vector<long>();
	ft_create_vector<unsigned long>();
	ft_create_vector<long long>();
	ft_create_vector<unsigned long long>();
	ft_create_vector<long double>();
	ft_create_vector<signed char>();
	ft_create_vector<unsigned char>();
}