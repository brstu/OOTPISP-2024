#include "Exam.h"

Exam::Exam(const Exam &other)
{
	this->date = other.date;

	this->grade = other.grade;

	this->studentName = new char[strnlen(other.studentName, STR_MAX_SIZE) + 1];
	strncpy(this->studentName, other.studentName, strnlen(other.studentName, STR_MAX_SIZE) + 1);

	std::cout << "The copy constructor is called " << this << std::endl;
}

void Exam::SetName(const char *name)
{
	if (studentName != nullptr)
		delete[] this->studentName;

	this->studentName = new char[strnlen(name, STR_MAX_SIZE) + 1];
	strncpy(this->studentName, name, strnlen(name, STR_MAX_SIZE) + 1);
}

void Exam::Set(const char *name, const int date, const int grade)
{
	this->date = date;
	this->grade = grade;

	if (studentName != nullptr)
		delete[] this->studentName;

	this->studentName = new char[strnlen(name, STR_MAX_SIZE) + 1];
	strncpy(this->studentName, name, strnlen(name, STR_MAX_SIZE) + 1);
}

Exam::Exam(const char *name, const int date, const int grade)
{
	std::cout << "The constructor with parameters is called " << this << std::endl;

	this->studentName = new char[strnlen(name, STR_MAX_SIZE) + 1];
	strncpy(this->studentName, name, strnlen(name, STR_MAX_SIZE) + 1);

	this->date = date;
	this->grade = grade;
}

Exam::Exam()
	: studentName(nullptr), date(1), grade(0)
{
	std::cout << "A constructor without parameters is called " << this << std::endl;
}

Exam::~Exam()
{
	std::cout << "Destructor called " << this << std::endl;
	delete[] studentName;
}

void Exam::Print()
{
	std::cout << "Student name: " << studentName << std::endl;
	std::cout << "Exam day: " << date << std::endl;
	std::cout << "Grade: " << grade << std::endl;
	std::cout << std::endl;
}