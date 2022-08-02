#include "hely.h"
#include "kocsi.h"

Hely::Hely()
{
	helyId = 0;
	foglalt_e = false;
	kocsi = NULL;
}

std::ostream& operator<<(std::ostream& os, Hely& h) {
	os << "Hely: " << h.getHelyID();
	if(h.getFoglalt_e()==1) {
        os << " Foglalt-e: " << "Foglalt";
    }
	    else
	        os << " Foglalt-e: " << "Szabad";


	return os;
}


Hely& Hely::operator=(const Hely& h)
{
	helyId = h.helyId;
	foglalt_e = h.foglalt_e;
	//vonat = h.vonat;
	kocsi = h.kocsi;
	return *this;
}

