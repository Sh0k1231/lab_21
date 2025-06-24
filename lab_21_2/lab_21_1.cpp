#include "tree.h"

int main() {
    setlocale(LC_ALL, "ru");
    Tree tree;
    int n;
    int choice;

    cout << "Введите количество элементов: ";
    cin >> n;

    cout << "Выберите метод заполнения дерева:\n"
        << "1. с консоли\n"
        << "2. рандомно\n"
        << "3. из файла\n"
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

    // Выводим дерево в возрастающем порядке
    tree.printInorder();

    // Выводим дерево в "понятном" виде (боком)
    tree.printSideways();

    return 0;
}