#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
/* 	
	template <typename T, bool B>
	class vector_iterator
	{
		public:
			typedef long int										difference_type;
			typedef T												value_type;
			typedef size_t											size_type;

			typedef std::random_access_iterator_tag 				iterator_category;
			typedef typename  chooseConst<B, T&, const T&>::type	reference;
			typedef typename  chooseConst<B, T*, const T*>::type	pointer;
			typedef T*												valPtr;
	*/
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
				vector_iterator(valPtr val = 0) : _val(val) {}
				
				// coppy constructor
				vector_iterator(const vector_iterator< T, false>& vec)
				{
					_val = vec.getValPtr();
				}

				// assigment operator constructor
				vector_iterato& operator=(const vector_iterator vec)
				{
					if (this != vec)
						_val = vec._val;
					return *this;
				}

				// Default destructor

				~vector_iterator() {}

				// getter val return _val
				valPtr getValPtr() const
				{
					return _val;
				}

				// operator overloads

				// deference
				reference operator*() const { return *_val; }

				//pointer 
				pointer operator->() const { return _val; }

				// increment	
				vector_iterator& operator++() 
				{
					_val++;
					return *this;
				}
				
				//decrement
				vector_iterator& operator--() 
				{
					_val--;
					return *this;
				}

				// post increment create copy of this and increment 
				// this but return temp, next time you call this 
				// it will be incremented.
				vector_iterator operator++(int) 
				{
					vector_iterator temp(*this);
					++(*this);
					return temp;
				}

				// post decrement create copy of this and decrement
				// this but return temp, next time you call this 
				// it will be decremented.
				vector_iterator operator--(int) 
				{
					vector_iterator temp(*this);
					--(*this);
					return temp;
				}

				// add on it

				vector_iterator& operator+=(difference_type n)
				{
					_val += n;
					return *this;
				}

				vector_iterator& operator-=(difference_type n)
				{
					_val -= n;
					return *this;
				}

				vector_iterator operator[](difference_type n) const
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

				bool operator==(const vector_iterator& vec) const
				{
					return vec._val == _val;
				}

				bool operator!=(const vector_iterator& vec) const
				{
					return vec._val != _val;
				}
				
				bool operator<(const vector_iterator& vec) const
				{
					return vec._val > _val;
				}

				bool operator<=(const vector_iterator& vec) const
				{
					return vec._val >= _val;
				}

				bool operator>(const vector_iterator& vec) const
				{
					return vec._val < _val;
				}

				bool operator>=(const vector_iterator& vec) const
				{
					return vec._val <= _val;
				}
	};

}

#endif