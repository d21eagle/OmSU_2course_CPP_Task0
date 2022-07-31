#include "RingBuffer.h"
#include <iostream>
using namespace std;

int main()
{
    system("chcp 65001");

    size_t size = 5;
    RingBuffer<double> buffer(size);

    buffer.addElemInEnd(10);
    buffer.addElemInEnd(11);
    buffer.addElemInEnd(12);
    buffer.addElemInEnd(14);
    buffer.addElemInEnd(15);

    Iterator iter(buffer);

    iter.start();

    cout << "Элементы очереди: " << endl;
    for (int i = 0; i < buffer.getSizeBuffer(); i++)
    {
        cout << iter.getValue() << endl;
        iter.next();
    }

    cout << "\nТест на исключение при переполнении:" << endl;
    // Тест на исключение при переполнении
    try {
        buffer.addElemInEnd(16);
    }
    catch (MyException &ex) {
        cout << ex.what() << endl;
    }

    double getElem = buffer.getElemInStart();
    cout << "\nИзъятый элемент из начала очереди: ";
    cout << getElem << endl;

    size_t buffSize = buffer.getSizeBuffer();
    cout << "\nРазмер очереди: ";
    cout << buffSize << endl;

    double checkElem = buffer.checkElemInStart();
    cout << "\nПросмотр элемента в начале очереди: ";
    cout << checkElem << endl;

    double checkElem1 = buffer.checkElemInStart();
    cout << "\nПросмотр элемента в начале очереди: ";
    cout << checkElem1 << endl;

    buffer.addElemInEnd(17);
    size_t buffSize2 = buffer.getSizeBuffer();
    cout << "\nРазмер очереди: ";
    cout << buffSize2 << endl;
    cout << endl;

    buffer.clearBuffer();
    bool emptyCheck = buffer.isEmpty();
    cout << "\nПроверка очереди на пустоту: ";
    cout << emptyCheck << endl;

    // Тест на исключение при отсутствии элементов
    cout << "\nТест на исключение при отсутствии элементов:" << endl;
    try {
        double getElemEx = buffer.getElemInStart();
    }
    catch (MyException &ex) {
        cout << ex.what() << endl;
    }

    bool iterCheck = iter.finish();
    cout << "\nПроверка, все ли проитерировано: ";
    cout << iterCheck << endl;
    cout << endl;
}