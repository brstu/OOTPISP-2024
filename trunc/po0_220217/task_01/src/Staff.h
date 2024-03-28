#ifndef Staff_H
#define Staff_H

#include <iostream>
#include <string>
#include <memory>

constexpr static auto STR_MAX_SIZE = 100;

class Staff
{
public:
    Staff();
    Staff(const char *name, const int workshopNumber, const int category);
    Staff(const Staff &other);

    std::string GetName() const;
    int GetWorkshopNumber() const;
    int GetCategory() const;

    void SetName(const char *name);
    void SetWorkshopNumber(const int workshopNumber);
    void SetCategory(const int category);
    void Set(const char *name, int workshopNumber, const int category);

    void Print() const;

    ~Staff();

private:
    std::unique_ptr<std::string> _workerName;
    int _workshopNumber = 1;
    int _category = 1;
};
#endif