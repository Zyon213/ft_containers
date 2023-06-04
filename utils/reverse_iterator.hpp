#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator : public ft::iterator<typename ft::iterator_traits<Iterator>::iterator_category,
												typename ft::iterator_traits<Iterator>::value_type, 
												typename ft::iterator_traits<Iterator>::difference_type, 
												typename ft::iterator_traits<Iterator>::pointer, 
												typename ft::iterator_traits<Iterator>::reference>

	{
		public:
			typedef Iterator										iterator_type;
			typedef ft::iterator_traits<iterator_type> 			traits_types;					
			typedef typename traits_types::pointer						pointer;									
			typedef typename traits_types::reference						reference;									
			typedef typename traits_types::difference_type				difference_type;					

		private:
			iterator_type		_val;
		
		public:
				// Default constructor
				reverse_iterator() : _val() {}
				
				// coppy constructor
				reverse_iterator(iterator_type v) : _val(v) {}

				template <class T>
				reverse_iterator(const reverse_iterator<T> &vec) : _val(vec.base()) {}

				// assigment operator constructor
				reverse_iterator &operator=(const reverse_iterator &vec)
				{
					if (this != &vec)
						_val = vec.base();
					return *this;
				}

				// Default destructor

				~reverse_iterator() {}

				iterator_type base() const
				{
					return _val;
				}

				// operator overloads

				// deference
				reference operator*() const 
				{
					iterator_type temp = _val;

					return *--temp;
				}

				//pointer 
				pointer operator->() const { return &this->operator*(); }

				// increment	
				reverse_iterator &operator++() 
				{
					--_val;
					return *this;
				}
				
				//decrement
				reverse_iterator &operator--() 
				{
					++_val;
					return *this;
				}

				// post increment
				reverse_iterator operator++(int) 
				{
					reverse_iterator temp(*this);
					--_val;
					return temp;
				}

				reverse_iterator operator--(int) 
				{
					reverse_iterator temp(*this);
					++_val;
					return temp;
				}

				// add on it

				reverse_iterator &operator+=(difference_type n)
				{
					_val -= n;
					return *this;
				}

				reverse_iterator &operator-=(difference_type n)
				{
					_val += n;
					return *this;
				}

				reference operator[](difference_type n) const
				{
					return *(*this + n);
				}

				reverse_iterator operator+(difference_type n) const
				{
					return reverse_iterator(_val - n);
				}

				reverse_iterator operator-(difference_type n) const
				{
					return reverse_iterator(_val + n);
				}

	};

template <class Iter1, class Iter2>
bool operator==(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs) {
	return lhs.base() == rhs.base();
}

template <class Iter1, class Iter2>
bool operator!=(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs) {
	return lhs.base() != rhs.base();
}

template <class Iter1, class Iter2>
bool operator<(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs) {
	return lhs.base() > rhs.base();
}

template <class Iter1, class Iter2>
bool operator<=(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs) {
	return lhs.base() >= rhs.base();
}

template <class Iter1, class Iter2>
bool operator>(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs) {
	return lhs.base() < rhs.base();
}

template <class Iter1, class Iter2>
bool operator>=(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs) {
	return lhs.base() <= rhs.base();
}

template <class Iter1, class Iter2>
typename reverse_iterator<Iter1>::difference_type
operator-(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs) {
	return rhs.base() - lhs.base();
}

template <class Iterator>
reverse_iterator<Iterator>
operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &it) {
	return reverse_iterator<Iterator>(it.base() - n);
}

}

#endif