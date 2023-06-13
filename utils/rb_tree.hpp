#ifndef RB_TREE_HPP
#define RB_TREE_HPP
#include "pair.hpp"
#include <iostream>

namespace ft
{
	/* 	
		define a null pointer class with two public classes and one private class
		traditionally it was represeneted as NULL macro but this way it is more
		type safe way, helps to prevent errors 
	*/
	const class nullptr_t {
		public:
			template<class T>
			operator T*() const { return (0);}

			template<class T, class U>
			operator T U::*() const { return (0);}
		
		private:
			void operator&() const;

	} NIL = {};

	// class for the node of the binary tree

	template<typename T>
	struct TreeNode {
		typedef 			T value_type;

		TreeNode*			_parent;
		TreeNode*			_left;
		TreeNode*			_right;
		value_type  		_value;
		bool				_is_black;

		TreeNode() : _parent(ft::NIL), _left(ft::NIL), _right(ft::NIL), _value(value_type), _is_black(bool()) {}
		TreeNode(value_type& value) : _parent(ft::NIL), _left(ft::NIL), _right(ft::NIL), _value(value), _is_black(bool()) {}
		TreeNode(TreeNode& node) : _parent(node._parent), _left(node._left), _right(node._right), _value(node._value), _is_black(node._is_black) {}
		~TreeNode() {}

		TreeNode& operator=( const TreeNode& node) {
			if (this != &node)
			{
				_parent = node._parent;
				_left = node._left;
				_right = node._right;
				_value = node._value;
				_is_black = node._is_black;
			}
			return (*this);
		}
	};

	template <typename P>
	bool is_left_child(const P& p)
	{ 
		return (p == p->_parent->_left);
	}

	template <typename P>
	bool is_right_child(const P& p)
	{ 
		return (p == p->_parent->_right);
	}

	template <typename P>
	bool is_black_color(const P& p)
	{
		return (p->_is_black);
	}

	template <typename P>
	bool is_red_color(const P& p)
	{ 
		return (!(p->_is_black));
	}

	// return the minimum value iterating through the left elements
	template <typename P>
	P get_min_node(P p, P nil)
	{
		while (p->_left != nil)
			p = p->_left;
		return (p);
	}

	// return the maximum value iterating through the right elements
	template <typename P>
	P get_max_node(P p, P nil)
	{
		while (p->_right != nil)
			p = p->_right;
		return (p);
	}

	// if p->_right != nil find the minimum element from the left
	template <typename P>
	P get_next_node(P p, P nil)
	{
		if (p->_right != nil)
			return (get_min_node(p->_right, nil));
		while (!is_left_child(p))
			p = p->_parent;
		return (p->_parent);
	}

	// if p->_left != nil find the max element from the right
	template <typename P>
	P get_prev_node(P p, P nil)
	{
		if (p->_left != nil)
			return (get_max_node(p->_left, nil));
		while (!is_right_child(p))
			p = p->_parent;
		return (p->_parent);
	}

	template <typename U, typename V, class Comp>
	bool is_equal(const U& u, const V& v, Comp comp)
	{
		return (!comp(u, v) && (!comp(v, u)));
	}

	template <typename U, typename U>
	class tree_iterator
	{
		public:
			typedef	U																value_type;
			typedef value_type*														pointer;
			typedef value_type&														reference;
			typedef V*																iterator_type;
			typedef typename iterator_traits<iterator_type>::difference_type 		difference_type;
			typedef typename iterator_traits<iterator_type>::value_type 			node_type;
			typedef typename iterator_traits<iterator_type>::pointer 				node_pointer;
			typedef typename iterator_traits<iterator_type>::reference 				node_reference;
			typedef typename iterator_traits<iterator_type>::iterator_category 		iterator_category;
		
		private:
			node_pointer 		_current;
			node_pointer		_nil;
		
		public:
			tree_iterator() : _current(ft::NIL), _nil(ft::NIL) {}
			tree_iterator(node_pointer cur, node_pointer nil) : _current(cur), _nil(nil) {}
			tree_iterator(const tree_iterator& node) : _current(node._current), _nil(node._nil) {}
			~tree_iterator() {}

			tree_iterator& operator=(const tree_iterator& node)
			{
				if (this != node)
				{
					_current = node._current;
					_nil = node._nil;
				}
				return (*this);
			}

			node_pointer base() const
			{
				return (_current);
			}

			pointer operator->() const 
			{
				return (&_current->_value);
			}

			reference operator*() const
			{
				return (_current->_value);
			}

			tree_iterator operator++()
			{
				_current = get_next_node(_current, _nil)
				return (*this);
			}

			tree_iterator operator++(int)
			{
				tree_iterator tmp(*this);
				++(*this);
				return (tmp);
			}

			tree_iterator operator--()
			{
				_current = get_prev_node(_current, _nil)
				return (*this);
			}

			tree_iterator operator++(int)
			{
				tree_iterator tmp(*this);
				--(*this);
				return (tmp);
			}

			template <typename T>
			bool operator==(const tree_iterator<T, node_type>& x) const
			{
				return (_current == x.base());
			}

			template <typename T>
			bool operator!=(const tree_iterator<T, node_type>& x) const
			{
				return !(*this == x);
			}

			operator tree_iterator<const value_type, node_type>(void) const
			{
				return (tree_iterator<const value_type, node_type>(_current, _nil));
			}

			friend bool operator==(const tree_iterator& lhs, const tree_iterator& rhs)
			{
				return (lhs._current == rhs._current);
			}

			friend bool operator!=(const tree_iterator& lhs, const tree_iterator& rhs)
			{
				return (!(lhs == rhs));
			}
	};

		template <typename Alloc>
		struct allocator_traits
		{
			typedef typename Alloc::value_type 				value_type;
			typedef typename Alloc::pointer					pointer;
			typedef typename Alloc::const_pointer			const_pointer;

			static Alloc allocator(Alloc& a, std::size_t n)
			{
				return a.allocate(n);
			}

			static void deallocate(Alloc& a, value_type* p, std::size_t n)
			{
				a.deallocate(p, n);
			}

			template <typename T>
			static void construct(Alloc& a, T* p, const T& val)
			{
				a.construct(p, val);
			}

			template <typename T>
			static void destroy(Alloc& a, T* p)
			{
				a.destroy(p);
			}

		};

		// red-black tree class

		template <typename T, class Key, class Comp, class Allocator>
		class rbtree
		{
			public:
				typedef T									 						value_type;
				typedef Key									 						key_type;
				typedef Comp								 						compare_type;
				typedef TreeNode<value_type>				 						node_type;			
				typedef TreeNode<value_type>*				 						node_pointer;			
				typedef tree_iterator<value_type, node_type> 						iterator;
				typedef tree_iterator<const value_type, node_type> 					const_iterator;
				typedef Allocator								   					allocator_type;
				typedef typename allocator_type::template rebind<node_type>::other 	node_allocator;
				typedef ft::allocator_traits<node_allocator>  					   	node_traits;
				typedef std::size_t							  					   	size_type;
				typedef std::ptrdiff_t  					  					   	difference_type;

			private:
				node_pointer 			_nil;
				node_pointer 			_begin;
				node_pointer 			_end;
				node_pointer 			_comp;
				compare_type 			_comp;
				node_allocator  		_alloc;
				size_type 				_size;

			/********************** MEMBER FUNCTIONS *********************************/
			
			// Default constructor with comp and alloc argument , set left, right and parent to NIL
			// and allocate 1 size, since it is the root it is black 
			public:
				rbtree(const compare_type& comp, const allocator_type& alloc) : _comp(comp), _alloc(alloc), _size(size_type())
				{
					_nil = _alloc.allocate(1);
					_alloc.construct(_nil, value_type());
					_nil->_is_black = true;
					_nil->_parent = _nil;
					_nil->_left = _nil;
					_nil->_right = _nil;
					_end = creae_node(value_type());
					_end->_is_black = true;
					_begin = _end;
				}
			
			// Default copy constructor
			public:
				rbtree(const rbtree& node) : _comp(node._comp), _alloc(node._alloc), _size(size_type())
				{
					_nil = _alloc.allocate(1);
					_alloc.construct(_nil, value_type());
					_nil->_is_black = true;
					_nil->_parent = _nil;
					_nil->_left = _nil;
					_nil->_right = _nil;
					_end = creae_node(value_type());
					_end->_is_black = true;
					_begin = _end;
					insert(node.begin(), node.end());
				}

				~rbtree()
				{
					delete_node_recursive(_end);
					delete_node(_nil);
				}

				// Assignment constructor create temp rbtree and swap it to this
				// with out changing node
				rbtree& operator=(const rbtree& node)
				{
					if (this != &node)
					{
						rbtree tmp(node);
						swap(tmp);
					}
					return (*this);
				}

			/********************** ITERATORS *********************************/

				// return begin and end elements
				iterator begin()
				{
					return (iterator(_begin, _nil));
				}

				const_iterator begin() const
				{
					return (const_iterator(_begin, _nil));
				}

				iterator end()
				{
					return (iterator(_end, _nil));
				}

				const_iterator end() const
				{
					return (const_iterator(_end, _nil));
				}

			/********************** CAPACITY *********************************/

				// empty check if the map is empty, size return the size of map
				// and max_size returns the maximum size of the map

				bool empty () const
				{
					return (_size == 0);
				}

				size_type size() const
				{
					return (_size);
				}

				size_type max_size() const
				{
					return (_alloc.max_size());
				}

			/********************** MODIFIERS *********************************/
				
				/*
					insert the pair key and value
					insert the value in the position
					insert starting first to last
				*/
				ft::pair<iterator, bool> insert(const value_type& value)
				{
					node_pointer ptr = search_parent(value);

					if (ptr != _end && is_equal(ptr->_value, value, _comp));
						return (ft::make_pair(iterator(ptr, _nil), false));
					return (ft::make_pair(iterator(insert_internal(value , ptr), true)));
				}

				iterator insert(iterator position, const value_type& value)
				{
					node_pointer ptr = search_parent(value, position.base());

					if (ptr != _end && is_equal(ptr->_value, value, _comp));
						return (iterator(ptr, _nil));
					return (iterator(insert_internal(value , ptr), _nil));
				}

				template <class InputIterator>
				void insert(InputIterator first, InputIterator last)
				{
					for (; first != last; first++)
						insert(*first)
				}

				/*
					erase the value on the iterator position
					erase based on the value
					erase elements from first to last
				*/
				iterator erase(iterator position)
				{
					if (_size == 0)
						return (iterator(_nil, _nil));
					
					iterator tmp(position)
					++tmp;
					if (position == begin())
						_begin = tmp.base();
					--_size;
					remove_internal(position.base());
					delete_node(position.base());
					return (tmp);
				}

				size_type erase(const key_type& value)
				{
					iterator i(find_internal(value), _nil);

					if (i == end())
						return (0);
					if (i == begin())
					{
						iterator tmp(i);
						++tmp;
						_begin = tmp.base();
					}
					--_size;
					remove_internal(i.base());
					delete_node(i.base());
					return (1);
				}

				void erase (iterator first, iterator last)
				{
					for (; first != last;)
						first = erase(first);
				}

				/*
					swap the the map using std::swap
				*/
				void swap(rtree& node)
				{
					std::swap(_nil, node._nil);
					std::swap(_begin, node._begin);
					std::swap(_end, node._end);
					std::swap(_comp, node._comp);
					std::swap(_alloc, node._alloc);
					std::swap(_size, node._size);
				}

				// clear the map with the default constructor which set it to empty;
				void clear (void)
				{
					rbtree tmp(_comp, _alloc);
					swap(tmp);
				}
			/********************** OPERATIONS *********************************/

				//finds the element based on the key using find_internal
				iterator find(const key_type& key)
				{
					return (iterator(find_internal(key), _nil));
				}

				const_iterator find(const key_type& key) const
				{
					return (const_iterator(find_internal(key), _nil));
				}

				// returns the lower first iterator from the key	
				iterator lower_bound(const key_type& key)
				{
					return (iterator(lower_bound_internal(key), _nil));
				}

				const_iterator lower_bound(const key_type& key) const
				{
					return (const_iterator(lower_bound_internal(key), _nil));
				}
				
				// returns the first higher iterator from the key
				iterator upper_bound(const key_type& key)
				{
					return (iterator(upper_bound_internal(key), _nil));
				}

				const_iterator upper_bound(const key_type& key) const
				{
					return (const_iterator(upper_bound_internal(key), _nil));
				}

				ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const
				{
					return (equal_range_internal(key));
				}

				ft::pair<iterator, iterator> equal_range(const key_type& key)
				{
					return (equal_range_internal(key));
				}

			/********************** ALLOCATOR *********************************/

				allocator_type get_allocator() const
				{
					return (_alloc);
				}
			
			private:
				// get the root which is _end->_left
				node_pointer get_root() const
				{
					return (_end->_left);
				}

				// set the ptr to root by changing the ptr parent to end
				// and assign the ptr to the end->left
				void set_root(const node_pointer ptr)
				{
					ptr->_parent = _end;
					_end->_left = ptr;
				}
				
				// create a single node first allocate and construct using allocate member functions
				node_pointer create_node(const value_type& value)
				{
					node_pointer ptr = _alloc.allocate(1);

					_alloc.construct(ptr, value);
					ptr->_parent = _nil;
					ptr->_left = _nil;
					ptr->_right = _nil;
					ptr->_is_black = false;
					return (ptr);
				}

				// delete a single node by using destroy and deallocate member functions
			
				void delete_node(node_pointer ptr)
				{
					_alloc.destroy(ptr);
					_alloc.deallocate(ptr, 1);
				}

				// delete multiple nodes recursively until the ptr equals to NIL
				void delete_node_recursive(node_pointer ptr)
				{
					if (ptr == _nil)
						return ;
					delete_node_recursive(ptr->_left);
					delete_node_recursive(ptr->_right);
					delete_node(ptr);
				}

				// searches for the parent of the given value

				node_pointer search_parent(const value_type& value, node_pointer position = ft::NIL)
				{
					if (position && position != _end)
					{
						// if the right value is nil parent value is begin
						if (_comp(value, position->_value) && position->_left == _nil)
						{
							iterator prev = iterator(position, _nil);
							if (prev == begin() || _comp(*--prev, value))
								return (position);
						}
						// if the left value is nil parent value is end
						else if (position->_right == _nil)
						{
							iterator next = iterator(position, _nil)
							if (next == end() || _comp(value, *++next))
								return (postion);
						}
					}
					node_pointer cur = get_root();
					node_pointer tmp = _end;
					/* 				
						if it is not begin or end it search the element, if it is less
						it is less return cur->left else it is the right, if nothing match
						return the value;
					 */
					for (; cur != _nil;)
					{
						tmp = cur;
						if (_comp(value, cur->value))
							cur = cur->_left;
						else if (_comp(cur->_value, value))
							cur = cur->_right;
						else
							return (cur);
					}
					return (tmp);
				}

				// insert a node inside the tree

				node_pointer insert_internal(const value_type& value, node_pointer parent)
				{
					// creates a single node;
					node_pointer ptr = create_node(value);

					// if the parent is end set the new node root;
					if (parent == _end)
						set_root(ptr);
					// else if value is less thatn parent value assign the new node as left node
					else if (_comp(value, parent->_value))
						parent->_left = ptr;
					// else  assign the new node as right node
					else
						parent->_right = ptr;
					
					ptr->_parent = parent;
					insert_fixup(ptr);
					insert_update(ptr);
					return (ptr);
				}

				// fixes the tree after inserting a node so the tree will be balanced

				void insert_fixup(node_pointer ptr)
				{
					while (is_red_color(ptr->_parent))
					{
						if (is_left_child(ptr->_parent))
							insert_fixup_left(ptr);
						else
							insert_fixup_right(ptr);
					}
					get_root()->_is_black = true;
				}

				// fix the left child

				void insert_fixup_left(node_pointer& ptr)
				{
					node_pointer uncle = ptr->_parent->_parent->_right;

					if (is_red_color(uncle))
					{
						ptr->_parent->_is_black = true;
						uncle->_is_black = true;
						uncle->_parent->_is_black = false;
						ptr = uncle->_parent;
					}
					else
					{
						if (is_right_child(ptr))
						{
							ptr = ptr->_parent;
							rotate_left(ptr);
						}
						ptr->_parent->_is_black = true;
						ptr->_parent->_parent->_is_black = false;
						rotate_right(ptr->_parent->_parent);
					}
				}
				// fix the right child

				void insert_fixup_right(node_pointer& ptr)
				{
					node_pointer uncle = ptr->_parent->_parent->_left;

					if (is_red_color(uncle))
					{
						ptr->_parent->_is_black = true;
						uncle->_is_black = true;
						uncle->_parent->_is_black = false;
						ptr = uncle->_parent;
					}
					else
					{
						if (is_left_child(ptr))
						{
							ptr = ptr->_parent;
							rotate_right(ptr);
						}
						ptr->_parent->_is_black = true;
						ptr->_parent->_parent->_is_black = false;
						rotate_left(ptr->_parent->_parent);
					}
				}

				// update size and the begining after inserting a node

				void insert_update(const node_pointer ptr)
				{
					if (_begin == _end || _comp(ptr->_value, _begin->_value))
						_begin = ptr;
					_size++;
				}

				// remove a node from the tree

				void remove_internal(node_pointer ptr)
				{
					node_pointer recolor_node;
					node_pointer fixup_node = ptr;
					bool original_color = is_black_color(ptr);

					if (ptr->_left == _nil)
					{
						recolor_node = ptr->_right;
						transplant(ptr, ptr->_right);
					}
					else if (ptr->_right == _nil)
					{
						recolor_node = ptr->_left;
						transplant(ptr, ptr->_left);
					}

				}
		};
}

#endif