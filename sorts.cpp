#include "sorts.h"

std::vector<Child> selectSort(std::vector<Child> vec) {
    std::vector<Child> a = vec;
    int min = 0; // индекс минимального значения
    for (int i = 0; i < a.size(); i++)
    {
        min = i; // изначально min - номер текущей ячейки
        for (int j = i + 1; j < a.size(); j++)
            if(a[j] < a[min])
                min = j;
        // после нахождения минимального элемента, поменяем его местами с текущим
        if(min != i)
            std::swap(a[i], a[min]);
    }
    return a;
}

std::vector<Child> insertSort(std::vector<Child> vec) {
    std::vector<Child> a = vec;
    int i, j;
    for (i = 0; i < a.size(); i++)
    {
        Child x = a[i];
        // Поиск места для вставки
        for (j=i-1; j>=0 && a[j] > x; j--)
            a[j+1] = a[j]; // двигаем неподходящие элементы
        a[j+1] = x; // Помещаем на нужное место
    }
    return a;
}

std::vector<Child> shakerSort(std::vector<Child> vec) {
    std::vector<Child> arr = vec;

    int control = arr.size() - 1;
    int left = 0;
    int right = arr.size() - 1;
    do {
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                control = i;
            }
        }
        right = control;
        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                control = i;
            }
        }
        left = control;
    } while (left < right);

    return arr;
}
