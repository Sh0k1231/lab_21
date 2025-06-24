#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>

//структура узла дерева
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

//класс бинарного дерева поиска
class Tree {
private:
    TreeNode* root;

    //вспомогательные рекурсивные методы
    TreeNode* insertNode(TreeNode* node, int value);
    bool containsValue(TreeNode* node, int x) const;
    void inorderPrint(TreeNode* node) const;
    void printTreeSideways(TreeNode* node, int level = 0) const;
    void clearTree(TreeNode* node);

public:
    Tree();
    ~Tree();

    //основные публичные методы
    void insert(int value);
    bool contains(int x) const;
    void printInorder() const;
    void printSideways() const;
    void fillFromConsole(int n);
    void fillRandom(int n);
    void fillFromFile(const std::string& filename, int n);
};

#endif 