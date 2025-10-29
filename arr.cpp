#include "arr.h"
#include <iostream>

using namespace std;

// Инициализация массива
void NewArray(Arr &arr) {
    arr.data = nullptr;
    arr.size = 0;
}

// Освобождение памяти
void ClearArr(Arr &arr) {
    delete[] arr.data;
    arr.data = nullptr;
    arr.size = 0;
}

// Добавление в конец массива
void AddToEnd(Arr &arr, const string& val) {
    string* newData = new string[arr.size + 1];
    for (int i = 0; i < arr.size; i++) {
        newData[i] = arr.data[i];
    }
    newData[arr.size] = val;
    delete[] arr.data;
    arr.data = newData;
    arr.size++;
}

// Вывод элемента по индексу
void GetAt(const Arr &arr, int idx) {
    if (idx < 0 || idx >= arr.size) {
        cout << "Ошибка: некоректный индекс." << endl;
        return;
    }
    cout << arr.data[idx] << " - Расположен по индексу: " << idx << endl;
}

// Вставка по индексу
void AddAt(Arr &arr, int idx, const string& val) {
    if (idx < 0 || idx >= arr.size) {
        cout << "Ошибка: некоректный индекс." << endl;
        return;
    }
    string* newData = new string[arr.size + 1];
    for (int i = 0; i < idx; i++) {
        newData[i] = arr.data[i];
    }
    newData[idx] = val;
    for (int i = idx; i < arr.size; i++) {
        newData[i+1] = arr.data[i];
    }
    delete[] arr.data;
    arr.data=newData;
    arr.size++;
    cout << val << " - Добавлен по индексу: " << idx << endl; 
}

// Удаление по индексу
void DelAt(Arr &arr, int idx) {
    if (idx < 0 || idx >= arr.size) {
        cout << "Ошибка: некоректный индекс." << endl;
        return;
    }    
    string* newData = new string[arr.size - 1];
    for(int i = 0; i < idx; i++) {
        newData[i] = arr.data[i];
    }
    for (int i = idx + 1; i < arr.size; i++) {
        newData[i-1] = arr.data[i];
    }
    delete[] arr.data;
    arr.data = newData;
    arr.size--;
    cout << "Элемент удален (по индексу: " << idx << ")" << endl;
}

// Вывод массива
void PrintArr(const Arr &arr) {
    if (arr.size == 0) {
        cout << "Массив пуст";
        return;
    }
    for (int i = 0; i < arr.size; i++) {
        cout << arr.data[i] << "; ";
    }
    cout << endl;
}

void ChangeArr(Arr &arr, int idx, const string& val) {
    if (idx < 0 || idx >= arr.size) {
        cout << "Ошибка: некоректный индекс." << endl;
        return;
    }
    arr.data[idx] = val;
    cout << "Элемент по индексу " << idx << " заменен на " << val << endl;
}

int LenArr(const Arr &arr) {
    return arr.size;
}