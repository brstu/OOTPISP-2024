
#include <Windows.h>
#include <locale>

#include "Exam.h"

int main()
{

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Вызов конструктора с параметрами
    Exam *a = new Exam("Петр", 1, 4);
    // Вызов конструктора по умолчанию
    Exam b;
    // Вызов конструктора копирования
    Exam *c = new Exam(*a);

    Exam *ptr = c;
    ptr->Print();

    // Вызов сеттеров для объекта b
    b.SetDate(12);
    b.SetGrade(10);
    b.SetName("Федор");

    b.Print();

    // Вызов сеттера для объекта а
    a->Set("Евгений", 10, 8);

    a->Print();

    void (Exam::*pf)();
    pf = &Exam::Print;

    // Размещение в стеке
    Exam firstGroup[3] = {
        Exam("Виктор", 1, 10),
        Exam("Виталий", 1, 10),
        Exam("Дмитрий", 1, 10)};

    for (int i = 0; i < 3; i++)
    {
        (firstGroup[i].*pf)();
    }

    // Размещение в куче
    Exam *secondGroup = new Exam[3];
    secondGroup[0].Set("Роман", 3, 4);
    secondGroup[1].Set("Ахмет", 3, 5);
    secondGroup[2].Set("Фиодосий", 3, 6);

    for (int i = 0; i < 3; i++)
    {
        (secondGroup[i].*pf)();
    }

    // Деструкторы масива в динамической памяти
    delete[] secondGroup;

    // Вызов деструкторов в статической памяти
    delete a; // Вызов деструктора а
    delete c; // Вызов деструктора c
              // Вызов деструктора b
}
