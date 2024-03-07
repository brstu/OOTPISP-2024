
# Лабораторная работа №1 #

## Классы и объекты в С++ ##

## Вариант 6 ##
 

## Цель работы ##
Получить практические навыки реализации классов на С++.


### Блоки с кодом реализации конструкторов и деструктора ###
```c++
Exam::Exam(const Exam &other)
{
	this->date = other.date;

	this->grade = other.grade;

	this->studentName = new char[strlen(other.studentName) + 1];
	strcpy_s(this->studentName, strlen(other.studentName) + 1, other.studentName);

	std::cout << "Вызван конструктор копирования " << this << std::endl;
}

Exam::Exam(const char *name, const int date, const int grade)
{
	std::cout << "Вызван конструктор с параметрами " << this << std::endl;

	this->studentName = new char[strlen(name) + 1];
	strcpy_s(this->studentName, strlen(name) + 1, name);

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
```

### Фрагмент программы, показывающий использование указателя на объект и указателя на функцию ###

#### Указатель на объект ####

```c++
Exam *ptr = c;
ptr->Print();
```

#### В переменную ptr записывается адрес переменной с. Затем вызывается метод Print класса Exam. Метод выведет в консоль поля объекта с. ####

#### Указатель на функцию ####

```c++
void (Exam::*pf)();
pf = &Exam::Print;

Exam firstGroup[3] = {
        Exam("Виктор", 1, 10),
        Exam("Виталий", 1, 10),
        Exam("Дмитрий", 1, 10)};

for (int i = 0; i < 3; i++)
{
    (firstGroup[i].*pf)();
}
```

#### Адрес функции print записывается в указатель на функцию. Затем каждый элемент массива разыменовывает указатель и вызывает функцию Print ####



#### Результат работы программы ####

[img_01](images/img_01.png)
