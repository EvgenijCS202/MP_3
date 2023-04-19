#ifndef SEARCH_H
#define SEARCH_H
#include <vector>
#include "child.h"

std::vector<int> linearSearch(std::vector<Child>& v, std::string key);

int getLowerBound(std::vector<Child>& v, std::string key);

int getUpperBound(std::vector<Child>& v, std::string key);

std::vector<Child> binarySearch(std::vector<Child>& v, std::string key);

#endif // SEARCH_H
