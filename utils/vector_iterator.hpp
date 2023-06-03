#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{

	template <class T>
	class vector_iterator : public ft::iterator<std::random_access_iterator_tag, T>
	{
		public:
			typedef ft::iterator<std::random_access_iterator_tag, T> 	traits_type;
			typedef typename traits_type::value_type 					value_type;
			typedef typename traits_type::pointer 						pointer;
			typedef typename traits_type::reference 					reference;
			typedef typename traits_type::difference_type 				difference_type;
			typedef typename traits_type::iterator_category 			iterator_category;

		private:
			pointer		_val;
		
		public:
				// Default constructor
				vector_iterator() : _val() {}

				// Default constructor
				vector_iterator(pointer val) : _val(val) {}
				
				// coppy constructor
				template <class C>
				vector_iterator(const vector_iterator<C> &vec) : _val(vec.base()){}
	

				// assigment operator constructor
				vector_iterator &operator=(const vector_iterator &vec)
				{
					if (this != &vec)
						_val = vec._val;
					return *this;
				}

				~vector_iterator() {}
				
				pointer base() const { return _val; }

				reference operator*() const { return *_val; }

				pointer operator->() const { return _val; }

				vector_iterator &operator++() 
				{
					_val++;
					return *this;
				}
				
				vector_iterator &operator--() 
				{
					_val--;
					return *this;
				}

				// post increment create copy of this and increment 
				// this but return temp, next time you call this 
				// it will be incremented.
				vector_iterator operator++(int) 
				{
					vector_iterator temp = *this;
					++(*this);
					return temp;
				}

				// post decrement create copy of this and decrement
				// this but return temp, next time you call this 
				// it will be decremented.
				vector_iterator operator--(int) 
				{
					vector_iterator temp = *this;
					--(*this);
					return temp;
				}

				// add on it

				vector_iterator &operator+=(difference_type n)
				{
					_val += n;
					return *this;
				}

				vector_iterator &operator-=(difference_type n)
				{
					_val -= n;
					return *this;
				}

				reference operator[](difference_type n) const
				{
					return _val[n];
				}

				vector_iterator operator+(difference_type n) const
				{
					return vector_iterator(_val + n);
				}

				vector_iterator operator-(difference_type n) const
				{
					return vector_iterator(_val - n);
				}
							
	};


template <class Iter1, class Iter2>
bool operator==(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs) {
	return lhs.base() == rhs.base();
}

template <class Iter1, class Iter2>
bool operator!=(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs) {
	return lhs.base() != rhs.base();
}

template <class Iter1, class Iter2>
bool operator<(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs) {
	return lhs.base() < rhs.base();
}

template <class Iter1, class Iter2>
bool operator<=(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs) {
	return lhs.base() <= rhs.base();
}

template <class Iter1, class Iter2>
bool operator>(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs) {
	return lhs.base() > rhs.base();
}

template <class Iter1, class Iter2>
bool operator>=(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs) {
	return lhs.base() >= rhs.base();
}


template <class Iterator>
typename vector_iterator<Iterator>::difference_type
operator-(const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs) {
	return lhs.base() - rhs.base();
}

template <class Iter1, class Iter2>
typename vector_iterator<Iter1>::difference_type
operator-(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs) {
	return lhs.base() - rhs.base();
}

template <class Iterator>
vector_iterator<Iterator>
operator+(typename vector_iterator<Iterator>::difference_type n, const vector_iterator<Iterator> &it) {
	return vector_iterator<Iterator>(it.base() + n);
}
}

#endif