#ifndef REVERSE_VECTOR_ITERATOR_HPP
#define REVERSE_VECTOR_ITERATOR_HPP

namespace ft
{
	template <typename T, bool B>
	class reverse_vector_iterator
	{
		public:
			typedef long int										difference_type;
			typedef T												value_type;
			typedef size_t											size_type;

			typedef std::random_access_iterator_tag 				iterator_category;
			typedef typename  chooseConst<B, T&, const T&>::type	reference;
			typedef typename  chooseConst<B, T*, const T*>::type	pointer;
			typedef T*												valPtr;

		private:
				valPtr		_val;
		
		public:
				// Default constructor
				reverse_vector_iterator(valPtr val = 0) : _val(val) {}
				
				// coppy constructor
				reverse_vector_iterator(const reverse_vector_iterator< T, false>& vec)
				{
					_val = vec.getValPtr();
				}

				// assigment operator constructor
				vector_iterato& operator=(const reverse_vector_iterator vec)
				{
					if (this != vec)
						_val = vec._val;
					return *this;
				}

				// Default destructor

				~reverse_vector_iterator() {}

				iterator

				// getter val return _val
				valPtr getValPtr() const
				{
					return _val;
				}

				// operator overloads

				// deference
				reference operator*() const 
				{ 
					return *_val; }

				//pointer 
				pointer operator->() const { return _val; }

				// increment	
				reverse_vector_iterator& operator++() 
				{
					--_val;
					return *this;
				}
				
				//decrement
				reverse_vector_iterator& operator--() 
				{
					++_val;
					return *this;
				}

				// post increment
				reverse_vector_iterator operator++(int) 
				{
					reverse_vector_iterator temp(*this);
					--(*this);
					return res;
				}

				// post decrement
				reverse_vector_iterator operator--(int) 
				{
					reverse_vector_iterator temp(*this);
					++(*this);
					return res;
				}

				// add on it

				reverse_vector_iterator& operator+=(difference_type n)
				{
					_val -= n;
					return *this;
				}

				reverse_vector_iterator& operator-=(difference_type n)
				{
					_val += n;
					return *this;
				}

				reverse_vector_iterator operator[](difference_type n) const
				{
					return _val[n];
				}

				reverse_vector_iterator operator+(difference_type n) const
				{
					return reverse_vector_iterator(_val - n);
				}

				reverse_vector_iterator operator-(difference_type n) const
				{
					return reverse_vector_iterator(_val + n);
				}

				bool operator==(const reverse_vector_iterator& vec) const
				{
					return vec._val == _val;
				}

				bool operator!=(const reverse_vector_iterator& vec) const
				{
					return vec._val != _val;
				}
				
				bool operator<(const reverse_vector_iterator& vec) const
				{
					return vec._val > _val;
				}

				bool operator<=(const reverse_vector_iterator& vec) const
				{
					return vec._val >= _val;
				}

				bool operator>(const reverse_vector_iterator& vec) const
				{
					return vec._val < _val;
				}

				bool operator>=(const reverse_vector_iterator& vec) const
				{
					return vec._val <= _val;
				}
	};

}

#endif