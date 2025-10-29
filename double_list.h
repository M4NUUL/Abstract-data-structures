#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include <iostream>
#include <string>
using namespace std;

struct Node
{
   string data; // Значение узла
   Node* next; // Указатель на следующий элемент
   Node* prev; // Указатель на предыдущий элемент
};

struct DList
{
   Node* head; // Указатель на первый элемент
   Node* tail; // Указатель на предыдущий элемент
};


#endif