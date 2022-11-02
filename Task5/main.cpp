#include "BinaryTree.h"
int main() {

    system("chcp 65001");
    // Добавление элементов и вывод дерева
    vector<bool> arr1{};
    BinaryTree binaryTree1(2);
    try {
        arr1.push_back(false);
        binaryTree1.insert(3, arr1);
        arr1.push_back(false);
        binaryTree1.insert(11, arr1);
        arr1.push_back(false);
        binaryTree1.insert(7, arr1);
        arr1.pop_back();
        arr1.push_back(true);
        arr1.push_back(true);
        arr1.push_back(true);
        arr1.push_back(true);
        binaryTree1.insert(8, arr1);
    } catch (exception &ex) {
        cout << "Ошибка добавления элемента!" << endl;
    }

    cout << "Исходное дерево:" << endl;
    std::cout << binaryTree1;

    cout << "--------------------------" << endl;
    cout << "Удаление листьев:" << endl;
    binaryTree1.deleteLeaves();
    std::cout << binaryTree1;

    cout << "--------------------------" << endl;
    BinaryTree bin(binaryTree1);
    cout << bin << endl;

    cout << "--------------------------" << endl;
    cout << "Очистка дерева:" << endl;
    std::cout << binaryTree1;
    binaryTree1.clear();
    std::cout << binaryTree1;

    cout << "--------------------------" << endl;

    //CountOfEven, allPositives, average
    vector<bool> arr2{};
    BinaryTree binaryTree2(22);

    try {
        arr2.push_back(true);
        binaryTree2.insert(4, arr2);
        arr2.pop_back();
        arr2.push_back(false);
        binaryTree2.insert(18, arr2);
        arr2.push_back(false);
        binaryTree2.insert(5, arr2);
    } catch (exception &ex) {
        cout << "Ошибка добавления элемента!" << endl;
    }

    cout << "Количество четных чисел в дереве: ";
    cout << binaryTree2.countOfEven() << endl; //3
    cout << "Среднее арифметическое всех чисел в дереве: ";
    cout << binaryTree2.average() << endl; //12.25
    cout << "Все ли положительные: ";
    cout << binaryTree2.allPositive() << endl;

    cout << "Добавляем -10" << endl;
    binaryTree2.insert(-10, arr2);
    cout << "Все ли положительные: ";
    cout << binaryTree2.allPositive() << endl;

    cout << "--------------------------" << endl;
    vector<bool> arr4{};
    BinaryTree binaryTree5;

    try {
        binaryTree5.insert(8, arr4);
        arr4.push_back(false);
        binaryTree5.insert(3, arr4);
        arr4.push_back(false);
        binaryTree5.insert(-1, arr4);
        arr4.pop_back();
        arr4.push_back(true);
        binaryTree5.insert(6, arr4);
        arr4.push_back(true);
        binaryTree5.insert(8, arr4);
    } catch (exception &ex) {
        cout << "Ошибка добавления элемента!" << endl;
    }

    cout << binaryTree5 << endl;

    cout << "--------------------------" << endl;
    arr4.clear();

    try {
        arr4.push_back(true);
        binaryTree5.insert(10, arr4);
        arr4.push_back(true);
        binaryTree5.insert(12, arr4);
        arr4.push_back(false);
        binaryTree5.insert(7, arr4);
    } catch (exception &ex) {
        cout << "Ошибка добавления элемента!" << endl;
    }

    cout << binaryTree5 << endl;

    cout << "--------------------------" << endl;
    cout << "Поиск заданного элемента в дереве: ";
    arr4.clear();

    try {
        arr4.push_back(true);
        arr4.push_back(true);
        arr4.push_back(false);
    } catch (exception &ex) {
        cout << "Ошибка добавления элемента!" << endl;
    }

    vector<bool> bArr = binaryTree5.searchElem(7);
    if (arr4 == bArr) {
        cout << true << endl;
    }
}
