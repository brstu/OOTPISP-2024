
#include <memory>
#include <vector>
#include <array>
#include "Exam.h"

int main()
{

    auto a = std::make_unique<Exam>("Petr", 1, 4);
    Exam b;

    a->Print();

    b.SetDate(12);
    b.SetGrade(10);
    b.SetName("Fedor");

    b.Print();

    a->Set("Evgeniy", 10, 8);

    a->Print();

    void (Exam::*pf)() const = &Exam::Print;

    std::array<Exam, 3> firstGroup = {
        Exam("Victor", 1, 10),
        Exam("Vitaliy", 1, 10),
        Exam("Dima", 1, 10)};

    for (int i = 0; i < 3; i++)
    {
        (firstGroup[i].*pf)();
    }

    auto secondGroup = std::make_unique<Exam[]>(3);
    secondGroup[0].Set("Roman", 3, 4);
    secondGroup[1].Set("Axmet", 3, 5);
    secondGroup[2].Set("Fiodociy", 3, 6);

    for (int i = 0; i < 3; i++)
    {
        (secondGroup[i].*pf)();
    }
}
