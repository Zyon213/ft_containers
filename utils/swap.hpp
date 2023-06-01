#ifndef SWAP_HPP
#define SWAP_HPP

namespace ft
{
	template <typename A>
	void swap(A& x, A& y)
	{
		A tmp;
		tmp = x;
		x = y;
		y = tmp;
	}
}

#endif		