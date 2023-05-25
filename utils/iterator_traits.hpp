#ifndef ITERATOR_TRAIT_HPP
#define ITERATOR_TRAIT_HPP

/* 	
	SFINAE (substitution failure is not an error) used to prevent the instantiation
	of a template specialazation if the template do not meet certain requirments
	by check the template arguments
 */

/* 
	trait class defining properties of iterators, gives information about the
	iterator standard algorithm determines
	certain properties passed to them
 */
namespace ft
{
	// empty class to identify the catagory of an iterator as an input iterator
	struct input_iterator_tag {};

	// empty class to identify the catagory of an iterator as an output iterator
	struct output_iterator_tag {};

	/* 	
		empty class to identify the catagory of an iterator as an forward iterator
		can access element in the direction that goes from the begining
	 */
	struct forward_iterator_tag  : public input_iterator_tag {};

	/* 	
		empty class to identify the catagory of an iterator as an bidirectional iterator
		can access element in sequences of elements in a range of both direction
	 */
	struct bidirectional_iterator_tag : public forward_iterator_tag {};

	/* 	
		empty class to identify the catagory fo an iterator as an random access iterator
		can access element at arbitrary offset position relative to the position they point
	 */

	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	// iterator_triats template provides information about the iterators

	template <class Iterator>
	struct iterator_traits
		{
			typedef typename Iterator::value_type				value_type;
			typedef typename Iterator::pointer					pointer;
			typedef typename Iterator::reference					reference;
			typedef typename Iterator::difference_type			difference_type;
			typedef typename Iterator::iterator_category			iterator_category;
		};	

	/* 	
		the specialazion provides typedef for the memmber types
		this template is a specialazation for pointers to get information about
		the pointer
	 */
	template <class T>	
	struct iterator_traits<T*>	
		{	
			typedef T									value_type;
			typedef T*									pointer;
			typedef T&									reference;
			typedef std::ptrdiff_t						difference_type;
			typedef ft::random_access_iterator_tag 		iterator_category;
		};
	// specialization for constant pointer types
	template <class T>	
	struct iterator_traits<const T*>	
		{	
			typedef T									value_type;
			typedef const T*							pointer;
			typedef const T&							reference;
			typedef std::ptrdiff_t						difference_type;
			typedef ft::random_access_iterator_tag 		iterator_category;
		};

	template <class Category, class T, class Distance = std::ptrdiff_t,
				class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T 										value_type;
		typedef Pointer 								pointer;
		typedef Reference   							reference;
		typedef Distance 								difference_type;
		typedef Category 								iterator_category;
	};
	
}

#endif