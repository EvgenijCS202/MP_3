#ifndef CHILD_H
#define CHILD_H
#include <iostream>

class Child {
public:
    int year;
    int squad;
    std::string name;
    std::string date;
    int shift;
    unsigned long long (*hashFunc)(std::string);
    unsigned long long hash;

    Child(
    int year,
    int squad,
    std::string name,
    std::string date,
    int shift,
    unsigned long long (*hashFunc)(std::string)
    );

    friend bool operator== (const Child& a, const Child& b);
    friend bool operator< (const Child& a, const Child& b);
    friend bool operator<= (const Child& a, const Child& b);
    friend bool operator> (const Child& a, const Child& b);
    friend bool operator>= (const Child& a, const Child& b);

    friend std::ostream& operator<<(std::ostream& os, const Child& a);
};

#endif // CHILD_H
