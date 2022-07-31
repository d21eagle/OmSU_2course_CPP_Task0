
// С++ Блок 1 Доп

#include "Vector.h"
#include <iostream>
using namespace std;

int main()
{
    Vector v = { 1, -25, 2 };
    v.push_back(-5);
    std::cout << v << v.getSize() << " " << v.capacity();
    v.pop_back();
    v.pop_back();
    std::cout << v;
}