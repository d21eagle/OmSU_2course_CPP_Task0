#include "HashTable.h"

template<typename T>
HashTable<T>::HashTable() : table(2)
{
    for (size_t i = 0; i < table.size(); i++)
        table[i] = nullptr;
}

template<typename T>
HashTable<T>::HashTable(const int capacity) : table(capacity)
{
    for (size_t i = 0; i < table.size(); i++)
        table[i] = nullptr;
}

template<typename T>
HashTable<T>::~HashTable()
{
    clearTable();
}

template<typename T>
int HashTable<T>::hash(const std::string& key) const
{
    int hashsum = 0;
    for (int i: key) hashsum += i;
    return hashsum % table.size();
}

//добавить элемент
template<typename T>
void HashTable<T>::addElem(const std::string& key, const T& value)
{
    int index = hash(key);
    auto* item = new Item<T>(key, value);
    if (!table[index])
    {
        table[index] = new std::list<Item<T>*>;
        table[index] -> push_back(item);
    }
    else
    {
        for (Item<T>* i: *table[index])
        {
            if (i -> key == key) return;
        }
        table[index] -> push_back(item);
    }
    suplist.push_back(item);
}

//удалить элемент
template<typename T>
void HashTable<T>::deleteElem(const std::string& key)
{
    int index = hash(key);
    if (!table[index])
        return;

    Item<T>* searched_item = searchElem(key);

    if (!searched_item)
        return;

    typename std::vector<Item<T>*>::iterator it = std::find(suplist.begin(), suplist.end(), searched_item);
    if (it == suplist.end())
        throw std::exception();

    suplist.erase(it);
    table[index] -> remove(searched_item);
}

//найти элемент
template<typename T>
Item<T>* HashTable<T>::searchElem(std::string key) const
{
    int index = hash(key);

    if (!table[index])
        return nullptr;

    auto it = table[index]->begin();

    for(Item<T>* item: *table[index])
    {
        if (item -> key == key)
            return item;
    }
    return nullptr;
}

//сделать таблицу пустой
template<typename T>
void HashTable<T>::clearTable()
{
    for (int i = 0; i < table.size(); i++)
    {
        if (table[i] != nullptr)
        {
            while (!table[i] -> empty())
            {
                Item<T>* it = table[i] -> back();
                delete it;
                table[i] -> pop_back();
            }
        }
    }
    table.clear();
    suplist.clear();
}

//проверка таблицы на пустоту
template<typename T>
bool HashTable<T>::isEmpty() const
{
    return suplist.size() == 0;
}

template<typename T>
HashTable<T>::Iterator::Iterator(const HashTable<T>& hashTable) : hashTable(hashTable) {}

template<typename T>
void HashTable<T>::Iterator::start()
{
    current = hashTable.suplist.begin();
}

template<typename T>
void HashTable<T>::Iterator::next()
{
    current++;
}

template<typename T>
Item<T>* HashTable<T>::Iterator::getValue() const
{
    return *current;
}

template<typename T>
bool HashTable<T>::Iterator::finish() const
{
    return current == hashTable.suplist.end();
}


