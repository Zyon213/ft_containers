#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <functional>
#include "utils/pair.hpp"
#include "utils/lexicographical_compare.hpp"

namespace ft
{
	template <
	class Key, 
	class T,
	class Compare = std::less<Key>, 
	class Allocator = std::allocator<ft::pair<const Key, T>>
	>
	class map
	{
		private:
			typedef Key 											key_type;
			typedef T 												mapped_type;
			typedef ft::pair<const key_type, mapped_type>			value_type;	
			typedef value_type&										reference;
			typedef const value_type&								const_reference;
			typedef Compare											key_compare;
			typedef Allocator										allocator_type;
			typedef typename allocator_type::template rebind<value_type>::other type_allocator;
			typedef std::allocator_traits<allocator_type> 			type_traits;
			typedef typename type_traits::pointer 					pointer;
			typedef typename type_traits::const_pointer 			const_pointer;
			typedef size_t											size_type;
			typedef	std::ptrdiff_t 									difference_type;

			// return a comparision objects that can be used to compare two elements to get
			// whether the key of the first one goes before the second.

			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				protected:
					key_compare comp;
				public:
					value_compare(key_compare c) : comp(c) {}
					~value_compare() {}

					bool operator()(const value_type& x, const value_type& y) const
					{
						return (comp(x.first, y.first));
					}
			};

			explicit map( const key_compare& comp, const Allocator& alloc = Allocator()) {}

			template<class InputIt>
			map(InputIt first, InputIt last, const key_compare& comp = Compare(), cosnt Allocator& alloc = Allocator()) {}
			map(const map& other) {}


	};
}
#endif