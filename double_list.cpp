#include "double_list.h"

using namespace std;

void CreateList(DList &list)
{
   list.head = nullptr;
   list.tail = nullptr;
}

// Добавление в начало массива
void AddHead(DList &list)
{
   cout << "Введите значение: ";
   string val;
   cin >> val;

   Node *node = new Node{val, list.head, nullptr};

   if (list.head)
   {
      list.head->prev = node;
   }
   else
      list.tail = node;

   list.head = node;
}

// Добавление в конец массива
void AddToTail(DList &list, string val)
{
   Node *node = new Node{val, nullptr, list.tail};

   if (list.tail)
      list.tail->next = node;
   else
      list.head = node;

   list.tail = node;
}

// Добавление перед элементом
void AddBeforeVal(DList &list)
{
   if (!list.head)
   {
      cout << "Список пуст" << endl;
      return;
   }

   cout << "Введите значение перед которым вставить: ";
   string target, val;
   cin >> target;

   cout << "Введите новое значение";
   cin >> val;

   for (Node *curr = list.head; curr; curr = curr->next)
   {
      if (curr->data == target)
      {
         Node *node = new Node{val, curr, curr->prev};
         if (curr->prev)
         {
            curr->prev->next = node;
         }
         else
            list.head = node;
         curr->prev = node;
         cout << "Элемент добавлен перед " << target << " не найден" << endl;
      }
   }
}

// Добавление после элемента
void AddAfterVal(DList &list)
{
   if (!list.head)
   {
      cout << "Список пуст" << endl;
      return;
   }

   cout << "Введите значение после которого вставить: ";
   string target, val;
   cin >> target;
   cout << "Введите новое значение: ";
   cin >> val;

   for (Node *curr = list.head; curr; curr = curr->next)
   {
      if (curr->data == target)
      {
         Node *node = new Node{val, curr->next, curr};
         if (curr->next)
         {
            curr->next->prev = node;
         }
         else
            list.tail = node;
         curr->next = node;
         cout << "Элемент добавлен после " << target << endl;
         return;
      }
   }
   cout << "Элемент " << target << " не найден" << endl;
}

// Удалить первый элемент
void DelHead(DList &list)
{
   if (!list.head)
   {
      cout << "Список пуст" << endl;
      return;
   }
   Node *tmp = list.head;
   list.head = list.head->next;

   if (list.head)
      list.head->prev = nullptr;
   else
      list.tail = nullptr;

   delete tmp;
   cout << "Первый элемент удалён" << endl;
}