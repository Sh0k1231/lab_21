#include "tree.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

//������� ����
TreeNode* Tree::insertNode(TreeNode* node, int value) {
    if (node == nullptr) return new TreeNode(value);
    if (value < node->value) node->left = insertNode(node->left, value);
    else if (value > node->value) node->right = insertNode(node->right, value);
    return node;
}

//����� ��������
bool Tree::containsValue(TreeNode* node, int x) const {
    if (node == nullptr) return false;
    if (x == node->value) return true;
    return (x < node->value) ? containsValue(node->left, x) : containsValue(node->right, x);
}

//����� ������ � ������� �����������
void Tree::inorderPrint(TreeNode* node) const {
    if (node) {
        inorderPrint(node->left);
        cout << node->value << " ";
        inorderPrint(node->right);
    }
}

//����� ������ �����
void Tree::printTreeSideways(TreeNode* node, int level) const {
    if (node) {
        printTreeSideways(node->right, level + 1);
        for (int i = 0; i < level; ++i) cout << "    ";
        cout << node->value << endl;
        printTreeSideways(node->left, level + 1);
    }
}

//������� ������
void Tree::clearTree(TreeNode* node) {
    if (node) {
        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }
}

//����������� � ����������
Tree::Tree() : root(nullptr) {}
Tree::~Tree() { clearTree(root); }

//��������� ������
void Tree::insert(int value) { root = insertNode(root, value); }
bool Tree::contains(int x) const { return containsValue(root, x); }

void Tree::printInorder() const {
    cout << "�������� ������ � ������������ �������: ";
    inorderPrint(root);
    cout << endl;
}

void Tree::printSideways() const {
    cout << "������ (��� �����):" << endl;
    printTreeSideways(root);
}

void Tree::fillFromConsole(int n) {
    cout << "������� " << n << " ���������: ";
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
        cout << "�� ������� ������� ����!" << endl;
        return;
    }
    for (int i = 0; i < n; ++i) {
        int value;
        if (!(file >> value)) {
            cout << "������ ������ �����!" << endl;
            break;
        }
        insert(value);
    }
}