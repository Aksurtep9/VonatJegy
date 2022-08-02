
#include <sstream>
#include <ctime>


#include "datum.h"

Datum::Datum() {
    time_t tim;
    tim = time(NULL);       // lekérdezzük a jelenlegi időt
    struct tm* tp = localtime(&tim);  // átalakítjuk
    ev = tp->tm_year + 1900;
    ho = tp->tm_mon + 1;
    nap = tp->tm_mday;
    ora = 0;
    perc = 0;
}

std::ostream &operator<<(std::ostream &os, const Datum &datum) {
    os <<  datum.ev << "." << datum.ho << "." << datum.nap << " " << datum.ora << ":"
       << datum.perc;
    return os;
}

bool Datum::operator<(const Datum &rhs) const {
    if (ev < rhs.ev)
        return true;
    if (rhs.ev < ev)
        return false;
    if (ev == rhs.ev && ho < rhs.ho)
        return true;
    if (ev == rhs.ev && rhs.ho < ho)
        return false;
    if (ev == rhs.ev && ho == rhs.ho && nap < rhs.nap)
        return true;
    if (ev == rhs.ev && ho == rhs.ho && rhs.nap < nap)
        return false;
    if (ev == rhs.ev && ho == rhs.ho && rhs.nap == nap && ora < rhs.ora)
        return true;
    if (ev == rhs.ev && ho == rhs.ho && rhs.nap == nap && rhs.ora < ora)
        return false;
    return perc < rhs.perc;
}

bool Datum::operator>(const Datum &rhs) const {
    return rhs < *this;
}

bool Datum::operator<=(const Datum &rhs) const {
    return !(rhs < *this);
}

bool Datum::operator>=(const Datum &rhs) const {
    return !(*this < rhs);
}
