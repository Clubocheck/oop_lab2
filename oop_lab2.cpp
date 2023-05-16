#include <iostream>
#include <string>

using namespace std;

class Cat
{
protected:
	string CatName;
public:
	Cat()
	{
		printf("Cat()\n");
		CatName = "Simon";
	}

	Cat(string CatName)
	{
		printf("Cat(string CatName)\n");
		this->CatName = CatName;
	}

	Cat(const Cat& Kitty)
	{
		printf("Cat(const Cat& Kitty)\n");
		CatName = Kitty.CatName;
	}

	~Cat()
	{
		cout << "Cat name is " << CatName << endl;
		printf("~Cat()\n");
	}
	string SayName()
	{
		return CatName;
	}
	void Rename(string NewName);
};

void Cat::Rename(string NewName)
{
	CatName = NewName;
}

class CatAges : public Cat
{
protected:
	int CatAge;
public:
	CatAges() :Cat()
	{
		printf("CatAges()\n");
		CatAge = 0;
	}

	CatAges(string CatName, int CatAge) :Cat(CatName)
	{
		printf("CatAges(int CatAge)\n");
		this->CatAge = CatAge;
	}

	CatAges(const CatAges& Kitty)
	{
		printf("Cat(const CatAges& Kitty)\n");
		CatAge = Kitty.CatAge;
		CatName = Kitty.CatName;
	}

	~CatAges()
	{
		cout << "Cat age is " << CatAge << endl;
		printf("~CatAges()\n");
	}
	int SayAge()
	{
		return CatAge;
	}
	void Reage(int NewAge);
};

void CatAges::Reage(int NewAge)
{
	CatAge = NewAge;
}

class CatFamily
{
private:
	Cat* Kitty1;
	Cat* Kitty2;
	Cat* Kitty3;
public:
	CatFamily()
	{
		cout << "kf" << endl;
		Kitty1 = new Cat();
		Kitty2 = new Cat();
		Kitty3 = new Cat();
	}

	CatFamily(string name1, string name2, string name3)
	{
		cout << "kf" << endl;
		Kitty1 = new Cat(name1);
		Kitty2 = new Cat(name2);
		Kitty3 = new Cat(name3);
	}

	CatFamily(const CatFamily& KittyFamily)
	{
		cout << "kf" << endl;
		Kitty1 = new Cat(*(KittyFamily.Kitty1));
		Kitty2 = new Cat(*(KittyFamily.Kitty2));
		Kitty3 = new Cat(*(KittyFamily.Kitty3));
	}

	~CatFamily()
	{
		cout << "end kf" << endl;
		delete Kitty1;
		delete Kitty2;
		delete Kitty3;
	}
};

void main()
{
	setlocale(LC_ALL, "rus");
	cout << "Создание и удаление объекта клаасса Cat:" << endl;
	{
		cout << "Без параметров:" << endl;
		Cat Kitty1;
		cout << "С параметрами" << endl;
		Cat Kitty2("Misa");
		cout << "Копирование предыдущего" << endl;
		Cat Kitty3(Kitty2);
		cout << "Переименовать второго котёнка как Мика" << endl;
		Kitty2.Rename("Mika");
		cout << "Их удаление" << endl;
	}

	cout << "Создание и удаление объекта клаасса-наследника CatAges:" << endl;
	{
		cout << "Без параметров:" << endl;
		CatAges* Kitty1 = new CatAges();
		cout << "С параметрами" << endl;
		CatAges* Kitty2 = new CatAges("Nelly",3);
		cout << "Копирование предыдущего" << endl;
		CatAges* Kitty3 = new CatAges(*Kitty2);
		cout << "Изменить возраст первого котёнка на 1 год" << endl;
		Kitty1->Reage(1);
		cout << "Их удаление" << endl;
		delete Kitty1;
		delete Kitty2;
		delete Kitty3;
	}

	cout << "Создание и удаление объекта клаасса Cat как CatAge:" << endl;
	{
		Cat* Kitty = new CatAges();
		delete Kitty;
	}
	cout << "Создание и удаление объекта клаасса CatFamily:" << endl;
	{
		cout << "Без параметров:" << endl;
		CatFamily* KittyFamily1 = new CatFamily();
		cout << "С параметрами" << endl;
		CatFamily* KittyFamily2 = new CatFamily("Molly","Mike","Ted");
		cout << "Копирование предыдущего" << endl;
		CatFamily* KittyFamily3 = new CatFamily(*KittyFamily2);
		cout << "Их удаление" << endl;
		delete KittyFamily1;
		delete KittyFamily2;
		delete KittyFamily3;
	}
}