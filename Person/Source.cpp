#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>
#include <Windows.h>
using namespace std;

enum GenderType{
	male, 
	female,

	totalGender
};
string GenderString[totalGender] = { "Мужчина", "Женщина" };

struct Human {
	string mSurname { "" };
	string mName{ "" };
	double mWeight { 0.0 };
	double mHeight{ 0.0 };
	GenderType mGender{ };

	string Surname() const { return mSurname; }
	string Name() const { return mName; }
	double Weight() const { return mWeight; }
	double Height() const { return mHeight; }
	GenderType Gender() const { return mGender; }

	void Surname(string value) { mSurname = value; }
	void Name(string value) { mName = value; }
	void Weight(double value) { mWeight = value; }
	void Height(double value) { mHeight = value; }
	void Gender(GenderType value) { mGender = value; }

	bool IsMale() const { return mGender == male; }
	bool IsFemale() const { return mGender == female; }

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

string MaleNames[5] = { "Александр", "Михаил", "Максим", "Артём", "Лев" };
string FemaleNames[5] = { "Софья", "Мария", "Ева", "Виктория", "Анна" };
string MaleSurnames[10] = { "Иванов", "Смирнов", "Кузнецов", "Попов", "Соколов", "Лебедев", "Козлов", "Новиков", "Морозов", "Петров" };

int langConsole(int);
int getValidInteger(int);
Human GeneratedHuman();
void fillHumanArray(vector<Human>&, int);

double averageWeight(vector<Human>&);
double averageHeight(vector<Human>&);
void printHumanAndAvg(vector<Human>&, double, double);

void sortByWeight(vector<Human>&);
void sortByHeight(vector<Human>&);
void printHumanSort(vector<Human>&);

int main()
{
	langConsole(1251);
	srand(time(0));
	int n = getValidInteger(0);
	vector<Human> humans;
	fillHumanArray(humans, n);

	double avgWeight = averageWeight(humans);
	double avgHeight = averageHeight(humans);
	printHumanAndAvg(humans, avgWeight, avgHeight);

	cout << "Cписок всех людей по росту по возрастанию:" << endl;
	sortByHeight(humans);
	printHumanSort(humans);

	cout << "\nCписок всех людей по весу по возрастанию:" << endl;
	sortByWeight(humans);
	printHumanSort(humans);
	return 0;
}

int langConsole(int codePage) {
	SetConsoleCP(codePage);
	SetConsoleOutputCP(codePage);
	return codePage;
}

int getValidInteger(int n) {
	do {
		cout << "Введите целое число от 10 до 100: ";
		cin >> n;
		if (n < 10 || n > 100) {
			cout << "Некорректное значение. " << n << endl;
		}
	} while (n < 10 || n > 100);
	return n;
}

Human GeneratedHuman() {
	GenderType gender = rand() % 2 ? female : male;
	string surname = gender == male ? MaleSurnames[rand() % 10] : MaleSurnames[rand() % 10] + "а";
	string name = gender == male ? MaleNames[rand() % 5] : FemaleNames[rand() % 5];
	double weight = rand() % 160 + 40;
	double height = rand() % 100 + 110;
	Human h{ surname, name, weight, height, gender };
	return h;
}

void fillHumanArray(vector<Human>& humans, int size)
{
	for (int i = 0; i < size; i++)
		humans.push_back(GeneratedHuman());
}

double averageWeight(vector<Human>& humans) {
	double avgWeight = 0;
	for (Human human : humans)
		avgWeight += human.Weight();

	avgWeight /= humans.size();
	return avgWeight;
}

double averageHeight(vector<Human>& humans) {
	double avgHeight = 0;
	for (Human human : humans)
		avgHeight += human.Height();

	avgHeight /= humans.size();
	return avgHeight;
}

void printHumanAndAvg(vector<Human>& humans, double avgWeight, double avgHeight) {
	int index = 1;
	for (Human human : humans) {
		cout << "[" << index << "] " << human.GetInfoPerson() << endl;
		index++;
	}
	cout << "\nСредний вес: " << avgWeight << " кг.\n";
	cout << "Средний рост: " << avgHeight << " см.\n\n";
}

void sortByHeight(vector<Human>& humans) {
	for (size_t i = 0; i < humans.size() - 1; i++) {
		for (size_t j = 0; j < humans.size() - i - 1; j++) {
			if (humans[j].Height() > humans[j + 1].Height()) {
				swap(humans[j], humans[j + 1]);
			}
		}
	}
}

void sortByWeight(vector<Human>& humans) {
	for (size_t i = 0; i < humans.size() - 1; i++) {
		for (size_t j = 0; j < humans.size() - i - 1; j++) {
			if (humans[j].Weight() > humans[j + 1].Weight()) {
				swap(humans[j], humans[j + 1]);
			}
		}
	}
}

void printHumanSort(vector<Human>& humans) {
	int index = 1;
	for (Human human : humans){
		cout << "[" << index << "] " << human.GetInfoPerson() << endl;
		index++;
	}
}