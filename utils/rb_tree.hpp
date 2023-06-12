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
	bool is_black(const P& p)
	{
		return (p->_is_black);
	}

	template <typename P>
	bool is_red(const P& p)
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
}
#endif