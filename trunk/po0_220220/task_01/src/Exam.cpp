#include "Exam.h"

void Exam::SetName(const char *name)
{
	_studentName = std::make_unique<std::string>(name);
}

void Exam::Set(const char *name, const int date, const int grade)
{
	this->_date = date;
	this->_grade = grade;
	_studentName = std::make_unique<std::string>(name);
}

Exam::Exam(const char *name, const int date, const int grade)
	: _studentName(std::make_unique<std::string>(name)), _date(date), _grade(grade)
{
	std::cout << "The constructor with parameters is called " << this << std::endl;
}

Exam::Exam()
{
	std::cout << "A constructor without parameters is called " << this << std::endl;
}

void Exam::Print() const
{
	std::cout << "Student name: " << _studentName << std::endl;
	std::cout << "Exam day: " << _date << std::endl;
	std::cout << "Grade: " << _grade << std::endl;
	std::cout << std::endl;
}