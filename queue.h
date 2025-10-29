#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>

using namespace std;

// Структура узла
struct Node
{
    string data; // Данные в узле
    Node* next;  // Указатель на следующий узел
};

// Структура очереди
struct Queue
{
    Node* front; // Указатель на начало очереди
    Node* rear; // Указатель на конец очереди 
};



#endif