#include "child.h"

Child::Child(
    int year,
    int squad,
    std::string name,
    std::string date,
    int shift,
    unsigned long long (*hashFunc)(std::string)
    )
    {
        this->year = year;
        this->squad = squad;
        this->name = name;
        this->date = date;
        this->shift = shift;
        this->hashFunc = hashFunc;
        this->hash = hashFunc(name);
}

bool operator== (const Child& a, const Child& b) {
    return (a.year == b.year && a.squad == b.squad && a.name == b.name && a.shift == b.shift)?true:false;
}

bool operator< (const Child& a, const Child& b) {
    return (a.name < b.name);
//    return (a.year < b.year || ((a.year == b.year) && (a.squad < b.squad)) ||
//            ((a.year == b.year) && (a.squad == b.squad) && (a.shift < b.shift))||
//            ((a.year == b.year) && (a.squad == b.squad) && (a.shift == b.shift) && (a.name < b.name)))?true:false;
}

bool operator<= (const Child& a, const Child& b) {
    return (a < b || a == b)?true:false;
}

bool operator> (const Child& a, const Child& b) {
    return (!(a < b) && !(a == b))?true:false;
}

bool operator>= (const Child& a, const Child& b) {
    return (!(a < b))?true:false;
}


std::ostream& operator<<(std::ostream& os, const Child& a) {
    os << a.year << ' ' << a.squad << ' ' << a.name << ' ' << a.date << ' ' << a.shift << '\n';
    return os;
}
