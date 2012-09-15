//::purge.h
// Delete pointers in an STL sequence container
#ifndef PURGE_H_
#define PURGE_H_

#include <algorithm>

template<class Seq>
void purge(Seq& c) {
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
