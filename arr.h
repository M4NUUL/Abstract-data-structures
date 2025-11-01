#ifndef ARRAY_H
#define ARRAY_H

using namespace std;

// Структура для массива
struct Arr {
  string* data;  // Указатель на динамический массив
  int size;      // Текущий размер массива
};

void NewArray(Arr& arr);
void ClearArr(Arr& arr);
void AddToEnd(Arr& arr, const string& val);
void GetAt(const Arr& arr, int idx);
void AddAt(Arr& arr, int idx, const string& val);
void DelAt(Arr& arr, int idx);
void PrintArr(const Arr& arr);
void ChangeArr(Arr& arr, int idx, const string& val);
int LenArr(const Arr& arr);

#endif
