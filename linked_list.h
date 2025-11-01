#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
using namespace std;

struct Node {
  string value;  // Значение списка
  Node* next;    // Указатель на следующий элемент
};

struct List {
  Node* head;  // Указатель на начало списка
};

void CreateList(List& list);
void ClearList(List& list);
void AddToHead(List& list, string val);
void AddToEnd(List& list, const string& val);
void AddBefore(List& list);
void AddAfter(List& list);
void DelTail(List& list);
void DelVal(List& list, const string& val);
void FindVal(const List& list, const string val);
void PrintForward(const List& list);
void PrintBack(const List& list);
void DelHead(List& list);
void DelAfterVal(List& list, const string& val);
void DelBeforeVal(List& list, const string& val);

#endif