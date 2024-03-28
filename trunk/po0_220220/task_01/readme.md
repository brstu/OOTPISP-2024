
# Лабораторная работа №1 #

## Классы и объекты в С++ ##

## Вариант 6 ##
 

## Цель работы ##
Получить практические навыки реализации классов на С++.


### Блоки с кодом реализации конструкторов и деструктора ###
```c++
Exam::Exam(const char *name, const int date, const int grade)
	: _studentName(std::make_unique<std::string>(name)), _date(date), _grade(grade)
{
	std::cout << "The constructor with parameters is called " << this << std::endl;
}

Exam::Exam()
{
	std::cout << "A constructor without parameters is called " << this << std::endl;
}

```

### Фрагмент программы, показывающий использование указателя на объект и указателя на функцию ###

#### Указатель на объект ####

```c++
a->Print();
```

#### В переменной а содержится адрес объекта. Затем вызывается метод Print класса Exam. Метод выведет в консоль поля объекта а. ####

#### Указатель на функцию ####

```c++
void (Exam::*pf)() const = &Exam::Print;

std::array<Exam, 3> firstGroup = {
    Exam("Victor", 1, 10),
    Exam("Vitaliy", 1, 10),
    Exam("Dima", 1, 10)};

for (int i = 0; i < 3; i++)
{
    (firstGroup[i].*pf)();
}
```

#### Адрес функции print записывается в указатель на функцию. Затем каждый элемент массива разыменовывает указатель и вызывает функцию Print ####



#### Результат работы программы ####

[img_01](images/img_01.png)
