#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <functional>
#include "utils/pair.hpp"
#include "utils/lexicographical_compare.hpp"
#include "utils/reverse_iterator.hpp"

namespace ft
{
	template <
	class Key, 
	class T,
	class Compare = std::less<Key>, 
	class Allocator = std::allocator<ft::pair<const Key, T>>
	>
	class map
	{
		public:
			typedef Key 																				key_type;
			typedef T 																					mapped_type;
			typedef ft::pair<const key_type, mapped_type>												value_type;	
			typedef value_type&																			reference;
			typedef const value_type&																	const_reference;
			typedef Compare																				key_compare;
			typedef Allocator																			allocator_type;
			typedef typename allocator_type::template rebind<value_type>::other 						type_allocator;
			typedef std::allocator_traits<allocator_type> 												type_traits;
			typedef typename type_traits::pointer 														pointer;
			typedef typename type_traits::const_pointer 												const_pointer;
			typedef size_t																				size_type;
			typedef	std::ptrdiff_t 																		difference_type;
			typedef typename ft::rbtree<value_type, value_compare, allocator_type>::iterator    		iterator;
			typedef typename ft::rbtree<value_type, value_compare, allocator_type>::const_iterator    	const_iterator;
			typedef ft::reverse_iterator<iterator>														reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>												const_reverse_iterator;

			// return a comparision objects that can be used to compare two elements to get
			// whether the key of the first one goes before the second.
			
			/********************** MEMBER CLASS *********************************/

			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				protected:
					key_compare comp;
				public:
					value_compare(key_compare c) : comp(c) {}
					~value_compare() {}

					bool operator()(const value_type& x, const value_type& y) const
					{
						return (comp(x.first, y.first));
					}
			};

			/********************** MEMBER FUNCTIONS *********************************/

			private:
				key_compare 														_key_comp;
				value_compare 														_val_comp;
				ft::rbtree<value_type, key_type, value_compare, allocator_type> 	_tree;

			public:	
				explicit map( const key_compare& comp = key_compare(), const Allocator& alloc = Allocator()) :
				_key_comp(comp), _val_comp(comp), _tree(_val_comp, alloc){}

				template<class InputIt>
				map(InputIt first, InputIt last, const key_compare& comp = key_compare(), cosnt Allocator& alloc = Allocator()) :
				_key_comp(comp), _val_comp(comp), _tree(_value_comp, alloc)
				{
					insert(firts, last);
				}
				map(const map& other) : _key_comp(other._key_comp), _val_comp(other._val_comp), _tree(other._tree) {}

				~map() {}

				map& operator=(const map& x)
				{
					if (this != &x)
					{
						_key_comp = x._key_comp;
						_val_comp = x._val_comp;
						_tree = x._tree;
					}
					return (*this);
				}
		
			/********************** ELEMENT ACCESS *********************************/

			mapped_type& at (const key_type& key)
			{
				iterator it = find(key)
				if (it == end())
					throw std::out_of_range("map at");
				return (it->second);
			}
			
			const mapped_type& at (const key_type& key) const
			{
				const_iterator it = find(key)
				if (it == end())
					throw std::out_of_range("map at");
				return (it->second);
			}

			// returns a reference to the value that is mapped to a key or insert
			// if such key does not alread exist

			mapped_type& operator[](const key_type& key)
			{
				ft::pair<iterator, bool> p = insert(ft::make_pair(k, mapped_type()));
				return (p.first->second);
			}
			
			/********************** ITERATORS *********************************/

			iterator begin() { return (_tree.begin()); }

			const_iterator begin() { return (_tree.begin()); }

			iterator end() { return (_tree.end()); }

			const_iterator end() { return (_tree.end()); }

			reverse_iterator rbegin() { return (reverse_iterator.end()); }

			const_reverse_iterator begin() { return (reverse_iterator.end()); }

			reverse_iterator rend() { return (reverse_iterator.begin()); }

			const_reverse_iterator rend() { return (reverse_iterator.begin()); }

			/********************** CAPACITY *********************************/

			bool empty () const { return _tree.empty(); }

			size_type size () const { return (_tree.size()); }
			
			size_type max_size () const { return (_tree.max_size()); }

			/********************** MODIFIERS *********************************/

			void clear () { _tree.clear();}

			ft::pair<iterator, bool> insert(const value_type& value) {
				return (_tree.insert(value));
			}

			iterator insert(iterator pos, const value_type& value) {
				return (_tree.insert(pos, value));
			}

			template<class InputIt>
			void insert(InputIt first, InputIt last) {
				return (_tree.insert(first, last));
			}

			void erase(iterator position) { _tree.erase(position);}

			size_type erase (const key_type& k) { return (_tree.erase(k));}

			void erase (iterator first, iterator last) { _tree.erase(first, last); }

			void swap (map& x) { _tree.swap(x._tree);}

			/********************** OPERATIONS *********************************/
			




	};
}
#endif