
#ifndef DATUM_H_INCLUDED
#define DATUM_H_INCLUDED

#include <ostream>
//#include "memtrace.h"

class Datum {
	int ev;
	int ho;
	int nap;
	int ora;
	int perc;
public:
	/// Param�ter n�lk�l h�vhat� konstruktor
	/// Mai napot �ll�tja be
	/// 0 �ra 0 perc
	Datum();

	Datum(int ev, int ho, int nap, int ora, int perc): 
		ev(ev), ho(ho), nap(nap), ora(ora), perc(perc){}

	int getEv() const { return ev;}

	int getHo() const { return ho; }

	int getNap() const { return nap; }

	int getOra() const { return ora; }

	int getPerc() const { return perc; }


    friend std::ostream &operator<<(std::ostream &os, const Datum &datum);

    bool operator<(const Datum &rhs) const;

    bool operator>(const Datum &rhs) const;

    bool operator<=(const Datum &rhs) const;

    bool operator>=(const Datum &rhs) const;
};

#endif