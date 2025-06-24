#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

// Узел дерева
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class Tree {
private:
    TreeNode* root;

    // Вспомогательная функция для рекурсивного добавления узла
    TreeNode* insertNode(TreeNode* node, int value);

    // Вспомогательная функция для рекурсивного вывода дерева (инфиксный обход)
    void inorderPrint(TreeNode* node) const;

    // Вспомогательная функция для рекурсивного вывода дерева "боком"
    void printTreeSideways(TreeNode* node, int level = 0) const;

    // Вспомогательная функция для рекурсивного удаления дерева
    void clearTree(TreeNode* node);

public:
    Tree();
    ~Tree();

    // Добавление элемента в дерево
    void insert(int value);

    // Вывод дерева в возрастающем порядке
    void printInorder() const;

    // Вывод дерева "боком"
    void printSideways() const;

    // Заполнение дерева с консоли
    void fillFromConsole(int n);

    // Заполнение дерева случайными значениями
    void fillRandom(int n);

    // Заполнение дерева из файла
    void fillFromFile(const string& filename, int n);
};

#endif 