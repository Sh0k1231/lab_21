#include "tree.h"
#include <iostream>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    Tree tree;
    int n, choice;

    //ввод количества элементов
    cout << "введите количество элементов: ";
    cin >> n;

    //выбор способа заполнения
    cout << "выберите метод заполнения:\n"
        <<"1. с консоли\n"
        <<"2. рандом\n"
        <<"3. из файла\n"
        << "ваш выбор: ";
    cin >> choice;

    //обработка выбора
    switch (choice) {
    case 1: tree.fillFromConsole(n); break;
    case 2: tree.fillRandom(n); break;
    case 3: tree.fillFromFile("input.txt", n); break;
    default: cout << "Неверный выбор" << endl; return 1;
    }

    //вывод дерева
    tree.printInorder();
    tree.printSideways();

    //проверка наличия элемента
    int x;
    cout << "Введите значение Х: ";
    cin >> x;
    cout << "Результат: " << (tree.contains(x) ? "true, элемент Х найден в дереве" : "false, элемент Х не найден в дереве") << endl;

    return 0;
}