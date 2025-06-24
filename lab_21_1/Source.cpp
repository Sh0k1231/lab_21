#include "tree.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

//вставка узла
TreeNode* Tree::insertNode(TreeNode* node, int value) {
    if (node == nullptr) return new TreeNode(value);
    if (value < node->value) node->left = insertNode(node->left, value);
    else if (value > node->value) node->right = insertNode(node->right, value);
    return node;
}

//поиск значения
bool Tree::containsValue(TreeNode* node, int x) const {
    if (node == nullptr) return false;
    if (x == node->value) return true;
    return (x < node->value) ? containsValue(node->left, x) : containsValue(node->right, x);
}

//вывод дерева в порядке возрастания
void Tree::inorderPrint(TreeNode* node) const {
    if (node) {
        inorderPrint(node->left);
        cout << node->value << " ";
        inorderPrint(node->right);
    }
}

//вывод дерева боком
void Tree::printTreeSideways(TreeNode* node, int level) const {
    if (node) {
        printTreeSideways(node->right, level + 1);
        for (int i = 0; i < level; ++i) cout << "    ";
        cout << node->value << endl;
        printTreeSideways(node->left, level + 1);
    }
}

//очистка дерева
void Tree::clearTree(TreeNode* node) {
    if (node) {
        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }
}

//конструктор и деструктор
Tree::Tree() : root(nullptr) {}
Tree::~Tree() { clearTree(root); }

//публичные методы
void Tree::insert(int value) { root = insertNode(root, value); }
bool Tree::contains(int x) const { return containsValue(root, x); }

void Tree::printInorder() const {
    cout << "элементы дерева в возрастающем порядке: ";
    inorderPrint(root);
    cout << endl;
}

void Tree::printSideways() const {
    cout << "дерево (вид боком):" << endl;
    printTreeSideways(root);
}

void Tree::fillFromConsole(int n) {
    cout << "введите " << n << " элементов: ";
    for (int i = 0; i < n; ++i) {
        int value; cin >> value;
        insert(value);
    }
}

void Tree::fillRandom(int n) {
    srand(time(0));
    for (int i = 0; i < n; ++i) insert(rand() % 100);
}

void Tree::fillFromFile(const string& filename, int n) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "не удалось открыть файл!" << endl;
        return;
    }
    for (int i = 0; i < n; ++i) {
        int value;
        if (!(file >> value)) {
            cout << "ошибка чтения файла!" << endl;
            break;
        }
        insert(value);
    }
}