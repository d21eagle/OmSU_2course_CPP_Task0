#include "RingBuffer.h"
#include <iostream>
using namespace std;

template <typename T>
RingBuffer<T>::RingBuffer()
{
    size = 0;
    array1 = new T[10];
    first = 0;
    last = 0;
}

template <typename T>
RingBuffer<T>::RingBuffer(size_t size1) //: size(size1 + 1), array1(new T[size1+1]), first(0), last(0)
{
    size = size1 + 1;
    array1 = new T[size1 + 1];
    first = 0;
    last = 0;
}

template <typename T>
RingBuffer<T>::RingBuffer(const RingBuffer& copy) : size(copy.size), first(copy.first), last(copy.last), array1(new T[copy.size])
{}

// Добавить элемент в конец очереди (при переполнении – исключение)
template <typename T>
void RingBuffer<T>::addElemInEnd(T elem)
{
    if (last == size) size++;
    if ((last + 1) % (this -> size) == first)
        throw MyException("Overflow");
    array1[last] = elem;

    last = (last + 1) % size;
}

// Взять элемент в начале очереди (при отсутствии – исключение)
template <typename T>
double RingBuffer<T>::getElemInStart()
{
    if (isEmpty()) throw MyException("Empty");

    double temp = array1[first];
    first = (first + 1) % size;
    size--;
    return temp;
}

// Получить элемент в начале очереди (без его изъятия)
template <typename T>
double RingBuffer<T>::checkElemInStart()
{
    if (isEmpty()) throw MyException("Empty");
    return array1[first];
}

// Размер очереди
template <typename T>
size_t RingBuffer<T>::getSizeBuffer() const
{
    return size - 1;
}

// Проверка очереди на пустоту
template <typename T>
bool RingBuffer<T>::isEmpty() const
{
    return first == last;
}

// Сделать очередь пустой
template <typename T>
void RingBuffer<T>::clearBuffer()
{
    first = 0;
    last = 0;

    std::cout << "Очередь была очищена!" << std::endl;
}


template <typename T>
RingBuffer<T>::~RingBuffer()
{
    clearBuffer();
    if (array1 != nullptr)
    {
        delete[] array1;
        array1 = nullptr;
    }
    size = 0;
}
