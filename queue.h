#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>

using namespace std;

// Структура узла
struct Node {
  string data;  // Данные в узле
  Node* next;   // Указатель на следующий узел
};

// Структура очереди
struct Queue {
  Node* front;  // Указатель на начало очереди
  Node* rear;   // Указатель на конец очереди
};

void CreateQueue(Queue& q);
bool isEmpty(const Queue& q);
void AddToQueue(Queue& q, string val);
string Pop(Queue& q);
string Peek(const Queue& q);
void ClearQ(Queue& q);
void PrintQ(const Queue& q);

#endif