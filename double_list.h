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

void CreateList(DList &list);
void AddHead(DList &list);
void AddToTail(DList &list, string val);
void AddBeforeVal(DList &list);
void AddAfterVal(DList &list);
void DelHead(DList &list);
void DelTail(DList &list);
void DelVal(DList &list, const string &val);
Node *findVal(const DList &list, const string &val);
void PrintForward(const DList &list);
void PrintBackward(const DList &list);
void ClearList(DList &list);
void DelAfterVal(DList &list, const string &val);
void DelBeforeVal(DList &list, const string &val);

#endif