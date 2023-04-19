#ifndef HASH_HPP
#define HASH_HPP
#include <vector>
#include <string>
#include "child.h"

const int hashDims = 1000000;
std::vector<unsigned long long> p_pows(20);

unsigned long long naiveHash(std::string key) {
    unsigned long long result = 1;

    for (int i = 0; i < key.length(); ++i)
        result = (result * (key[i] - 'a' + 1)) % hashDims;

    return result % hashDims;
}

unsigned long long complicatedHash(std::string key) {
    unsigned long long hash = 0;
    for (size_t j = 0; j < key.length(); ++j)
        hash = (hash + (key[j] - 'a' + 1) * p_pows[j]);

    return hash % hashDims;
}

struct HashItem {
    std::vector<Child> values;
};

class HashTable {
    std::vector<HashItem> table;

public:
    HashTable() {
        table.resize(hashDims);
    }

    void insert(Child& item) {
        HashItem& currentItem = this->table[item.hash];

        //при совпадении элементов выходим
        for (auto i : currentItem.values)
            if (i.name == item.name)
                return;

        currentItem.values.push_back(item);
    }

    Child find(Child& item) {
        HashItem& currentItem = this->table[item.hash];

        for(int i = 0; i<currentItem.values.size(); ++i)
            if(currentItem.values[i].name == item.name)
                return currentItem.values[i];
        return item;
    }

    void clear() {
        this->table.clear();
        this->table.resize(hashDims);
    }


    unsigned int getCollisions() {
        unsigned int result = 0;

        for (auto n : this->table)
            if (n.values.size() > 1)
                result += n.values.size() - 1;

        return result;
    }
};

#endif // HASH_HPP
