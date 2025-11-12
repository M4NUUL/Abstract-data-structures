#include "red_black_tree.h"
#include <fstream>

// Инициализация красно-черного дерева
void initRBTree(RBTree& tree) {
    tree.nil = new RBNode("");
    tree.nil->color = BLACK;
    tree.root = tree.nil;
}

// Рекурсивная очистка дерева
void clearHelper(RBNode* node, RBNode* nil) {
    if (node != nil) {
        clearHelper(node->left, nil);
        clearHelper(node->right, nil);
        delete node;
    }
}

// Очистка всего дерева
void clearRBTree(RBTree& tree) {
    clearHelper(tree.root, tree.nil);
    tree.root = tree.nil;
}

// Левый поворот вокруг узла x
void leftRotate(RBTree& tree, RBNode* x) {
    RBNode* y = x->right;
    x->right = y->left;
    
    if (y->left != tree.nil) {
        y->left->parent = x;
    }
    
    y->parent = x->parent;
    
    if (x->parent == tree.nil) {
        tree.root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    
    y->left = x;
    x->parent = y;
}

// Правый поворот вокруг узла y
void rightRotate(RBTree& tree, RBNode* y) {
    RBNode* x = y->left;
    y->left = x->right;
    
    if (x->right != tree.nil) {
        x->right->parent = y;
    }
    
    x->parent = y->parent;
    
    if (y->parent == tree.nil) {
        tree.root = x;
    } else if (y == y->parent->right) {
        y->parent->right = x;
    } else {
        y->parent->left = x;
    }
    
    x->right = y;
    y->parent = x;
}

// Восстановление свойств красно-черного дерева после вставки
void insertFixup(RBTree& tree, RBNode* z) {
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            RBNode* y = z->parent->parent->right;
            
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(tree, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(tree, z->parent->parent);
            }
        } else {
            RBNode* y = z->parent->parent->left;
            
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(tree, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(tree, z->parent->parent);
            }
        }
    }
    tree.root->color = BLACK;
}

// Вставка элемента в дерево
void insert(RBTree& tree, string data) {
    RBNode* z = new RBNode(data);
    RBNode* y = tree.nil;
    RBNode* x = tree.root;
    
    while (x != tree.nil) {
        y = x;
        if (z->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    
    z->parent = y;
    
    if (y == tree.nil) {
        tree.root = z;
    } else if (z->data < y->data) {
        y->left = z;
    } else {
        y->right = z;
    }
    
    z->left = tree.nil;
    z->right = tree.nil;
    z->color = RED;
    
    insertFixup(tree, z);
}

// Поиск элемента в дереве
bool search(const RBTree& tree, string data) {
    RBNode* current = tree.root;
    
    while (current != tree.nil) {
        if (data == current->data) {
            return true;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    return false;
}

// Поиск минимального элемента в поддереве
RBNode* minimum(const RBTree& tree, RBNode* node) {
    while (node->left != tree.nil) {
        node = node->left;
    }
    return node;
}

// Замена поддерева
void transplant(RBTree& tree, RBNode* u, RBNode* v) {
    if (u->parent == tree.nil) {
        tree.root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

// Восстановление свойств красно-черного дерева после удаления
void deleteFixup(RBTree& tree, RBNode* x) {
    while (x != tree.root && x->color == BLACK) {
        if (x == x->parent->left) {
            RBNode* w = x->parent->right;
            
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(tree, x->parent);
                w = x->parent->right;
            }
            
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(tree, w);
                    w = x->parent->right;
                }
                
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(tree, x->parent);
                x = tree.root;
            }
        } else {
            RBNode* w = x->parent->left;
            
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(tree, x->parent);
                w = x->parent->left;
            }
            
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(tree, w);
                    w = x->parent->left;
                }
                
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(tree, x->parent);
                x = tree.root;
            }
        }
    }
    x->color = BLACK;
}

// Удаление элемента из дерева
void remove(RBTree& tree, string data) {
    RBNode* z = tree.root;
    RBNode* x, *y;
    
    // Поиск узла для удаления
    while (z != tree.nil) {
        if (data == z->data) {
            break;
        } else if (data < z->data) {
            z = z->left;
        } else {
            z = z->right;
        }
    }
    
    if (z == tree.nil) {
        cout << "Элемент не найден!" << endl;
        return;
    }
    
    y = z;
    Color y_original_color = y->color;
    
    if (z->left == tree.nil) {
        x = z->right;
        transplant(tree, z, z->right);
    } else if (z->right == tree.nil) {
        x = z->left;
        transplant(tree, z, z->left);
    } else {
        y = minimum(tree, z->right);
        y_original_color = y->color;
        x = y->right;
        
        if (y->parent == z) {
            x->parent = y;
        } else {
            transplant(tree, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        
        transplant(tree, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    
    if (y_original_color == BLACK) {
        deleteFixup(tree, x);
    }
    
    delete z;
    cout << "Элемент '" << data << "' удален!" << endl;
}

// Рекурсивный вывод дерева
void printHelper(RBNode* root, RBNode* nil, string indent, bool last) {
    if (root != nil) {
        cout << indent;
        if (last) {
            cout << "└──";
            indent += "    ";
        } else {
            cout << "├──";
            indent += "│   ";
        }
        
        string sColor = (root->color == RED) ? "RED" : "BLACK";
        cout << root->data << " (" << sColor << ")" << endl;
        
        printHelper(root->left, nil, indent, false);
        printHelper(root->right, nil, indent, true);
    }
}

// Вывод всего дерева
void printTree(const RBTree& tree) {
    if (tree.root == tree.nil) {
        cout << "Дерево пусто!" << endl;
        return;
    }
    printHelper(tree.root, tree.nil, "", true);
}

// Рекурсивное сохранение дерева в файл
void saveToFileHelper(RBNode* node, RBNode* nil, ofstream& file) {
    if (node != nil) {
        file << node->data << endl;
        saveToFileHelper(node->left, nil, file);
        saveToFileHelper(node->right, nil, file);
    }
}

// Сохранение дерева в файл
void saveToFile(const RBTree& tree, string filename) {
    ofstream file(filename);
    if (file.is_open()) {
        saveToFileHelper(tree.root, tree.nil, file);
        file.close();
        cout << "Дерево сохранено в " << filename << endl;
    } else {
        cout << "Ошибка сохранения файла!" << endl;
    }
}

// Загрузка дерева из файла
void loadFromFile(RBTree& tree, string filename) {
    ifstream file(filename);
    if (file.is_open()) {
        clearRBTree(tree);
        string data;
        while (getline(file, data)) {
            if (!data.empty()) {
                insert(tree, data);
            }
        }
        file.close();
        cout << "Дерево загружено из " << filename << endl;
    } else {
        cout << "Файл " << filename << " не найден!" << endl;
    }
}