#ifndef CHOOSE_CONST_HPP
#define CHOOSE_CONST_HPP

namespace ft
{
	template <bool B, typename isFalse, typename isTrue>
	struct chooseConst {};

	template <typename isNotConst, typename isConst>
	struct chooseConst<false, isNotConst, isConst>
	{
		typedef isNotConst type;
	};

	template <typename isNotConst, typename isConst>
	struct chooseConst<false, isNotConst, isConst>
	{
		typedef isConst type;
	};

}
#endif