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
#include "utils/lexicographical_compare.hpp"
#include "utils/swap.hpp"
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
			typedef T												value_type;
			typedef	Allocator										allocator_type;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_pointer 			const_pointer;
			typedef typename allocator_type::const_reference 		const_reference;
			typedef typename allocator_type::size_type				size_type;
			typedef typename allocator_type::difference_type		difference_type;
			typedef ft::vector_iterator<value_type>					iterator;
			typedef ft::vector_iterator<const value_type>			const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			/* 			
				creates an empty vector constructor with no elements, the explicit 
				keyword prevent the constructor from being used to implicitly convert
				from other types of std::vector.
			 */
			
			/********************** MEMBER FUNCTIONS **********************************************/
		
			explicit vector(const allocator_type &alloc = allocator_type()) :
			  _vector(0), _size(0), _capacity(0), _allocator(alloc)
			{
				// _vector = _allocator.allocate(_capacity);
			}

			/* 			
				fill constructor - constructs a container with n elemnets, each
				is with a copy of val
			 */

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
			_vector(0), _size(n), _capacity(n), _allocator(alloc)
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
				difference_type diff = 0;
				while (temp != last)
				{
					diff++;
					temp++;
				}
				_size = _capacity = static_cast<size_type>(diff);
				_vector = _allocator.allocate(_capacity);
				for (size_type i = 0; first != last; ++i, ++first)
					_allocator.construct(_vector + i, *first);
			} 

			// copy constructor

			vector (const vector& x):_vector(0), _size(0), _capacity(0), _allocator(x._allocator)
			{
				*this = x;
			} 

			vector& operator=(const vector& x)
			{
				if (!(this->empty()))
					this->~vector();

				if (this != &x)
				{
					// clear();
					// _allocator.deallocate(_vector, _capacity);
					_vector = _allocator.allocate(x._capacity);
					_size = x._size;
					_capacity = x._capacity;
					// _allocator = x._allocator;
					for (size_type i = 0; i < _size; i++)
						_allocator.construct(_vector + i, *(x._vector + i));
					// this->insert(this->begin(), x.begin(), x.end());
				}
				return *this;
			}


			~vector()
			{

				// std::cout << "Destructor called" << std::endl;
				for (iterator it = begin(); it != end(); ++it)
					_allocator.destroy(&(*it));
				_allocator.deallocate(_vector, _capacity);
				_capacity = 0;
			}

		// 	/********************** ITERATORS **********************************************/

			iterator begin() { return iterator(_vector); }
			const_iterator begin() const { return const_iterator(_vector); }
			
			iterator end() { return iterator(_vector + _size); }
			const_iterator end() const { return const_iterator(_vector + _size); }

			reverse_iterator rbegin() { return reverse_iterator(this->end());}
			const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end());}
			
			reverse_iterator rend() { return reverse_iterator(this->begin()); }
			const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); }

		// 	/********************** CAPACITY **********************************************/
			
			size_type size() const { return _size; }

			/* 	
				uses the max_size function of allocate returns the maximum number of 
				elements that the vector can hold. 
			*/

			size_type max_size() const { return _allocator.max_size(); }

			void resize(size_type n, value_type val = value_type())
			{
				if (n > _capacity)
					resize_vector(n);
				if (n > _size)
				{
					for (size_type i = _size; i < n; i++)
						push_back(val);
				}
				if (n < _size)
				{
					for (size_type i = n; _size > i; _size--)
						pop_back();
				}
			}

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
				else if (_capacity < n)
				{
					allocator_type tmp_alloc;
					pointer tmp_vec = tmp_alloc.allocate(n);
					size_type tmp_size = _size;

					for (size_type i = 0; i < _size; i++)
						tmp_alloc.construct(tmp_vec + i, *(_vector + i));

				this->~vector();
				_vector = tmp_vec;
				_size = tmp_size;
				_capacity = n;
				_allocator = tmp_alloc;
				}
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
				this->clear();
				while (first != last)
				{
					push_back(*first);
					++first;
				}

			}

			void assign(size_type n, const value_type& val)
			{
				this->clear();
				while (n)
				{
					push_back(val);
					--n;
				}
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
 
		iterator insert(iterator position, const value_type &val) {
			difference_type offset = position - this->begin();
			if (offset >= 0) {
				if (!_capacity) {
					this->reserve(1);
				} else if (_size == _capacity) {
					this->reserve(_capacity * 2);
				}

				if (static_cast<size_type>(offset) > _size) {
					_allocator.construct(_vector + _size, *(_vector + _size - 1));
				} else {
					for (size_type i = _size; i > static_cast<size_type>(offset); i--) {
						_allocator.construct(_vector + i, *(_vector + i - 1));
						_allocator.destroy(_vector + i - 1);
					}
					_allocator.construct(_vector + size_type(offset), val);
				}
			}
			_size++;
			return position;
		}

		void insert(iterator position, size_type n, const value_type &val) {
			difference_type offset = position - this->begin();
			size_type range = static_cast<size_type>(offset) + n,
			          old_value = static_cast<size_type>(offset) - static_cast<size_type>(range),
			          new_size = _size + n;

			if (_size + n >= _capacity) {
				this->reserve(std::max(_capacity * 2, _size + n));
			}

			allocator_type temp_alloc;
			pointer temp_vector = temp_alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++) {
				temp_alloc.construct(temp_vector + i, *(_vector + i));
			}

			for (size_type i = range; i < new_size; i++) {
				if (i < _size)
					_allocator.destroy(_vector + i);
				_allocator.construct(_vector + i, *(temp_vector + i + old_value));
			}
			for (size_type i = offset; i < range; i++) {
				if (i < _size)
					_allocator.destroy(_vector + i);
				_allocator.construct(_vector + i, val);
			}

			for (size_type i = 0; i < _size; i++) {
				temp_alloc.destroy(temp_vector + i);
			}
			temp_alloc.deallocate(temp_vector, _size);
			_size += n;
		}

		template <class Iterator>
		void insert(iterator position, Iterator first, Iterator last,
		            typename ft::enable_if<!ft::is_integral<Iterator>::value, Iterator>::type* = 0) {
			difference_type offset = position - this->begin(),
			                range = offset;
			size_type n = 0;
			for (Iterator temp = first; temp != last; temp++) {
				range++;
				n++;
			}
			size_type old_value =static_cast<size_type>(offset) - static_cast<size_type>(range),
			          new_size = _size + n;
			if (_size + n >= _capacity) {
				this->reserve(std::max(_capacity * 2, _size + n));
			}

			allocator_type temp_alloc;
			pointer temp_vector = temp_alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++) {
				temp_alloc.construct(temp_vector + i, *(_vector + i));
			}

			for (size_type i = static_cast<size_type>(range); i < new_size; i++) {
				if (i < _size)
					_allocator.destroy(_vector + i);
				_allocator.construct(_vector + i, *(temp_vector + i + old_value));
			}
			for (size_type i = static_cast<size_type>(offset); i < static_cast<size_type>(range); i++) {
				if (i < _size)
					_allocator.destroy(_vector + i);
				_allocator.construct(_vector + i, *first++);
			}

			for (size_type i = 0; i < _size; i++) {
				temp_alloc.destroy(temp_vector + i);
			}
			temp_alloc.deallocate(temp_vector, _size);
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
				ft::swap(_vector, x._vector);
				ft::swap(_size, x._size);
				ft::swap(_capacity, x._capacity);
				ft::swap(_allocator, x._allocator);
			}
			
			/********************** Allocator **********************************************/
			
			// returns a copy of the allocator objected associated with the vector

			allocator_type get_allocator() const
			{
				return _allocator;
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

		private:
			pointer							_vector;
			size_type						_size;
			size_type 						_capacity;
			allocator_type					_allocator;


	};

				/********************** Non-member function overloads  ****************************/

template <class T, class Allocator> 
bool operator==(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	
	for (size_t i = 0; i < lhs.size(); i++)
	{
		if (lhs.at(i) != rhs.at(i))
			return false;
	}
	return true;
}
	
template <class T, class Allocator>
bool operator!=(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs)
{
	return !(lhs == rhs);
}

template <class T, class Allocator> 
bool operator<(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs)
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Allocator>
bool operator<=(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs)
{
	return !(rhs < lhs);
}

template <class T, class Allocator> 
bool operator>(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs)
{
	return (rhs < lhs);
}

template <class T, class Allocator>
bool operator>=(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs)
{
	return !(lhs < rhs);
}

template <class T, class Allocator>
void swap(ft::vector<T, Allocator> &x, ft::vector<T, Allocator> &y)
{
	x.swap(y);
}
}


#endif