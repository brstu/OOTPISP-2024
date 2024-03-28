# Лабораторная работа №1

## Классы и объекты в С++

## Вариант 3

## Цель работы

Получить практические навыки реализации классов на С++.
Было сделано: определил пользовательский класс, определить в классе конструктор без параметров, с параметрами и копирования, а так же деструктор. Реализовал в классе компоненты-функции для просмотра и установки полей данных. Создал указатель на компоненту-функцию Определил указатель на экземпляр класса. Написал демонстрационную программу, в которой создаются и разрушаются объекты пользовательского класса и каждый вызов конструктора и деструктора сопровождается выдачей сообщения о вызове.Также было показано использование указателя на объект и указателя на компоненту-функцию.

### Блоки с кодом реализации конструкторов и деструктора

```c++
Staff::Staff(const Staff &other)
	: _workshopNumber(other._workshopNumber), _category(other._category)
{
	_workerName = std::make_unique<std::string>(*other._workerName);

	std::cout << "The copy constructor is called: " << this << std::endl;
}

Staff::Staff(const char *name, const int workshopNumber, const int category)
	: _workerName(std::make_unique<std::string>(name)), _workshopNumber (workshopNumber), _category(category)
{
	std::cout << "The constructor with parameters is called: " << this << std::endl;
}

Staff::Staff()
{
	std::cout << "A constructor without parameters is called: " << this << std::endl;
}

Staff::~Staff()
{
	std::cout << "Destructor called: " << this << std::endl;
}
```

### Фрагмент программы, показывающий использование указателя на объект и указателя на функцию

#### Указатель на объект

```c++
auto ptr = third;
ptr->Print();
```

#### В переменную ptr записывается адрес объекта third, для него вызывается метод Print класса Staff, который выведет в консоль поля объекта этого объкта.

#### Указатель на функцию

```c++
void (Staff::*pf)() const = &Staff::Print;

std::array<Staff, 3> firstTeam = {
    Staff("Victor", 1, 10),
    Staff("Vitaliy", 1, 10),
    Staff("Dima", 1, 10)};

for (int i = 0; i < 3; i++)
{
    (firstTeam[i].*pf)();
}
```

#### Адрес функции Print записывается в указатель на функцию. Затем каждый элемент массива firstTeam разыменовывает данный указатель и вызывает функцию Print.
