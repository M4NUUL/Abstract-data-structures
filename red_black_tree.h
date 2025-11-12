#ifndef RB_TREE_H
#define RB_TREE_H

#include <iostream>
#include <string>

using namespace std;

// Цвет узла: красный или черный
enum Color { RED, BLACK };

// Структура узла красно-черного дерева
struct RBNode {
    string data;
    Color color;
    RBNode* left;
    RBNode* right;
    RBNode* parent;

    RBNode(string val) : data(val), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

// Структура красно-черного дерева
struct RBTree {
    RBNode* root;
    RBNode* nil; // Страж-узел
};

// Инициализация дерева
void initRBTree(RBTree& tree);

// Очистка дерева
void clearRBTree(RBTree& tree);

// Основные операции
void insert(RBTree& tree, string data);
bool search(const RBTree& tree, string data);
void remove(RBTree& tree, string data);
void printTree(const RBTree& tree);

// Вспомогательные функции
void leftRotate(RBTree& tree, RBNode* x);
void rightRotate(RBTree& tree, RBNode* y);
void insertFixup(RBTree& tree, RBNode* z);
void deleteFixup(RBTree& tree, RBNode* x);
void transplant(RBTree& tree, RBNode* u, RBNode* v);
RBNode* minimum(const RBTree& tree, RBNode* node);

// Работа с файлами
void saveToFile(const RBTree& tree, string filename);
void loadFromFile(RBTree& tree, string filename);

#endif