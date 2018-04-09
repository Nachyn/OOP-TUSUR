#include "Person6.h"

namespace Lab6
{
	bool Person::SetAge(unsigned int age)
	{
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
	//TODO: Почему пустой?
	Person::Person()
	{

	}
	//TODO: Почему пустой?
	Person::~Person()
	{

	}
}
