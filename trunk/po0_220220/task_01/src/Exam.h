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
	Exam &operator=(const Exam &rhs);

	// Геттеры
	std::string GetName() const { return *_studentName; };
	int GetDate() const { return _date; };
	int GetGrade() const { return _grade; };

	// Сеттеры
	void SetName(const char *name);
	inline void SetDate(const int date) { this->_date = date; };
	inline void SetGrade(const int grade) { this->_grade = grade; };
	void Set(const char *name, int date, const int grade);

	void Print() const;

	// Деструктор
	~Exam();

private:
	std::unique_ptr<std::string> _studentName;
	int _date = 1;
	int _grade = 0;
};

#endif
