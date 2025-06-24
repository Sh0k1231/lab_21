#include "tree.h"

//вставка узла в дерево 
TreeNode* Tree::insertNode(TreeNode* node, int value) {
    if (node == nullptr) {
        return new TreeNode(value);
    }
    if (value < node->value) {
        node->left = insertNode(node->left, value);
    }
    else if (value > node->value) {
        node->right = insertNode(node->right, value);
    }
    return node;
}

//инфиксный обход дерева 
void Tree::inorderPrint(TreeNode* node) const {
    if (node != nullptr) {
        inorderPrint(node->left);
        cout << node->value << " ";
        inorderPrint(node->right);
    }
}

//вывод дерева в виде иерархии 
void Tree::printTreeSideways(TreeNode* node, int level) const {
    if (node != nullptr) {
        printTreeSideways(node->right, level + 1);
        for (int i = 0; i < level; ++i) {
            cout << "    ";
        }
        cout << node->value << endl;
        printTreeSideways(node->left, level + 1);
    }
}

//очистка памяти
void Tree::clearTree(TreeNode* node) {
    if (node != nullptr) {
        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }
}

//конструктор 
Tree::Tree() : root(nullptr) {}

//деструктор 
Tree::~Tree() {
    clearTree(root);
}

//публичный метод для вставки значения
void Tree::insert(int value) {
    root = insertNode(root, value);
}

//вывод элементов в отсортированном порядке
void Tree::printInorder() const {
    cout << "Элементы дерева в возрастающем порядке: ";
    inorderPrint(root);
    cout << endl;
}

//вывод дерева в иерархическом виде
void Tree::printSideways() const {
    cout << "Дерево (вид боком):" << endl;
    printTreeSideways(root);
}

//заполнение дерева с клавиатуры
void Tree::fillFromConsole(int n) {
    cout << "Введите " << n << " элементов для дерева: ";
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        insert(value);
    }
}

//заполнение дерева случайными значениями
void Tree::fillRandom(int n) {
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        insert(rand() % 100);
    }
}

//загрузка данных из файла
void Tree::fillFromFile(const string& filename, int n) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл!" << endl;
        return;
    }
    for (int i = 0; i < n; ++i) {
        int value;
        if (!(file >> value)) {
            cout << "Ошибка чтения файла!" << endl;
            break;
        }
        insert(value);
    }
}