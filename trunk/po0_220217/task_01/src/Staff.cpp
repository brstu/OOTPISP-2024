#include "Staff.h"

Staff::Staff(const char *name, const int workshopNumber, const int category)
    : _workerName(std::make_unique<std::string>(name)), _workshopNumber(workshopNumber), _category(category)
{
    std::cout << "The constructor with parameters is called:  " << this << std::endl;
}

Staff::Staff()
{
    std::cout << "The constructor without parameters is called: " << this << std::endl;
}

Staff::Staff(const Staff &other)
    : _workshopNumber(other._workshopNumber), _category(other._category), _workerName(std::make_unique<std::string>(*other._workerName))
{
    std::cout << "The copy constructor is called:  " << this << std::endl;
}

std::string Staff::GetName() const
{
    return *_workerName;
};

int Staff::GetWorkshopNumber() const
{
    return _workshopNumber;
};

int Staff::GetCategory() const
{
    return _category;
};

void Staff::SetName(const char *name)
{
    _workerName = std::make_unique<std::string>(name);
}

void Staff::SetWorkshopNumber(const int workshopNumber)
{
    this->_workshopNumber = workshopNumber;
};

void Staff::SetCategory(const int category)
{
    this->_category = category;
};

void Staff::Set(const char *name, const int workshopNumber, const int category)
{
    this->_workshopNumber = workshopNumber;
    this->_category = category;
    _workerName = std::make_unique<std::string>(name);
}

void Staff::Print() const
{
    std::cout << "Worker name: " << *_workerName << std::endl;
    std::cout << "Workshop number: " << _workshopNumber << std::endl;
    std::cout << "Category: " << _category << std::endl;
    std::cout << std::endl;
}

Staff::~Staff()
{
    std::cout << "The destructor called:  " << this << std::endl;
}
