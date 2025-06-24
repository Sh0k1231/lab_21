#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

// ���� ������
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class Tree {
private:
    TreeNode* root;

    // ��������������� ������� ��� ������������ ���������� ����
    TreeNode* insertNode(TreeNode* node, int value);

    // ��������������� ������� ��� ������������ ������ ������ (��������� �����)
    void inorderPrint(TreeNode* node) const;

    // ��������������� ������� ��� ������������ ������ ������ "�����"
    void printTreeSideways(TreeNode* node, int level = 0) const;

    // ��������������� ������� ��� ������������ �������� ������
    void clearTree(TreeNode* node);

public:
    Tree();
    ~Tree();

    // ���������� �������� � ������
    void insert(int value);

    // ����� ������ � ������������ �������
    void printInorder() const;

    // ����� ������ "�����"
    void printSideways() const;

    // ���������� ������ � �������
    void fillFromConsole(int n);

    // ���������� ������ ���������� ����������
    void fillRandom(int n);

    // ���������� ������ �� �����
    void fillFromFile(const string& filename, int n);
};

#endif 