﻿// Person.cpp

#include <iostream>
#include <sstream>
#include <Windows.h>
using namespace std;

int langConsole(int);

struct Human {
	string surname { "" };
	string name{ "" };
	double weight { 0.0 };
	double height{ 0.0 };

	// Getter - возвращает значения приватных переменных
	string Surname() const { return surname; }
	string Name() const { return name; }
	double Weight() const { return weight; }
	double Height() const { return height; }

	// Setter - устанавливает значения этих приватных переменных
	string Surname(string value) { return surname = value; }
	string Name(string value) { return name = value; }
	double Weight(double value) { return weight = value; }
	double Height(double value) { return height = value; }
	
	// Метод для преобразования числа с плавающей точкой в строку
    string ValueString(double value) const {
		ostringstream ss;
		ss << value;
		return ss.str();
	}

	string GetInfoPerson() const {
		return Surname() + " " + Name() + " | Вес: " + ValueString(Weight()) + " кг | Рост: " + ValueString(Height()) + " см";
	}

	void PrintIfoPerson() const {
		cout << GetInfoPerson();
	}
} h;

int main()
{
	langConsole(1251);

	h = { "Точилов", "Денис", 60.12, 178.2 };
	h.PrintIfoPerson();

	return 0;
}

// Функция для установки языка консоли
int langConsole(int temp) {
	SetConsoleCP(temp);
	SetConsoleOutputCP(temp);
	return temp;
}