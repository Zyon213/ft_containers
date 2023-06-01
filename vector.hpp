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
			typedef typename allocator_type::difference_type		difference_type;

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
			_vector(0), _size(0), _capacity(0), _allocator(alloc)
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

			vector (const vector& x):_vector(0), _size(0), _capacity(0), _allocator(x._allocator)
			{
				*this = x;
			} 

			// assignment operator
			// vector& operator=(const vector& x)
			// {
			// 	_size = x._size;
			// 	_capacity = x._capacity;
			// 	_allocator = x._allocator;
			// 	_vector = _allocator.allocate(_capacity);
			// 	for (size_type i = 0; i < _size; i++)
			// 		_allocator.construct(_vector + i, *(x._vector + i));
			// 	return *this;
			// }

			vector& operator=(const vector& x)
			{
				this->insert(this->begin(), x.begin(), x.end());
				return *this;
			}


			~vector()
			{
				// std::cout << "Destructor called" << std::endl;
				for (iterator it = begin(); it != end(); ++it)
					_allocator.destroy(&(*it));
				_allocator.deallocate(_vector, _capacity);
			}

		// 	/********************** ITERATORS **********************************************/

			iterator begin() { return iterator(_vector); }
			
			iterator end() { return iterator(_vector + _size); }

			reverse_iterator rbegin() { return reverse_iterator(_vector + (_size));}

			reverse_iterator rend() { return reverse_iterator(_vector); }
			
			const_iterator begin() const { return const_iterator(_vector); }

			const_iterator end() const { return const_iterator(_vector + _size); }

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

			/* 			
				request a change in capacity if n is greater than vector capacity
				the function causes the container to reallocate its storage 
				increasing its capacity to n(or greater)
				if n is greater than max_size throws length_error exceptions
			*/

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

			/* 			
				the difference between at and [] is at first check if n is in
				the bound of the elements in the vector (that is size)
			 */
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
				clear();

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

			void assign(size_type n, const value_type& val)
			{
				clear();
				if (n > _capacity)
				{
					_allocator.deallocate(_vector, _capacity);
					_vector = _allocator.allocate(n);
				}
				size_type i = 0;
				for (; i < n; i++)
					_allocator.construct(_vector + i, val);
				_size = n;
			}

			void push_back(const value_type& val)
			{
				if (_size + 1 > _capacity)
					resize_vector(!_capacity ? 1 : _capacity * 2);
				_allocator.construct(_vector + _size, val);
				++_size;
			}

			void pop_back()
			{
				if (_size)
				{
					_allocator.destroy(_vector + (_size - 1));
					_size--;
				}
			}

			// insert an element at a specific position

			iterator insert(iterator position, const value_type& val)
			{
				difference_type diff = position - begin();
				insert(position, 1, val);
				return (&_vector[diff]);
			}

			// insert a range of elements starting at position
 		
			void insert (iterator position, size_type n, const value_type& val)
			{
				difference_type diff = position - begin();
				size_type pos = static_cast<size_type>(diff) + n;
				size_type old_pos = static_cast<size_type>(diff) - static_cast<size_type>(pos);
				size_type new_pos = _size + n;

				if (_size + n > _capacity)
					resize_vector(!_capacity ? n : _capacity * 2);
				
				// create temportary vector

				allocator_type allocator_tmp;
				pointer vec_temp = allocator_tmp.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					allocator_tmp.construct(&vec_temp[i], _vector[i]);
				
				// assign values starting from position after the newly inserted elelments

				for (size_type i = pos; i < new_pos; i++)
				{
					if (i < _size)
						_allocator.destroy(&_vector[i]);
					_allocator.construct(&_vector[i], vec_temp[i + old_pos]);
				}
				
				// insert the new elements starting position
				for (size_type i = diff; i < pos; i++)
				{
					if (i < _size)
						_allocator.destroy(&_vector[i]);
					_allocator.construct(&_vector[i], val);
				}

				// destroy and dealloate the temporary vector
				for (size_type i = 0; i < _size; ++i)
					allocator_tmp.destroy(&vec_temp[i]);
					
				allocator_tmp.deallocate(vec_temp, _size);
				
				_size += n;
			}
		
		// insert a range of elements starting at position
			template <class InputIterator> 
			void insert(iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				difference_type diff = position - begin();
				difference_type pos = diff;

				size_type n = 0;
				for (InputIterator it = first; it != last; it++)
				{
					pos++;
					n++;
				}
				size_type old_pos = static_cast<size_type>(diff) - static_cast<size_type>(pos);
				size_type new_pos = _size + n;
				if (_size + n > _capacity)
					resize_vector(!_capacity ? n : _capacity * 2);
				
				// create temportary vector

				allocator_type allocator_tmp;
				pointer vec_temp = allocator_tmp.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					allocator_tmp.construct(&vec_temp[i], _vector[i]);
				
				// assign values starting from position after the newly inserted elelments

				for (size_type i = static_cast<size_type>(pos); i < new_pos; i++)
				{
					if (i < _size)
						_allocator.destroy(&_vector[i]);
					_allocator.construct(&_vector[i], vec_temp[i + old_pos]);
				}
				
				// insert the new elements starting position
				for (size_type i = static_cast<size_type>(diff); i < static_cast<size_type>(pos); i++)
				{
					if (i < _size)
						_allocator.destroy(&_vector[i]);
					_allocator.construct(&_vector[i], *first++);
				}

				// destroy and dealloate the temporary vector
				for (size_type i = 0; i < _size; ++i)
					allocator_tmp.destroy(&vec_temp[i]);
					
				allocator_tmp.deallocate(vec_temp, _size);
				
				_size += n;

			}

			// erase an element from position

			iterator erase(iterator position)
			{
				size_type i = 0;
				iterator it = this->begin();
				while (it != position)
				{
					++it;
					i++;
				}
				if (position != this->end())
					_allocator.destroy(&_vector[i]);
				for (iterator it = position ; it < this->end() - 1; ++it, ++i)
					this->_allocator.construct(&_vector[i], _vector[i + 1]);
				--(this->_size);
				return (position);
			}
/* 			iterator erase(iterator position)
			{
				if (position != this->end())
					_allocator.destroy(position.base());

				for (iterator it = position ; it < this->end() - 1; ++it)
					this->_allocator.construct(it.base(), *(it + 1));
				--(this->_size);
				return (position);
			}
 */
			iterator erase(iterator first, iterator last)
			{
				while (first != last)
					erase(--last);
		
				return last;
			}

			// removes all elements from the vector

			void clear()
			{
				erase(this->begin(), this->end());
			}

			// swap two containers exchanging every elements

			void swap(vector& x)
			{
				swap(_vector, x._vector);
				swap(_size, x._size);
				swap(_capacity, x._capacity);
				swap(_allocator, x._allocator);
			}
	
			friend void swap(vector& x, vector &y)
			{
				x.swap(y);
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

			// swap two elements x and y
			template <typename A>
			void swap(A& x, A& y)
			{
				A tmp;
				tmp = x;
				x = y;
				y = tmp;
			}
			

		private:
			pointer							_vector;
			size_type						_size;
			size_type 						_capacity;
			allocator_type					_allocator;


	};
}


#endif