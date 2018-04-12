#include "Person6.h"
#include "../Sex.h"

namespace Lab6
{
	void Person::SetName(string name)
	{
		if (name.length() < 1)
		{
			throw new exception("Person name is null");
		}
		Name = name;
	}

	void Person::SetSurname(string surname)
	{
		if (surname.length() < 1)
		{
			throw new exception("Person surname is null");
		}
		Surname = surname;
	}

	void Person::SetSex(enum Sex sex)
	{
		Sex = sex;
	}

	void Person::SetAge(unsigned int age)
	{
		if (age < 0 || age > 160)
		{
			throw new exception("Incorrect age");
		}
		Age = age;
	}

	Sex Person::GetSex()
	{
		return Sex;
	}

	string Person::GetDescription()
	{
		string temp;
		temp.append(Name)
			.append(" ")
			.append(Surname)
			.append(", ")
			.append(to_string(Age))
			.append(" years old");
		Sex == Male ? temp.append(", male") : temp.append(", female");
		return temp;
	}

	string Person::GetShortDescription()
	{
		string temp;
		temp.append(Name)
			.append(" ")
			.append(Surname);
		return temp;
	}

	bool Person::operator==(const Person& right)
	{
		return(Name == right.Name) 
			&& (Surname == right.Surname) 
			&& (Age == right.Age) 
			&& (Sex == right.Sex);
	}
	
	Person::Person(string name, string surname, unsigned int age, enum Sex sex)
	{
		SetName(name);
		SetSurname(surname);
		SetAge(age);
		SetSex(sex);
	}
	//TODO: Почему пустой? (нечего удалять)
	//TODO: Неверно. Сейчас класс испольузется при автоматическом заполнении, а правильнее его использовать
	//TODO: при пользовательском вводе, в котором будет работа с динамической памятью.
	//TODO: Отсутствие освобождения выделенной памяти - может привести к серъёзным проблемам.

	//В пользовательском вводе вроде тоже нечего удалять.(Он в PersonTools6)
	Person::~Person()
	{

	}

	std::ostream & operator<<(std::ostream & os, Person & p)
	{
		os << "Surname: " << p.Surname << std::endl;
		os << "Name: " << p.Name << std::endl;
		os << "Age: " << p.Age << std::endl;
		if (p.Sex == Male)
		{
			os << "Male" << endl;
		}
		else
		{
			os << "Female" << endl;
		}
		return os;
	}
}
