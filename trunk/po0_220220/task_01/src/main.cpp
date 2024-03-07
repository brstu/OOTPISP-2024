

#include "Exam.h"

int main()
{


    Exam *a = new Exam("Petr", 1, 4);
    Exam b;
    Exam *c = new Exam(*a);

    Exam *ptr = c;
    ptr->Print();

    b.SetDate(12);
    b.SetGrade(10);
    b.SetName("Fedor");

    b.Print();

    a->Set("Evgeniy", 10, 8);

    a->Print();

    void (Exam::*pf)();
    pf = &Exam::Print;

    Exam firstGroup[3] = {
        Exam("Victor", 1, 10),
        Exam("Vitaliy", 1, 10),
        Exam("Dima", 1, 10)};

    for (int i = 0; i < 3; i++)
    {
        (firstGroup[i].*pf)();
    }

    Exam *secondGroup = new Exam[3];
    secondGroup[0].Set("Roman", 3, 4);
    secondGroup[1].Set("Axmet", 3, 5);
    secondGroup[2].Set("Fiodociy", 3, 6);

    for (int i = 0; i < 3; i++)
    {
        (secondGroup[i].*pf)();
    }

    delete[] secondGroup;

    
    delete a;
    delete c; 
}
