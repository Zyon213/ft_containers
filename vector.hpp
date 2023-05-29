#ifndef VECTOR_HPP
#define VECTOR_HPP

/* 
	std::ios_base::Init this class is used to ensure that the default c++ stream(std::cin,
	std::cout, etc) are properly initialized and destructed.(when the first instance
	is consructed as well as flushes the output when the last instance is
	destructed), and <iostream> behaves as if it defines std::ios_base::Init with
	storage duration. 
*/
#include "utils/is_integral.hpp"
#include "utils/vector_iterator.hpp"
#include "utils/reverse_iterator.hpp"
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
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_pointer 		const_pointer;
			typedef typename allocator_type::const_reference 	const_reference;

			// size_t is the size of an object in bytes::size
			typedef typename allocator_type::size_type			size_type;

			// a signed integral type to represent pointer subtraction.
			typedef typename allocator_type::difference_type		diffence_type;

			typedef ft::vector_iterator<value_type>		iterator;
			typedef ft::vector_iterator<const value_type>		const_iterator;

			typedef ft::reverse_iterator<iterator>		reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			/* 			
			creates an empty vector constructor with no elements, the explicit 
			keyword prevent the constructor from being used to implicitly convert
			from other types of std::vector.
			 */
			
			/********************** MEMBER FUNCTIONS **********************************************/
		
			explicit vector(const allocator_type &alloc = allocator_type()) :
			  _size(0), _capacity(0), _allocator(alloc)
			{
				_vector = _allocator.allocate(_capacity);
			}

			/* 			
			fill constructor - constructs a container with n elemnets, each
			is with a copy of val
			 */

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
			_size(n), _capacity(n), _allocator(alloc)
			{
				_vector = _allocator.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(_vector + i, val);
			}

			// range constructor - constructs a container with as many elements as the range(first, last)

			template <class Iterator> 
			vector (Iterator first, Iterator last, const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<Iterator>::value, Iterator>::type* = 0) : 
			_vector(0), _allocator(alloc), _size(0), _capacity(0)
			{
				Iterator temp(first);
				while (temp != last)
				{
					temp++;
					_size++;
				}
				_capacity = _size;
				_vector = _allocator.allocate(_capacity);
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
				// for (iterator it = begin(); it != end(); ++it)
				for (size_type i = 0; i < size(); i++ )
					_allocator.destroy(_vector + i);
					// _allocator.destroy((*it));
				_allocator.deallocate(_vector, _capacity);
			}

		// 	/********************** ITERATORS **********************************************/

			iterator begin() { return iterator(_vector); }
			
			iterator end() { return iterator(_vector + _size); }

			reverse_iterator rbegin() { return reverse_iterator(_vector + (_size));}

			reverse_iterator rend() { return reverse_iterator(_vector); }
			
			const_iterator cbegin() const { return const_iterator(_vector); }

			const_iterator cend() const { return const_iterator(_vector + _size); }

			const_reverse_iterator crbegin() const { return const_reverse_iterator(_vector + (_size));}

			const_reverse_iterator crend() { return const_reverse_iterator(_vector); }

		// 	/********************** CAPACITY **********************************************/
			
			size_type size() const { return _size; }

		/* 	
			uses the max_size function of allocate returns the maximum number of 
			elements that the vector can hold. 
		*/

			size_type max_size() const { return _allocator.max_size(); }

			// void resize(size_type n, value_type val = value_type())
			// {
			// 	if (n > _capacity)
			// 		resize_vector(n);
			// 	if (n > _size)
			// 		push_back(val);
			// 	if (n < _size)
			// 		pop_back();
			// }

			size_type capacity() const { return _capacity; }

			// checks if the size is empty
			bool empty() const { return _size == 0;}

			// request a change in capacity if n is greater than vector capacity
			// the function causes the container to reallocate its storage 
			// increasing its capacity to n(or greater)
			// if n is greater than max_size throws length_error exceptions

			void reserve (size_type n)
			{
				if (n > _allocator.max_size())
					throw std::length_error("vector_reserve");
				if (n > _capacity)
					resize_vector(n);
			}

			/* 			
				request to the container to reduce its capacity to fit its size
				but has no effect on size;
 			*/
			/********************** ELEMENT ACCESS **********************************************/

			reference operator[](size_type n)
			{
				return _vector[n];
			}

			const_reference operator[](size_type n) const
			{
				return _vector[n];
			}

			// the difference between at and [] is at first check if n is in
			// the bound of the elements in the vector (that is size)
			reference at (size_type n)
			{
				if (n >= _size)
					throw std::out_of_range("vector_index");
				return _vector[n];
			}

			const_reference at (size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range("vector_index");
				return _vector[n];
			}

			// returns reference to the first element in the vector

			reference front()
			{
				return _vector[0];
			}

			const_reference front() const
			{
				return _vector[0];
			}
			
			// returns the last element of the vector

			reference back()
			{
				return _vector[_size - 1];
			}

			const_reference back() const
			{
				return _vector[_size - 1];
			}

			/********************** MODIFIERS **********************************************/

			template <class InputIterator> 
			void assign(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)

			{
				// clear();

				size_type n = static_cast<size_type>(last - first);
				if (n > _capacity)
				{
					_allocator.deallocate(_vector, _capacity);
					_vector = _allocator.allocate(n);
				}
				size_type i = 0;
				for (; first != last; ++first, ++i)
					_allocator.construct(_vector + i, *first);
				_size = i;
			}

		private:
			void resize_vector(size_type newSize)
			{
				pointer temp = _allocator.allocate(newSize);

				for (size_type i = 0; i < _size; i++)
					_allocator.construct(&temp[i], _vector[i]);

				this->~vector();
				_capacity = newSize;
				_vector = temp;
			}

		private:
			pointer							_vector;
			size_type						_size;
			size_type 						_capacity;
			allocator_type					_allocator;


	};
}


#endif