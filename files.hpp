#ifndef FILES_H
#define FILES_H
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>
#include "child.h"

std::string info = "info.txt";
std::string resultFile = "res.txt";
std::string timesFile = "times.txt";

std::ofstream fout(resultFile);

int sizesNum = 7;

int sizes[7] = { 100, 1000, 2000, 5000, 10000, 25000, 100000 };

std::string randomString(const int len) {
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);
    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return tmp_s;
}

std::string randomDate(int minY, int maxY)
{
    return std::to_string(rand() % 28 + 1)+'.'+std::to_string(rand() % 12+1)+'.'+std::to_string(minY + rand() % (maxY - minY));
}

void createInfo() {
    srand((unsigned)time(NULL));
    std::ofstream fout(info);

    for (int i = 0; i < sizesNum; ++i) {
        //Вывод числа записей
        fout << sizes[i] << "\n";
        for (int j = 0; j < sizes[i]; ++j) {
            //Вывод полей по порядку
            fout << 2016 - rand() % 40 << "\n";   // Год
            fout << rand() % 13 + 1 << "\n";   // Отряд
            fout << randomString(10)  << "\n";   // ФИО
            fout << randomDate(1990, 2016) << "\n"; // Дата рождения
            fout << rand() % 5 + 1 << "\n"; // Смена
        }
    }
}

std::vector<std::vector<Child>> readInfo(unsigned long long (*hashFunc)(std::string)) {
    std::ifstream fin(info);

    std::vector<std::vector<Child>> result;

    int dim;
    int year;
    int squad;
    std::string name;
    std::string date;
    int shift;

    for (int i = 0; i < sizesNum; ++i) {
        //Ввод числа записей
        fin >> dim;
        std::vector<Child> v;
        for (int j = 0; j < dim; ++j) {
            //Ввод полей по порядку
            fin >> year >> squad >> name >> date >> shift;
            Child temp(year, squad, name, date, shift, hashFunc);
            v.push_back(temp);
        }
        result.push_back(v);
    }

    return result;
}

void writeResult(std::string title, std::vector<std::vector<Child>>& res) {
    std::ofstream fout(resultFile, std::ios::app);

    fout << title << "\n";

    for (int i = 0; i < sizesNum; ++i) {
        //Вывод числа записей
        fout << "Размер: " << res[i].size() << "\n";
        for (int j = 0; j < res[i].size(); ++j) {
            //Вывод объекта
            fout << res[i][j] << "\n";
        }
    }
}

void writeTime(std::string title, std::chrono::steady_clock::time_point start, std::chrono::steady_clock::time_point end, int divideBy) {
    fout << title;

    fout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / divideBy << " [микросекунд]\n";
}

#endif // FILES_H
