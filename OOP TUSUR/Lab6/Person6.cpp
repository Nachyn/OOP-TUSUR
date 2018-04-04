#include "Person6.h"

namespace Lab6
{
	//TODO: Лучше uint
	void Person::SetAge(int age)
	{
		//BUG: Условие
		if (age < 0 && age < 150)
		{
			Age = 1;
		}
		else
		{
			Age = age;
		}
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
}
