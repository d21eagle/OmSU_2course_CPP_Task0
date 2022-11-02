#include "HashTable.h"

int main() {

    system("chcp 65001");

    HashTable<int> table;
    table.addElem("mmm", 1);
    table.addElem("mmb", 2);
    table.addElem("mmc", 3);
    table.addElem("mmd", 4);
    table.addElem("mme", 5);
    table.addElem("mmf", 6);
    table.addElem("mmg", 7);
    table.addElem("mmh", 8);
    table.addElem("mmi", 9);

    HashTable<int>::Iterator it(table);
    it.start();
    while (!it.finish()) {
        std::cout << it.getValue() -> value << " ";
        it.next();
    }
    std::cout << std::endl;

    std::cout << table.searchElem("mmm") -> value << std::endl;

    Item<int> *item = table.searchElem("mme");
    std::cout << item -> value << std::endl;

    table.deleteElem("mme");
    std::cout << table.searchElem("mme") << std::endl;

    HashTable<int>::Iterator it1(table);
    it1.start();
    while (!it1.finish()) {
        std::cout << it1.getValue() -> value << " ";
        it1.next();
    }

    table.clearTable();
    it1.start();
    while (!it1.finish()) {
        std::cout << it1.getValue() -> value << " ";
        it1.next();
    }
}