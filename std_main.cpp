#include "std_tester.hpp"

int main()
{
	std::cout << "/************** ft_vector ****************/" << std::endl;
	is_empty_vector();
	range_vector();
	iterator_vector();
	copy_vector();
	assignment_vector();
	reverse_traverse();
	capacity_vector();
	access_vector();
	assign_vector();
	int myarr[] = {4, 6, 32, 76, 12, 88};
	arr_assign_vector<int>(myarr, 6);
	int myarr1[] = {77, 0, 24, 6, 32, 76, 12, 88};
	arr_assign_vector<int>(myarr1, 8);
	insert_vector(89);
	erase_vector(2);
	clear_vector();
	swap_vector();
	return (0);
}