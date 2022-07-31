#pragma once
#include <iostream>

class Vector
{
private:
    size_t size = 0;
    size_t cap = 0;
    int* arr = nullptr;

public:
    Vector();
    explicit Vector(size_t);
    Vector(size_t, int);
    Vector(const Vector&);
    Vector(std::initializer_list<int>);
    Vector(Vector&&) noexcept;
    ~Vector();

    [[nodiscard]] size_t getSize() const { return size; }
    [[nodiscard]] size_t capacity()const { return cap; }
    void push_back(int);
    void pop_back();
    void reserve(size_t);
    void resize(int);

    int& operator[](int i) { return arr[i]; }
    const int& operator[](int i) const { return arr[i]; }
    Vector& operator=(const Vector&);
    Vector& operator+=(const Vector&);
    Vector operator+(const Vector&);

    bool operator==(const Vector&) const;
    bool operator!=(const Vector&) const;

    friend std::ostream& operator<<(std::ostream&, const Vector&);
    friend std::istream& operator>>(std::istream&, Vector&);
};
