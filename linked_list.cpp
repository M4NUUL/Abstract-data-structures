#include "linked_list.h"

#include <iostream>

using namespace std;

// Создание (инициализация) списка
void CreateList(List& list) { list.head = nullptr; }

// Отчиска списка
void ClearList(List& list) {
  Node* cur = list.head;
  while (cur != nullptr) {
    Node* tmp = cur;
    cur = cur->next;
    delete tmp;
  }
  list.head = nullptr;
}

// Добавление в начало списка
void AddToHead(List& list, string val) {
  Node* node = new Node{val, list.head};
  list.head = node;
}

// Добавление в конец
void AddToEnd(List& list, const string& val) {
  Node* node = new Node{val, nullptr};
  if (!list.head) {
    list.head = node;
    return;
  }

  Node* cur = list.head;  // Указатель на узел
  while (cur->next) {
    cur = cur->next;
    cur->next = node;
  }
}

// Добавление перед элементом
void AddBefore(List& list) {
  if (!list.head) {
    cout << "Список пуст!" << endl;
    return;
  }

  string target, val;
  cout << "Введите значение, перед которым добавить: ";
  cin >> target;
  cout << "Введите новое значение: ";
  cin >> val;

  if (list.head->value == target) {
    AddToHead(list, val);
    return;
  }

  Node* cur = list.head;
  while (cur->next && cur->next->value != target) {
    cur = cur->next;
  }

  if (!cur->next) {
    cout << "Элемент не найден" << endl;
    return;
  }

  Node* node = new Node{val, cur->next};
  cur->next = node;
}

// Добавление после элемента
void AddAfter(List& list) {
  if (!list.head) {
    cout << "Список пуст" << endl;
    return;
  }
  string target, val;
  cout << "Введите значение, после которого добавить: ";
  cin >> target;
  cout << "Введите новое значение: ";
  cin >> val;

  Node* cur = list.head;
  while (cur && cur->value != target) {
    cur = cur->next;
  }
  if (!cur) {
    cout << "Элемент не найден" << endl;
    return;
  }

  Node* node = new Node{val, cur->next};
  cur->next = node;
}

// Удаление хвоста
void DelTail(List& list) {
  if (!list.head) {
    cout << "Список пуст" << endl;
    return;
  }
  if (!list.head->next) {
    delete list.head;
    list.head = nullptr;
    return;
  }

  Node* cur = list.head;
  while (cur->next->next) cur = cur->next;

  delete cur->next;
  cur->next = nullptr;
}

// Удаление элемента
void DelVal(List& list, const string& val) {
  if (!list.head) {
    cout << "Список пуст." << endl;
    return;
  }
  if (list.head->value == val) {
    DelHead(list);
    cout << "Элемент " << val << " удален." << endl;
    return;
  }
  Node* cur = list.head;
  while (cur->next && cur->next->value != val) {
    cur = cur->next;
  }
  if (!cur->next) {
    cout << "Элемент " << val << " не найден." << endl;
    return;
  }
  Node* tmp = cur->next;
  cur->next = tmp->next;
  delete tmp;
  cout << "Элемент " << val << " удален." << endl;
}

// Поиск элемента
void FindVal(const List& list, const string val) {
  Node* curr = list.head;
  int p = 0;
  while (curr) {
    if (curr->value == val) {
      cout << "Элемент \"" << val << "\" найден на позиции: " << p << endl;
      return;
    }
    curr = curr->next;
    p++;
  }
  cout << "Элемент \"" << val << "\" не найден." << endl;
}

// Вывод списка вперед
void PrintForward(const List& list) {
  if (!list.head) {
    cout << "Список пуст" << endl;
    return;
  }
  cout << "Список вперёд";
  for (Node* curr = list.head; curr; curr = curr->next) {
    cout << curr->value << " ";
  }
  cout << endl;
}

void printBack(Node* node) {
  if (!node) return;
  printBack(node->next);
  cout << node->value << " ";
}

// Вывод списка назад
void PrintBack(const List& list) {
  if (!list.head) {
    cout << "Список пуст" << endl;
    return;
  }
  cout << "Список назад: ";
  printBack(list.head);
  cout << endl;
}

// Удалениеначала списка
void DelHead(List& list) {
  if (!list.head) {
    cout << "Список пуст" << endl;
    return;
  }
  Node* tmp = list.head;
  list.head = list.head->next;
  delete tmp;
}

// Удаление после элемента
void DelAfterVal(List& list, const string& val) {
  if (!list.head || !list.head->next) {
    cout << "Нечего удалять после элемента или список пуст." << endl;
    return;
  }
  Node* cur = list.head;
  while (cur && cur->value != val) {
    cur = cur->next;
  }
  if (!cur || !cur->next) {
    cout << "Элемент '" << val << "' не найден или он последний." << endl;
    return;
  }
  Node* tmp = cur->next;
  cur->next = tmp->next;
  delete tmp;
  cout << "Элемент после '" << val << "' удален." << endl;
}

// Удаление перед элементом
void DelBeforeVal(List& list, const string& val) {
  if (!list.head || !list.head->next) {
    cout << "Нечего удалять перед элементом или список пуст." << endl;
    return;
  }
  if (list.head->next->value == val) {
    DelHead(list);
    cout << "Элемент перед '" << val << "' удален." << endl;
    return;
  }
  Node* cur = list.head;
  while (cur->next && cur->next->next && cur->next->next->value != val) {
    cur = cur->next;
  }
  if (!cur->next || !cur->next->next) {
    cout << "Элемент '" << val << "' не найден или перед ним нечего удалять."
         << endl;
    return;
  }
  Node* tmp = cur->next;
  cur->next = tmp->next;
  delete tmp;
  cout << "Элемент перед '" << val << "' удален." << endl;
}
