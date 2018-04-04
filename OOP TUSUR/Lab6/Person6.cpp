#include "Person6.h"

namespace Lab6
{
	//TODO: Лучше uint(+)
	bool Person::SetAge(unsigned int age)
	{
		//BUG: Условие(+)
		if (age < 0 || age > 150)
		{
			return false;
		}
		Age = age;
		return true;
	}

	int Person::GetAge()
	{
		return Age;
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

	bool Person::operator==(const Person& right)
	{
		return(Name == right.Name) 
			&& (Surname == right.Surname) 
			&& (Age == right.Age) 
			&& (Sex == right.Sex);
	}

	Person::Person()
	{

	}

	Person::~Person()
	{

	}
}
