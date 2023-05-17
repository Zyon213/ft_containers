#ifndef VECTOR_HPP
#define VECTOR_HPP

/* 
	std::ios_base::Init this class is used to ensure that the default c++ stream(std::cin,
	std::cout, etc) are properly initialized and destructed.(when the first instance
	is consructed as well as flushes the output when the last instance is
	destructed), and <iostream> behaves as if it defines std::ios_base::Init with
	storage duration. 
*/
#include <iostream>
/* 
	memory header is part of the dynamic memory management library
	allocator class template is default Allocator used by all standard library containers
 */
#include <memory>

// exception is the part of error handling library
#include <exception>

#endif