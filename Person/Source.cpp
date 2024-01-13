// Person.cpp

#include <iostream>
#include <sstream>
#include <ctime>
#include <Windows.h>
using namespace std;

int langConsole(int);

string MaleNames[5] = { "Александр", "Михаил", "Максим", "Артём", "Лев" };
string FemaleNames[5] = { "Софья", "Мария", "Ева", "Виктория", "Анна" };
string MaleSurnames[10] = { "Иванов", "Смирнов", "Кузнецов", "Попов", "Соколов", "Лебедев", "Козлов", "Новиков", "Морозов", "Петров" };

enum GenderType{
	male, 
	female,

	totalGender
};
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

void GeneratedHuman();

int main()
{
	langConsole(1251);
	
	GeneratedHuman();

	return 0;
}

// Функция для установки языка консоли
int langConsole(int codePage) {
	SetConsoleCP(codePage);
	SetConsoleOutputCP(codePage);
	return codePage;
}

void GeneratedHuman() {
	srand(time(0));
	GenderType gender = rand() % 2 ? male : female;
	string surname = gender == male ? MaleSurnames[rand() % 10] : MaleSurnames[rand() % 10] + "a",
		name = gender == male ? MaleNames[rand() % 5] : FemaleNames[rand() % 5];
	double weight = rand() % 40 + 140,
		height = rand() % 40 + 80;
	Human h{ surname, name, weight, height, gender };
	h.PrintIfoPerson();
}