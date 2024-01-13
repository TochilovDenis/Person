// Person.cpp

#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>
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
string GenderString[totalGender] = { "Мужчина", "Женщина" };

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
		return Surname() + " " + Name() + " | Вес: " + ValueString(Weight()) + " кг | Рост: " + ValueString(Height()) + " см | Пол: " + GenderString[Gender()];
	}

	void PrintInfoPerson() const {
		cout << GetInfoPerson();
	}
} h;

int Put(int);
Human GeneratedHuman();
void fillHumanArray(vector<Human>& , int);
void printHumanArray(vector<Human>& humanArray);

int main()
{
	srand(time(0));
	langConsole(1251);
	int n = Put(0);
	vector<Human> humans;
	fillHumanArray(humans, n);
	printHumanArray(humans);

	return 0;
}

// Функция для установки языка консоли
int langConsole(int codePage) {
	SetConsoleCP(codePage);
	SetConsoleOutputCP(codePage);
	return codePage;
}

int Put(int n) {
	do {
		cout << "Введите целое число от 10 до 100: ";
		cin >> n;
	} while (n < 10 || n > 100);
	return n;
}

Human GeneratedHuman() {
	GenderType gender = rand() % totalGender ? male : female;
	string surname = gender == male ? MaleSurnames[rand() % 10] : MaleSurnames[rand() % 10] + "a";
	string name = gender == male ? MaleNames[rand() % 5] : FemaleNames[rand() % 5];
	double weight = rand() % 160 + 40;
	double height = rand() % 100 + 110;
	Human hGen{ surname, name, weight, height, gender };
	return hGen;
}

void fillHumanArray(vector<Human>& humanArray, int size)
{
	for (int i = 0; i < size; i++) {
		humanArray.push_back(GeneratedHuman());
	}
}

void printHumanArray(vector<Human>& humanArray)
{
	for (Human human : humanArray)
	{
		cout << human.GetInfoPerson() << endl;
	}
}

