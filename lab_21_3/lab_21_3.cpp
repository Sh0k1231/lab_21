#include "tree.h"

int main() {
    try {
        setlocale(LC_ALL, "ru");
        Tree tree;
        int n, choice;

        cout << "введите количество элементов: ";
        cin >> n;

        cout << "выберите способ заполнения:\n"
            << "1. с консоли\n"
            << "2. рандом\n"
            << "3. из файла\n"
            << "ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: tree.fillFromConsole(n); break;
        case 2: tree.fillRandom(n); break;
        case 3: tree.fillFromFile("input.txt", n); break;
        default: cout << "неправильный выбор!" << endl; return 1;
        }

        //выводим дерево
        tree.printInorder();
        tree.printSideways();

        //ищем второй максимум
        cout << "второй максимум: " << tree.findSecondMax() << endl;

    }
    catch (const exception& e) {
        cerr << "ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}