#include "Exam.h"

Exam::Exam(const Exam &other)
{
	this->date = other.date;

	this->grade = other.grade;

	this->studentName = new char[strnlen(other.studentName, STR_MAX_SIZE) + 1];
	strcpy_s(this->studentName, strnlen(other.studentName, STR_MAX_SIZE) + 1, other.studentName);

	std::cout << "Вызван конструктор копирования " << this << std::endl;
}

void Exam::SetName(const char *name)
{
	if (studentName != nullptr)
		delete[] this->studentName;

	this->studentName = new char[strnlen(name, STR_MAX_SIZE) + 1];
	strcpy_s(this->studentName, strnlen(name, STR_MAX_SIZE) + 1, name);
}

void Exam::Set(const char *name, const int date, const int grade)
{
	this->date = date;
	this->grade = grade;

	if (studentName != nullptr)
		delete[] this->studentName;

	this->studentName = new char[strnlen(name, STR_MAX_SIZE) + 1];
	strcpy_s(this->studentName, strnlen(name, STR_MAX_SIZE) + 1, name);
}

Exam::Exam(const char *name, const int date, const int grade)
{
	std::cout << "Вызван конструктор с параметрами " << this << std::endl;

	this->studentName = new char[strnlen(name, STR_MAX_SIZE) + 1];
	strcpy_s(this->studentName, strnlen(name, STR_MAX_SIZE) + 1, name);

	this->date = date;
	this->grade = grade;
}

Exam::Exam()
	: studentName(nullptr), date(1), grade(0)
{
	std::cout << "Вызван конструктор без параметров " << this << std::endl;
}

Exam::~Exam()
{
	std::cout << "Вызван деструктор " << this << std::endl;
	delete[] studentName;
}

void Exam::Print()
{
	std::cout << "Имя студента: " << studentName << std::endl;
	std::cout << "День экзамена: " << date << std::endl;
	std::cout << "Оценка: " << grade << std::endl;
	std::cout << std::endl;
}