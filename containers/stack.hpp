#ifndef STACK_HPP
#define STACK_HPP
#include "vector.hpp"

namespace ft
{
	template<class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef T 				value_type;
			typedef Container 		container_type;
			typedef size_t 			size_type;
		public:
			explicit stack (const container_type& ctnr = container_type()) : _c(ctnr){}

			stack& operator=(const stack& st)
			{
				if (this != &st)
					_c = st._c;
				return (*this);
			}

			~stack() {}
			bool empty() const
			{
				return (_c.empty());
			}

			size_type size() const
			{
				return (_c.size());
			}

			value_type& top()
			{
				return (_c.back());
			}

			const value_type& top() const
			{
				return (_c.back());
			}

			void push (const value_type& val)
			{
				_c.push_back(val);
			}

			void pop ()
			{
				_c.pop_back();
			}

			// void swap(stack& x)
			// {
			// 	ft::swap(_c, x._c);
			// }
		
		template<class C1, class T1>
		friend bool operator==(const stack<C1, T1>& lhs, const stack<C1, T1>& rhs);
		template<class C1, class T1>
		friend bool operator<(const stack<C1, T1>& lhs, const stack<C1, T1>& rhs);
		protected:
			container_type _c;

	};
template <class T, class Container> 
bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (lhs._c == rhs._c);
}
template <class T, class Container> 
bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (!(lhs == rhs));
}

template <class T, class Container> 
bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (lhs._c < rhs._c);
}
template <class T, class Container> 
bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (!(lhs > rhs));
}
template <class T, class Container> 
bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (rhs < lhs);
}

template <class T, class Container> 
bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (!(lhs < rhs));
}

// template<class T, class Container> 
// void swap(stack <T, Container>& x, stack<T, Container>& y)
// {
// 	x.swap(y);
// }
}
#endif