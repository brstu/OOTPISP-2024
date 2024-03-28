#include <memory>
#include <vector>
#include <array>
#include "Staff.h"

int main()
{
    auto first = std::make_unique<Staff>("Petr", 1, 4);
    Staff second;
    auto third = std::make_shared<Staff>(*first);

    auto ptr = third;
    ptr->Print();

    second.SetWorkshopNumber(2);
    second.SetCategory(2);
    second.SetName("Anton");
    second.Print();

    first->Set("Artemi", 3, 4);
    first->Print();

    void (Staff::*pf)() const = &Staff::Print;

    std::array<Staff, 3> firstTeam = {
        Staff("Victor", 1, 2),
        Staff("Vitaliy", 1, 4),
        Staff("Dima", 1, 3)};

    for (int i = 0; i < 3; i++)
    {
        (firstTeam[i].*pf)();
    }

    auto secondTeam = std::make_unique<Staff[]>(3);
    secondTeam[0].Set("Kiril", 3, 4);
    secondTeam[1].Set("Artur", 3, 5);
    secondTeam[2].Set("Roy", 3, 6);

    for (int i = 0; i < 3; i++)
    {
        secondTeam[i].Print();
    }

    Staff fourth = secondTeam[1];
    fourth.Print();
}
