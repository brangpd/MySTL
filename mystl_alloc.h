//
// Created by brang on 1/18/19.
//

#ifndef MYSTL_MYSTL_ALLOC_H
#define MYSTL_MYSTL_ALLOC_H

#include "mystl_config.h"
#include "mystl_construct.h"

BEGIN_NAMESPACE_MYSTD

template <class T, class Alloc>
class simple_alloc
{
public:
	static T*allocate(size_t n)
	{
		return n ? (T*)Alloc::allocate(n * sizeof(T)) : 0;
	}

	static T*allocate()
	{
		void*tmp = Alloc::allocate(sizeof(T));
		return (T*)tmp;
	}

	static void deallocate(T*p, size_t n)
	{
		if (n)Alloc::deallocate(p, n * sizeof(T));
	}

	static void deallocate(T*p)
	{
		Alloc::deallocate(p, 1);
	}
};

END_NAMESPACE_MYSTD

#endif //MYSTL_MYSTL_ALLOC_H
