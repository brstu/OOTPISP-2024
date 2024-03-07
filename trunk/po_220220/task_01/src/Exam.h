#ifndef EXAM_H
#define EXAM_H

#include <iostream>
#include <string>

constexpr static auto STR_MAX_SIZE = 100;

class Exam
{
public:
	Exam();													 // Конструктор по умолчанию
	Exam(const char *name, const int date, const int grade); // Конструктор с параметрами
	Exam(const Exam &other);								 // Конструктор копирования

	// Геттеры
	char *GetName() const { return studentName; };
	int GetDate() const { return date; };
	int GetGrade() const { return grade; };

	// Сеттеры
	void SetName(const char *name);
	inline void SetDate(const int date) { this->date = date; };
	inline void SetGrade(const int grade) { this->grade = grade; };
	void Set(const char *name, int date, const int grade);

	void Print();

	// Деструктор
	~Exam();

private:
	char *studentName = nullptr;
	int date;
	int grade;
};

#endif
