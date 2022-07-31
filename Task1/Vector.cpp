#include "Vector.h"
#include <iostream>

Vector::Vector() = default;

Vector::Vector(size_t n) : size(n), cap(n), arr(new int[n])
{
    for (size_t i = 0; i < cap; ++i)
        arr[i] = 0;
}

Vector::Vector(size_t n, int x) : Vector(n)
{
    for (size_t i = 0; i < cap; ++i)
        arr[i] = x;
}

Vector::Vector(const Vector& v): Vector(v.cap)
{
    size = v.size;
    for (size_t i = 0; i < size; ++i)
        arr[i] = v.arr[i];
}

Vector::Vector(std::initializer_list<int> list): size(list.size()), cap(size), arr(new int[cap])
{
    std::copy(list.begin(), list.end(), arr);
}

Vector::Vector(Vector&& v) noexcept: size(v.size), cap(v.cap), arr(v.arr)
{
    v.arr = nullptr;
}

Vector::~Vector()
{
    delete[] arr;
    arr = nullptr;
}

void Vector::reserve(size_t n)
{
    cap = n;
    int* newArr = new int[n];
    for (size_t i = 0; i < size; ++i)
        newArr[i] = arr[i];

    delete[] arr;
    arr = newArr;
}

void Vector::resize(int n)
{
    size = n;
    cap = n;
    int* newArr = new int[n];
    for (size_t i = 0; i < n; ++i)
        newArr[i] = arr[i];

    delete[] arr;
    arr = newArr;
}

void Vector::push_back(int x)
{
    if (size == cap) reserve(2 * cap);
    arr[size] = x;
    ++size;
}

void Vector::pop_back()
{
    if (size == 0) return;
    --size;
}

Vector& Vector::operator=(const Vector& v)
{
    size = v.size;
    cap = v.cap;
    delete[] arr;
    arr = new int[cap];
    for (size_t i = 0; i < size; ++i)
        arr[i] = v.arr[i];

    return *this;
}

Vector& Vector::operator+=(const Vector& v)
{
    cap += v.cap;
    int* newArr = new int[cap];
    for (size_t i = 0; i < size; ++i)
        newArr[i] = arr[i];

    for (size_t i = size; i < size + v.size; ++i)
        newArr[i] = v.arr[i - size];

    size += v.size;
    return *this;
}

Vector Vector::operator+(const Vector& v)
{
    Vector copy = *this;
    copy += v;
    return copy;
}

bool Vector::operator==(const Vector& v) const
{
    if (size != v.size || cap != v.cap) return false;
    for (size_t i = 0; i < size; ++i)
        if (arr[i] != v.arr[i]) return false;

    return true;
}

bool Vector::operator!=(const Vector& v) const
{
    return !(*this == v);
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
    for (size_t i = 0; i < v.size; ++i)
        out << v.arr[i] << " ";
    return out;
}

std::istream& operator>>(std::istream& in, Vector& v)
{
    for (size_t i = 0; i < v.cap; ++i)
        in >> v.arr[i];
    return in;
}