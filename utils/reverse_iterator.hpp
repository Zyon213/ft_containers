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
				reverse_iterator &operator=(const reverse_iterator<Iterator> &vec)
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

				// getter val return _val
				iterator_type getValPtr() const
				{
					return _val;
				}

				// operator overloads

				// deference
				reference operator*() const 
				{
					iterator_type temp(_val);

					return *--temp;
				}

				//pointer 
				pointer operator->() const { return _val; }

				// increment	
				reverse_iterator& operator++() 
				{
					--_val;
					return *this;
				}
				
				//decrement
				reverse_iterator& operator--() 
				{
					++_val;
					return *this;
				}

				// post increment
				reverse_iterator operator++(int) 
				{
					reverse_iterator temp(*this);
					--(*this);
					return temp;
				}

				// post decrement
				reverse_iterator operator--(int) 
				{
					reverse_iterator temp(*this);
					++(*this);
					return temp;
				}

				// add on it

				reverse_iterator& operator+=(difference_type n)
				{
					_val -= n;
					return *this;
				}

				reverse_iterator& operator-=(difference_type n)
				{
					_val += n;
					return *this;
				}

				reverse_iterator operator[](difference_type n) const
				{
					return _val[n];
				}

				reverse_iterator operator+(difference_type n) const
				{
					return reverse_iterator(_val - n);
				}

				reverse_iterator operator-(difference_type n) const
				{
					return reverse_iterator(_val + n);
				}

				bool operator==(const reverse_iterator& vec) const
				{
					return vec._val == _val;
				}

				bool operator!=(const reverse_iterator& vec) const
				{
					return vec._val != _val;
				}
				
				bool operator<(const reverse_iterator& vec) const
				{
					return vec._val > _val;
				}

				bool operator<=(const reverse_iterator& vec) const
				{
					return vec._val >= _val;
				}

				bool operator>(const reverse_iterator& vec) const
				{
					return vec._val < _val;
				}

				bool operator>=(const reverse_iterator& vec) const
				{
					return vec._val <= _val;
				}
	};

}

#endif