#pragma once
#include <vector>
#include "Box.h"
using namespace Boxes;

namespace Containers
{
    class Container {
    public:
        vector<Box> array;
        int length;
        int width;
        int height;
        int maxWeight;

        Container(const vector<Box>& array, int length, int width, int height, int maxWeight);

        int appendBoxInContainer(Box box);

        void deleteBoxInContainer(int i);

        [[nodiscard]]
        unsigned long long int countBoxesInContainer() const;

        double totalWeightInContainer();

        int totalValueInContainer();

        const Box& returnBoxByIndex(int i);

        Box& operator[] (int index);
    };

    istream& operator >> (istream& in, Container& container);
    ostream& operator << (ostream& out, Container& container);

    class MyException : public exception {
    private:
        string m_error;
    public:
        explicit MyException(string error) : m_error(std::move(error)) {}
        [[nodiscard]] const char* what() const noexcept override { return m_error.c_str(); }
    };

}