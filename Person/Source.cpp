// Person.cpp

#include <iostream>
#include <sstream>
#include <Windows.h>
using namespace std;

int langConsole(int);

enum GenderType{male, female, totalGender};
string GenderString[2] = { "Мужчина", "Женщина" };

struct Human {
	string mSurname { "" }; // member surname
	string mName{ "" };		// member name
	double mWeight { 0.0 }; // member weight
	double mHeight{ 0.0 };  // member height
	GenderType mGender{ }; // member gender, по умолчанию male

	// Getter - возвращает значения приватных переменных
	string Surname() const { return mSurname; }
	string Name() const { return mName; }
	double Weight() const { return mWeight; }
	double Height() const { return mHeight; }
	GenderType Gender() const { return mGender; }

	// Setter - устанавливает значения этих приватных переменных
	string Surname(string value) { return mSurname = value; }
	string Name(string value) { return mName = value; }
	double Weight(double value) { return mWeight = value; }
	double Height(double value) { return mHeight = value; }
	GenderType Gender(GenderType value) { return mGender = value; }

	// Условные функции
	bool IsMale() const { return mGender == male; }
	bool IsFemale() const { return mGender == female; }

	// Метод для преобразования числа с плавающей точкой в строку
    string ValueString(double value) const {
		ostringstream ss;
		ss << value;
		return ss.str();
	}

	string GetInfoPerson() const {
		return Surname() + " " + Name() + " | Вес: " + ValueString(Weight()) + " кг | Рост: " + ValueString(Height()) + " см | Пол: " + GenderString[Gender()] + "\n";
	}

	void PrintIfoPerson() const {
		cout << GetInfoPerson();
	}
} h;

int main()
{
	langConsole(1251);

	h = { "Точилов", "Денис", 60.12, 178.2};
	h.PrintIfoPerson();

	h = { "Точилова", "Александра", 58, 170.6, female };
	h.PrintIfoPerson();

	return 0;
}

// Функция для установки языка консоли
int langConsole(int temp) {
	SetConsoleCP(temp);
	SetConsoleOutputCP(temp);
	return temp;
}