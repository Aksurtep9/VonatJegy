#ifndef HELY_H_INCLUDED
#define HELY_H_INCLUDED

#include <iostream>
//#include "memtrace.h"

class Kocsi;

class Hely {
	int helyId;
	bool foglalt_e;

	Kocsi *kocsi;
public:

	Hely();

	Hely(int helyID, bool foglalt_e, Kocsi *kocsi) :
		helyId(helyID), foglalt_e(foglalt_e), kocsi(kocsi){}
	int getHelyID() const { return helyId; }

	bool getFoglalt_e() { return foglalt_e; }

	Kocsi* getKocsi() { return kocsi; }

	Hely(const Hely& e) {
		*this = e;
	};

    Hely& operator=(const Hely&);

    void set_foglalt(){
        foglalt_e = true;
    }

    void set_szabad(){
        foglalt_e = false;
    }

	~Hely() {
        kocsi = NULL;
    }

};
std::ostream& operator<<(std::ostream& os, Hely& h);


#endif // HELY_H