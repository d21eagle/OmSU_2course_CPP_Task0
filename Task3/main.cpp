#include "List.h"
using namespace std;

int main()
{
    system("chcp 65001");

    List list1;
    AIterator* it = new List::Iterator(list1);
    it -> start();
    list1.addElem(it, 2);
    list1.addElem(it, 4);
    it -> start();
    it -> next();
    cout << it -> get() -> data << endl;
    it -> next();
    cout << it -> get() -> data << endl;

    cout << "\nПроверка на пустоту: " << list1.isEmpty();
    cout << "\nДелаем список пустым!";
    list1.makeEmpty();
    cout << "\nПроверка на пустоту: " << list1.isEmpty() << endl;

    cout << "\nДобавляем элементы!" << endl;
    it -> start();
    list1.addElem(it, 5);
    it -> next();
    list1.addElem(it, 9);
    it -> next();
    list1.addElem(it, 6);

    cout << "Поиск первого вхождения:" << endl;
    cout << list1.searchFirstEntry(11) -> get() -> data << endl;

    cout << "Итератор на первый элемент списка:" << endl;
    cout << list1.getFirstI() -> get() -> data << endl;

    it -> start();
    it -> next();
    list1.deleteElem(it);

    cout << "Итератор на первый элемент списка:" << endl;
    cout << list1.getFirstI() -> get() -> data << endl;

    cout << "\nСписок1" << endl;
    it = new List::Iterator(list1);
    it -> start();
    while(!it -> finish())
    {
        it -> next();
        cout << it -> get() -> data << endl;
    }

    List list2 = list1;
    AIterator* i = new List::Iterator(list2);
    i -> start();
    cout << "Список2" << endl;
    while (!i -> finish())
    {
        i -> next();
        cout << i -> get() -> data << endl;
    }
}
