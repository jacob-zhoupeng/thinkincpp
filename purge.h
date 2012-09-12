//::purge.h
// Delete pointers in an STL sequence container
#ifndef PURGE_H_
#define PURGE_H_

#include <algorithm>

template<class Seq>
void purge(Seq& c) {
    //! 增加了typedef，原文没有，现在gcc-4.6.2编译通过
	typedef typename Seq::iterator It;
	for (It i = c.begin(); i != c.end(); i++) {
		delete *i;
		*i = 0;
	}
}

// Iterator version:
template<class InpIt>
void purge(InpIt begin, InpIt end) {
	while (begin != end) {
		delete *begin;
		*begin = 0;
		begin++;
	}
}

#endif // PURGE_H_ ///:~
