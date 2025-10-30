#include "queue.h"

// Создание массива
void CreateQueue(Queue &q)
{
    q.front = nullptr;
    q.rear = nullptr;
}

// Проверка на пустоту очереди
bool isEmpty(const Queue &q)
{
    return q.front == nullptr;
}

// Добавление в очередь
void AddToQueue(Queue &q, string val)
{
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;

    if (isEmpty(q))
    {
        q.front = newNode;
        q.rear = newNode;
    }
    else
    {
        q.rear->next = newNode;
        q.rear = newNode;
    }
}

// Удаление элемента из начала очереди

string Pop(Queue &q)
{
    if (isEmpty(q))
    {
        return ""; // почему
    }
    Node *tmp = q.front;
    string value = tmp->data;

    q.front = q.front->next;
    delete tmp;

    if (q.front == nullptr)
    {
        q.rear = nullptr;
    }
    return value;
}

// Возвращение первого элемента очереди
string Peek(const Queue &q)
{
    if (isEmpty(q))
    {
        return "";
    }
    return q.front->data;
}

// Отчистка очереди
void ClearQ(Queue &q)
{
    while (!isEmpty(q))
    {
        Pop(q);
    }
}

// Вывод очереди
void PrintQ(const Queue &q)
{
    if (isEmpty(q))
    {
        cout << "Очередь пуста" << endl;
        return;
    }
    cout << "Очередь с начала: " << endl;
    for (Node *curr = q.front; curr; curr = curr->next)
    {
        cout << curr->data << "; ";
    }
    cout << endl;
}