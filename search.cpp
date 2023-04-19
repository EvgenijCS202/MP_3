#include "search.h"

std::vector<int> linearSearch(std::vector<Child>& v, std::string key) {
    std::vector<int> res;
    for (int i = 0; i < v.size(); ++i)
        if (v[i].name == key)
            res.push_back(i);
    return res;
}

int getLowerBound(std::vector<Child>& v, std::string key) {
    int mid = 0, left = 0, right = v.size();
    while (1)
    {
        mid = (left + right) / 2;

        if (mid < 0 || mid >= v.size())
            return -1;

        if (key <= v[mid].name)
            right = mid - 1;
        else if (key > v[mid].name && mid + 1 < v.size() && key == v[mid + 1].name)
            return mid;
        else if (key > v[mid].name)
            left = mid + 1;

        if (left > right)
            return -1;
    }
}

int getUpperBound(std::vector<Child>& v, std::string key) {
    int mid = 0, left = 0, right = v.size();
    while (1)
    {
        mid = (left + right) / 2;

        if (mid < 0 || mid >= v.size())
            return -1;

        if (key < v[mid].name && mid - 1 >= 0 && key == v[mid - 1].name)
            return mid;
        else if (key < v[mid].name)
            right = mid - 1;
        else if (key >= v[mid].name)
            left = mid + 1;

        if (left > right)
            return -1;
    }
}

std::vector<Child> binarySearch(std::vector<Child>& v, std::string key) {
    int left = getLowerBound(v, key);
    int right = getUpperBound(v, key);

    if (left == -1 || right == -1)
        return std::vector<Child>();

    auto first = v.cbegin() + left + 1;
    auto last = v.cbegin() + right;

    std::vector<Child> res(first, last);

    return res;
}
