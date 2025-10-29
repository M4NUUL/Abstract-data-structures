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

// Удаление последнего элемента
void DelTail(DList &list)
{
   if (!list.tail)
   {
      cout << "Список пуст" << endl;
      return;
   }
   Node *tmp = list.head;
   list.tail = list.tail->prev;

   if (list.tail)
      list.tail->next = nullptr;
   else
      list.head = nullptr;

   delete tmp;
   cout << "Последний элемент удалён";
}

// Удалить определенный элемент
void DelVal(DList &list, const string &val)
{
   if (!list.head)
   {
      cout << "Список пуст." << endl;
      return;
   }
   Node *curr = list.head;
   while (curr && curr->data != val)
   {
      curr = curr->next;
   }

   if (!curr)
   {
      cout << "Элемент " << val << " не найден." << endl;
      return;
   }

   if (curr->prev)
      curr->prev->next = curr->next;
   else
      list.head = curr->next;

   if (curr->next)
      curr->next->prev = curr->prev;
   else
      list.tail = curr->prev;

   delete curr;
   cout << "Элемент \"" << val << "\" удален." << endl;
}

// Поиск по значению
Node *findVal(const DList &list, const string &val)
{
   for (Node *curr = list.head; curr; curr = curr->next)
   {
      if (curr->data == val)
      {
         return curr;
      }
   }
   return nullptr;
}

// Вывод списка с начала
void PrintForward(const DList &list)
{
   if (!list.head)
   {
      cout << "Список пуст" << endl;
      return;
   }

   cout << "Список вперед: ";
   for (Node *curr = list.head; curr; curr = curr->next)
      cout << curr->data << " ";
   cout << endl;
}

// Вывод с конца
void PrintBackward(const DList &list)
{
   if (!list.tail)
   {
      cout << "Список пуст" << endl;
      return;
   }

   cout << "Список назад: ";
   for (Node *curr = list.tail; curr; curr = curr->prev)
   {
      cout << curr->data << " ";
   }
   cout << endl;
}

// Отчистка списка
void ClearList(DList &list)
{
   while (list.head)
   {
      Node *tmp = list.head;
      list.head = list.head->next;
      delete tmp;
   }
   list.tail = nullptr;
}

// Удаление после элемента
void DelAfterVal(DList &list, const string &val)
{
   Node *targetNode = findVal(list, val);
   if (!targetNode || !targetNode->next)
   {
      cout << "Элемент '" << val << "' не найден или он последний." << endl;
      return;
   }
   Node *nodeToDelete = targetNode->next;
   // Если удаляемый узел - хвост, обновляем хвост
   if (nodeToDelete == list.tail)
   {
      DelTail(list);
   }
   else
   {
      targetNode->next = nodeToDelete->next;
      nodeToDelete->next->prev = targetNode;
      delete nodeToDelete;
   }
   cout << "Элемент после '" << val << "' удален." << endl;
}

// Удаление до элемента
void DelBeforeVal(DList &list, const string &val)
{
   Node *targetNode = findVal(list, val);
   if (!targetNode || !targetNode->prev)
   {
      cout << "Элемент '" << val << "' не найден или он первый." << endl;
      return;
   }
   Node *nodeToDelete = targetNode->prev;
   // Если удаляемый узел - голова, обновляем голову
   if (nodeToDelete == list.head)
   {
      DelHead(list);
   }
   else
   {
      targetNode->prev = nodeToDelete->prev;
      nodeToDelete->prev->next = targetNode;
      delete nodeToDelete;
   }
   cout << "Элемент перед '" << val << "' удален." << endl;
}