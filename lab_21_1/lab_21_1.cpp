
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

    TreeNode* insertNode(TreeNode* node, int value) {
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

    void printTreeSideways(TreeNode* node, int level = 0) const {
        if (node != nullptr) {
            printTreeSideways(node->right, level + 1);
            for (int i = 0; i < level; ++i) {
                cout << "    ";
            }
            cout << node->value << endl;
            printTreeSideways(node->left, level + 1);
        }
    }

    void clearTree(TreeNode* node) {
        if (node != nullptr) {
            clearTree(node->left);
            clearTree(node->right);
            delete node;
        }
    }

public:
    Tree() : root(nullptr) {}
    ~Tree() {
        clearTree(root);
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    void printSideways() const {
        cout << "Дерево (вид боком):" << endl;
        printTreeSideways(root);
    }

    void fillFromConsole(int n) {
        cout << "Введите " << n << " элементов для дерева: ";
        for (int i = 0; i < n; ++i) {
            int value;
            cin >> value;
            insert(value);
        }
    }

    void fillRandom(int n) {
        srand(time(0));
        for (int i = 0; i < n; ++i) {
            insert(rand() % 100);
        }
    }

    void fillFromFile(const string& filename, int n) {
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
};

int main() {
    setlocale(LC_ALL, "ru");
    Tree tree;
    int n;
    int choice;

    cout << "Введите количество элементов: ";
    cin >> n;

    cout << "Выберите метод заполнения дерева:\n"
        << "1. Заполнение с консоли\n"
        << "2. Рандомное заполнение\n"
        << "3. Заполнение из файла\n"
        << "Ваш выбор: ";
    cin >> choice;

    switch (choice) {
    case 1:
        tree.fillFromConsole(n);
        break;
    case 2:
        tree.fillRandom(n);
        break;
    case 3:
        tree.fillFromFile("input.txt", n);
        break;
    default:
        cout << "Неверный выбор" << endl;
        return 1;
    }

    // Выводим дерево боком
    tree.printSideways();

    return 0;
}