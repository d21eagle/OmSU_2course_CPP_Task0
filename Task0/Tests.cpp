#include <iostream>
#include <gtest/gtest.h>
#include "Box.h"
#include "Container.h"
using namespace Boxes;
using namespace Containers;

// Тесты класса Box

TEST (test, totalValue)
{   // Функция вычисляет суммарную стоимость содержимого всех коробок
    Box boxes[3] = {
            boxes[0] = Box(1, 2, 3, 5.0, 30, 0),
            boxes[1] = Box(4, 5, 6, 5.0, 40, 1),
            boxes[2] = Box(7, 8, 9, 5.0, 50, 2)
    };
    ASSERT_EQ(120, Boxes::Box::totalValue(boxes, 3));
}

TEST (test, notExceedValue)
{   // Функция проверяет, что сумма длины, ширины и высоты всех коробок не превосходит заданного значения
    Box boxes[3] = {
            boxes[0] = Box(1, 2, 3, 5.0, 30, 0),
            boxes[1] = Box(4, 5, 6, 5.0, 40, 1),
            boxes[2] = Box(7, 8, 9, 5.0, 50, 2)
    };
    ASSERT_EQ(true, Boxes::Box::notExceedValue(boxes, 3, 46));
}

TEST (test, maxWeight)
{   // Функция определяет максимальный вес коробок, объем которых не больше параметра maxV
    Box boxes[3] = {
            boxes[0] = Box(1, 2, 3, 5.0, 30, 0),
            boxes[1] = Box(4, 5, 6, 6.0, 40, 1),
            boxes[2] = Box(7, 8, 9, 7.0, 50, 2)
    };
    ASSERT_EQ(7.0, Boxes::Box::maxWeight(boxes, 3, 505));
}

TEST (test, boxInBox)
{   // Функция проверяет, что все коробки массива можно вложить друг в друга по одной штуке
    Box boxes[3] = {
            boxes[0] = Box(1, 2, 3, 5.0, 30, 0),
            boxes[1] = Box(4, 5, 6, 6.0, 40, 1),
            boxes[2] = Box(7, 8, 9, 7.0, 50, 2)
    };
    ASSERT_EQ(true, Boxes::Box::boxInBox(boxes, 3));
}

TEST (test, boxInBox_BadTest)
{   // Функция проверяет, что все коробки массива можно вложить друг в друга по одной штуке
    Box boxes[3] = {
            boxes[0] = Box(8, 13, 8, 8.0, 50, 0),
            boxes[1] = Box(10, 3, 5, 7.0, 45, 1),
            boxes[2] = Box(20, 2, 11, 11.0, 63, 2)
    };
    ASSERT_EQ(false, Boxes::Box::boxInBox(boxes, 3));
}

TEST (test, equalsOperator)
{   // Оператор == сравнения двух коробок на равенство всех параметров
    Box box1 = Box(1, 2, 3, 5, 30, 0);
    Box box2 = Box(1, 2, 3, 5, 30, 1);
    ASSERT_TRUE(box1 == box2);
}

TEST (test, equalsOperator_BadTest)
{   // Оператор == сравнения двух коробок на равенство всех параметров
    Box box1 = Box(1, 2, 3, 5, 30, 0);
    Box box2 = Box(5, 6, 7, 8, 50, 1);
    ASSERT_FALSE(box1 == box2);
}

// Тесты класса Container

TEST (test, countBoxesInContainer)
{   // Количество коробок в контейнере
    vector<Box> box_arr;
    Box box1 = Box(1, 2, 3, 5.0, 30, 0);
    Box box2 = Box(4, 5, 6, 6.0, 40, 1);
    Box box3 = Box(7, 8, 9, 7.0, 50, 2);
    box_arr.push_back(box1);
    box_arr.push_back(box2);
    box_arr.push_back(box3);

    Container cont1 = Container(box_arr, 100, 200, 300, 50.0);
    ASSERT_EQ(3, cont1.countBoxesInContainer());
}

TEST (test, appendBoxInContainer)
{   // Добавление коробки в контейнер
    try {
        vector<Box> box_arr;
        Box box1 = Box(1, 2, 3, 5.0, 30, 0);
        Box box2 = Box(4, 5, 6, 6.0, 40, 1);
        Box box3 = Box(7, 8, 9, 7.0, 50, 2);

        box_arr.push_back(box1);
        box_arr.push_back(box2);
        box_arr.push_back(box3);

        Container cont1 = Container(box_arr, 100, 200, 300, 50.0);
        Container cont2 = Container(box_arr, 100, 200, 300, 50.0);
        Box append_box = Box(10, 11, 12, 8.0, 60, 3);
        int index = cont1.appendBoxInContainer(append_box);
        ASSERT_EQ(3, index);
        ASSERT_EQ(cont1.countBoxesInContainer() - 1, cont2.countBoxesInContainer());
    }
    catch(MyException &ex) {
        ASSERT_STREQ("Too much weight\n", ex.what());
    }
}

TEST (test, deleteBoxInContainer)
{   // Удаление коробки из контейнера (по индексу)
    vector<Box> box_arr;
    Box box1 = Box(1, 2, 3, 5.0, 30, 0);
    Box box2 = Box(4, 5, 6, 6.0, 40, 1);
    Box box3 = Box(7, 8, 9, 7.0, 50, 2);
    box_arr.push_back(box1);
    box_arr.push_back(box2);
    box_arr.push_back(box3);

    Container cont1 = Container(box_arr, 100, 200, 300, 50.0);
    Container cont2 = Container(box_arr, 100, 200, 300, 50.0);
    cont1.deleteBoxInContainer(2);
    ASSERT_EQ(cont1.countBoxesInContainer() + 1, cont2.countBoxesInContainer());
}

TEST (test, totalWeightInContainer)
{   // Суммарный вес содержимого контейнера
    vector<Box> box_arr;
    Box box1 = Box(1, 2, 3, 5.0, 30, 0);
    Box box2 = Box(4, 5, 6, 6.0, 40, 1);
    Box box3 = Box(7, 8, 9, 7.0, 50, 2);
    box_arr.push_back(box1);
    box_arr.push_back(box2);
    box_arr.push_back(box3);

    Container cont1 = Container(box_arr, 100, 200, 300, 50.0);
    ASSERT_EQ(18.0, cont1.totalWeightInContainer());
}

TEST (test, totalValueInContainer)
{   // Суммарная стоимость содержимого контейнера
    vector<Box> box_arr;
    Box box1 = Box(1, 2, 3, 5.0, 30, 0);
    Box box2 = Box(4, 5, 6, 6.0, 40, 1);
    Box box3 = Box(7, 8, 9, 7.0, 50, 2);
    box_arr.push_back(box1);
    box_arr.push_back(box2);
    box_arr.push_back(box3);

    Container cont1 = Container(box_arr, 100, 200, 300, 50.0);
    ASSERT_EQ(120.0, cont1.totalValueInContainer());
}

TEST (test, returnBoxByIndex)
{   // Получение коробки по индексу
    vector<Box> box_arr;
    Box box1 = Box(1, 2, 3, 5.0, 30, 0);
    Box box2 = Box(4, 5, 6, 6.0, 40, 1);
    Box box3 = Box(7, 8, 9, 7.0, 50, 2);
    box_arr.push_back(box1);
    box_arr.push_back(box2);
    box_arr.push_back(box3);

    const Box box4 = Box(1, 2, 3, 5.0, 30, 0);
    Container cont1 = Container(box_arr, 100, 200, 300, 50.0);
    ASSERT_TRUE(box4 == cont1.returnBoxByIndex(0));
}

TEST (test, returnOrChangeBoxByIndex)
{   // Оператор [] позволяет получить/изменить коробку по индексу
    vector<Box> box_arr;
    Box box1 = Box(1, 2, 3, 5.0, 30, 0);
    Box box2 = Box(4, 5, 6, 6.0, 40, 1);
    Box box3 = Box(7, 8, 9, 7.0, 50, 2);
    box_arr.push_back(box1);
    box_arr.push_back(box2);
    box_arr.push_back(box3);

    Container cont1 = Container(box_arr, 100, 200, 300, 60.0);
    ASSERT_TRUE(box1 == cont1[0]);

    cont1[1].setLength(9);
    cont1[1].setWidth(9);
    cont1[1].setHeight(9);
    cont1[1].setWeight(9.0);
    cont1[1].setValue(60);
    Box box4 = Box(9, 9, 9, 9.0, 60, 3);
    ASSERT_TRUE(box4 == cont1[1]);
}

GTEST_API_ int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


