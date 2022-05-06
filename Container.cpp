#include "Container.h"
using namespace Containers;

// 10. Конструктор по размерам и максимальному весу
Container::Container(const vector<Box>& array, int length, int width, int height, int maxWeight)
{
    double sum = 0;
    for (auto & i : array)
        sum += i.getWeight();

    if (sum > maxWeight) throw exception();

    this -> array = array;
    this -> length = length;
    this -> width = width;
    this -> height = height;
    this -> maxWeight = maxWeight;
}

// 11.1 Добавление коробки в контейнер
int Container::appendBoxInContainer(Box box)
{
    double sum = 0;
    for (auto & j : array)
        sum += j.getWeight();

    auto iter = array.cbegin();
    if ((sum + box.getWeight()) > maxWeight)
        throw MyException("Too much weight");

    int i = box.nest;
    array.insert(iter + i, box);
    return i;
}

// 11.2 Удаление коробки из контейнера (по индексу)
void Container::deleteBoxInContainer(int i)
{
    auto iter = array.cbegin();
    array.erase(iter + i - 1);
}

// 11.3 Количество коробок в контейнере
unsigned long long int Container::countBoxesInContainer() const { return array.size(); }

// 11.4 Суммарный вес содержимого контейнера
double Container::totalWeightInContainer()
{
    double sum = 0;
    for (auto & i : array)
        sum += i.getWeight();

    return sum;
}

// 11.5 Суммарная стоимость содержимого контейнера
int Container::totalValueInContainer()
{
    int sum = 0;
    for (auto & i : array)
        sum += i.getValue();

    return sum;
}

// 11.6 Получение коробки по индексу
const Box& Container::returnBoxByIndex(int i)
{
    return array[i];
}

// 12. Операторы ввода/вывода
istream& Containers::operator >> (istream& in, Container& container)
{
    in >> container.height;
    in >> container.width;
    in >> container.length;
    in >> container.maxWeight;
    for (auto & i : container.array)
        in >> i;

    return in;
}

ostream& Containers::operator << (ostream& out, Container& container)
{
    out << "Container(" << container.length << ", " << container.width << ", " << container.height << ", " << container.maxWeight << "):\n";
    for (auto & i : container.array)
        out << i << "\n";

    return out;
}

//13. Оператор [] позволяет получить/изменить коробку по индексу
Box& Container::operator[] (const int index) { return array[index]; }




