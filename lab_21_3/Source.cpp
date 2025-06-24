#include "tree.h"

//������� ���� � ������
TreeNode* Tree::insertNode(TreeNode* node, int value) {
    if (!node) return new TreeNode(value);
    if (value < node->value)
        node->left = insertNode(node->left, value);
    else if (value > node->value)
        node->right = insertNode(node->right, value);
    return node;
}

//����� ������ � ������� �����������
void Tree::inorderPrint(TreeNode* node) const {
    if (node) {
        inorderPrint(node->left);
        cout << node->value << " ";
        inorderPrint(node->right);
    }
}

//����� ������ ����� � ���������
void Tree::printTreeSideways(TreeNode* node, int level) const {
    if (node) {
        printTreeSideways(node->right, level + 1);
        for (int i = 0; i < level; i++) cout << "    ";
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

//����� ������������� ����
TreeNode* Tree::findMaxNode(TreeNode* node) const {
    while (node->right) node = node->right;
    return node;
}

Tree::Tree() : root(nullptr) {}

Tree::~Tree() {
    clearTree(root);
}

void Tree::insert(int value) {
    root = insertNode(root, value);
}

void Tree::printInorder() const {
    cout << "�������� ������: ";
    inorderPrint(root);
    cout << endl;
}

void Tree::printSideways() const {
    cout << "������ �����:" << endl;
    printTreeSideways(root);
}

void Tree::fillFromConsole(int n) {
    cout << "������� " << n << " ���������: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insert(value);
    }
}

void Tree::fillRandom(int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        insert(rand() % 100);
    }
}

void Tree::fillFromFile(const string& filename, int n) {
    ifstream file(filename);
    if (!file.is_open()) throw runtime_error("�� �������� ����!");
    for (int i = 0; i < n; i++) {
        int value;
        if (!(file >> value)) throw runtime_error("������ ������!");
        insert(value);
    }
}

//����� ������� ������������� ��������
int Tree::findSecondMax() const {
    if (!root || (!root->left && !root->right))
        throw runtime_error("���� ���������!");

    TreeNode* current = root;
    TreeNode* prev = nullptr;

    //���� ������ �������� (����� ������)
    while (current->right) {
        prev = current;
        current = current->right;
    }

    //���� ���� ����� ��������� - ���� ��� ��������
    if (current->left) {
        return findMaxNode(current->left)->value;
    }

    if (!prev) throw runtime_error("��� ������� ���������!");
    return prev->value;
}