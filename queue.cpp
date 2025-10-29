#include "queue.h"

// Создание массива
void CreateQueue(Queue &q)
{
    q.front = nullptr;
    q.rear = nullptr;
}

// Проверка на пустоту очереди
bool isEmpty(const Queue& q)
{
    return q.front == nullptr;
}