#include <map>
#include <fstream>
#include "child.h"
#include "files.hpp"
#include "sorts.h"
#include "search.h"
#include "hash.hpp"

int main()
{
    setlocale(LC_ALL, "Russian");

    const int p = 311;
    p_pows[0] = 1;
    for (size_t i = 1; i < p_pows.size(); ++i)
        p_pows[i] = p_pows[i - 1] * p;

    std::vector<std::vector<Child>> data = readInfo(naiveHash);

    HashTable nativeTable;

    std::chrono::steady_clock::time_point start, end;

    fout << "Простая хэш функция:\n" << '\n';

    start = std::chrono::steady_clock::now();

    for (int i = 0; i < sizesNum; ++i) {
        //заполнение таблицы
        for (int j = 0; j < data[i].size(); ++j)
            nativeTable.insert(data[i][j]);

        //поиск всех элементов для получения среднего результата
        for (int j = 0; j < data[i].size(); ++j) {
            Child objectToFind = data[i][j];
            nativeTable.find(objectToFind);
        }

        end = std::chrono::steady_clock::now();
        fout << "\"Простая\" реализация таблицы с " + std::to_string(data[i].size()) + " элементами:\n";
        writeTime("На поиск в среднем уходит: ", start, end, data[i].size());
        fout << "Коллизий: " << nativeTable.getCollisions() << "\n\n";
        nativeTable.clear();
        start = end;
    }

    data = readInfo(complicatedHash);

    HashTable complicatedTable;

    fout << "Сложная хэш функция:\n" << '\n';

    start = std::chrono::steady_clock::now();

    for (int i = 0; i < sizesNum; ++i) {
        //заполнение таблицы
        for (int j = 0; j < data[i].size(); ++j)
            complicatedTable.insert(data[i][j]);

        //поиск всех элементов для получения среднего результата
        for (int j = 0; j < data[i].size(); ++j) {
            Child objectToFind = data[i][j];
            complicatedTable.find(objectToFind);
        }

        end = std::chrono::steady_clock::now();
        fout << "\"Сложная\" реализация таблицы с " + std::to_string(data[i].size()) + " элементами:\n";
        writeTime("На поиск в среднем уходит: ", start, end, data[i].size());
        fout << "Коллизий: " << complicatedTable.getCollisions() << "\n\n";
        complicatedTable.clear();
        start = end;
    }
    exit(0);
}
