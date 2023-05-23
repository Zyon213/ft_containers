#ifndef VECTOR_HPP
#define VECTOR_HPP

/* 
	std::ios_base::Init this class is used to ensure that the default c++ stream(std::cin,
	std::cout, etc) are properly initialized and destructed.(when the first instance
	is consructed as well as flushes the output when the last instance is
	destructed), and <iostream> behaves as if it defines std::ios_base::Init with
	storage duration. 
*/
#include "is_integral.hpp"
#include "vector_iterator.hpp"
#include "reverse_vector_iterator.hpp"
#include <iostream>
/* 
	memory header is part of the dynamic memory management library
	allocator class template is default Allocator used by all standard library containers
 */
#include <memory>

// exception is the part of error handling library
#include <exception>

// use the namespace ft
namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T									value_type;
			typedef	Allocator							allocator_type;
			typedef allocator_type::pointer				pointer;
			typedef allocator_type::reference			reference;
			typedef allocator_type::const_pointer 		const_pointer;
			typedef allocator_type::const_reference 	const_reference;

			// size_t is the size of an object in bytes::size
			typedef allocator_type::size_type			size_type;

			// a signed integral type to represent pointer subtraction.
			typedef allocator_type::difference_type		diffence_type;

			typedef ft::vector_iterator<T, false>		iterator;
			typedef ft::vector_iterator<T, true>		const_iterator;

			typedef ft::reverse_vector_iterator<T, false>		reverse_iterator;
			typedef ft::reverse_vector_iterator<T, true>		const_reverse_iterator;
			/* 			
			creates an empty vector constructor with no elements, the explicit 
			keyword prevent the constructor from being used to implicitly convert
			from other types of std::vector.
			 */
			
			/********************** MEMBER FUNCTIONS **********************************************/
		
			explicit vector(const allocator_type& alloc = allocator_type(())) :
			  _size(0), _capacity(0), _allocator(alloc)
			{
				_vector = alloc.allocate(_capacity);
			}

			/* 			
			fill constructor - constructs a container with n elemnets, each
			is with a copy of val
			 */

			explicit vector(size_type n, const value_type& val = value_type(), const allcator_type& all = allocator_type()) :
			_size(n), _capacity(n), _allocator(alloc)
			{
				_vector = alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(_vector + i, val);
			}

			// range constructor - constructs a container with as many elements as the range(first, last)

			template <class InputIterator> 
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) : 
			_size(0), _allocator(alloc)
			{
				InputIterator temp(first);
				while (first != last)
					_size++;
				_capacity = _size;
				_vector = alloc.allocate(_capacity);
				for (int i = 0; first != last; ++i, ++first)
					_allocator.construct(_vector + i, *first);
			} 

			// copy constructor

			vector (const vector& x)
			{
				_size = x._size;
				_capacity = x._capacity;
				_allocator = x._allocator;
				_vector = _allocator.allocate(_capacity);
				*this = x;

			}

			// assignment operator
			vector& operator=(const vector& x)
			{
				_size = x._size;
				_capacity = x._capacity;
				_allocator = x._allocator;
				_vector = _allocator.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(_vector + i, *(x._vector + i));
				return *this;
			}

			~vector()
			{
				for (iterator it = begin(); it != end(); ++it)
					_allocator.destroy((*it));
				_allocator.deallocate(_vector, _capacity);
			}

			/********************** ITERATORS **********************************************/

			iterator begin() { return iterator(_vector); }
			
			iterator end() { return iterator(_vector + _size); }

			reverse_iterator rbegin() { return reverse_iterator(_vector + (_size - 1));}

			reverse_iterator rend() { return reverse_iterator(_vector - 1); }
			
			const_iterator cbegin() const { return const_iterator(_vector); }

			const_iterator cend() const { return const_iterator(_vector + _size); }

			const_reverse_iterator crbegin() const { return const_reverse_iterator(_vector + (_size - 1));}

			const_reverse_iterator crend() { return const_reverse_iterator(_vector - 1); }

			/********************** CAPACITY **********************************************/
			
			size_type size() const { return _size; }

			// uses the max_size function of allocate returns the maximum number of 
			// elements that the vector can hold.

			size_type max_size() const { return _allocate.max_size(); }

			void resize(size_type n, value_type val = value_type())
			{
				if (n > _capacity)
					resize_vector(n);
				if (n > _size)
					push_back(val);
				if (n < _size)
					pop_back();
			}


		private:
			void resize_vector(size_type newSize)
			{
				pointer temp = _allocator.allocate(newSize)

				for (size_type i = 0; i < _size; i++)
					_allocate.construct(&temp[i], _vector[i]);

				this->~vector();
				_capacity = newSize;
				_vector = temp;
			}

		private:
			pointer							_vector;
			size_type						_size;
			size_type 						_capacity;
			allocator_type					_allcator;


	};
}


#endif