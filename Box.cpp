#include "Box.h"
using namespace Boxes;

// 1. Конструктор по значениям полей
Box::Box(int length, int width, int height, double weight, int value, int nest)
{
    this -> length = length;
    this -> width = width;
    this -> height = height;
    this -> weight = weight;
    this -> value = value;
    this -> nest = nest;
}

int Box::getLength() const { return length; }

int Box::getWidth() const { return width; }

int Box::getHeight() const { return height; }

double Box::getWeight() const { return weight; }

int Box::getValue() const { return value; }

void Box::setLength(int len) { this -> length = len; }

void Box::setWidth(int wid) { this -> width = wid; }

void Box::setHeight(int hei) { this -> height = hei; }

void Box::setWeight(double wei) { this -> weight = wei; }

void Box::setValue(int val) { this -> value = val; }

// 2. Функция вычисляет суммарную стоимость содержимого всех коробок
int Box::totalValue(Box boxes[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += boxes[i].value;
    return sum;
}

// 3. Функция проверяет, что сумма длины, ширины и высоты всех коробок не превосходит заданного значения
bool Box::notExceedValue(Box boxes[], int size, int res)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += boxes[i].length;
        sum += boxes[i].width;
        sum += boxes[i].height;
    }
    if (res >= sum) return true;
    else return false;
}

// 4. Функция определяет максимальный вес коробок, объем которых не больше параметра maxV
double Box::maxWeight(Box boxes[], int size, int maxV)
{
    double maxWeight = 0;
    for (int j = 0; j < size; j++)
    {
        if ((boxes[j].getHeight() * boxes[j].getLength() * boxes[j].getWidth() <= maxV)
            && (maxWeight <= boxes[j].getWeight()))
            maxWeight = boxes[j].weight;
    }
    return maxWeight;
}

// 5. Функция проверяет, что все коробки массива можно вложить друг в друга по одной штуке
bool Box::boxInBox(Box boxes[], int size)
{
    int packed = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if ((boxes[i].getHeight() < boxes[j].getHeight()
                 && boxes[i].getWidth() < boxes[j].getWidth()
                 && boxes[i].getLength() < boxes[j].getLength()))
                packed++;
        }
    }
    if (size != packed) return false;
    return true;
}

// 6. Оператор == сравнения двух коробок на равенство всех параметров
bool Boxes::operator == (const Box& box1, const Box& box2)
{
    return ((box1.getLength() == box2.getLength())
        && (box1.getWidth() == box2.getWidth())
        && (box1.getHeight() == box2.getHeight())
        && (box1.getWeight() == box2.getWeight())
        && (box1.getValue() == box2.getValue()));
}

// 7. Операторы ввода/вывода (>> и <<) для коробок в произвольные потоки
istream& Boxes::operator >> (istream& in, Box& box)
{
    in >> box.length;
    in >> box.width;
    in >> box.height;
    in >> box.weight;
    in >> box.value;
    return in;
}

ostream& Boxes::operator << (ostream& out, Box& box)
{
    out << "Box(" << box.getLength() << ", " << box.getWidth() << ", "
        << box.getHeight() << ", " << box.getWeight() << ", " << box.getValue() << ")";
    return out;
}





