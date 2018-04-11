#include "Child6.h"

namespace Lab6
{
	void Child::SetAge(unsigned int age)
	{
		if (age > 17)
		{
			throw new exception("Incorrect age. Need children");
		}
		Person::SetAge(age);
	}

	string Child::GetDescription()
	{
		string temp = Person::GetDescription();
		if (Mother != nullptr && Father != nullptr)
		{
			temp.append(", parents are ")
				.append(Mother->GetShortDescription())
				.append(" and ")
				.append(Father->GetShortDescription());
		}
		else if (Mother != NULL)
		{
			temp.append(", mother is ")
				.append(Mother->GetShortDescription());
		}
		else if (Father != NULL)
		{
			temp.append(", father is ")
				.append(Father->GetShortDescription());
		}
		else
		{
			temp.append(", parents are not specified");
		}

		if (School.length() > 0)
		{
			temp.append(", ")
				.append(School);
		}
		else
		{
			temp.append(", does not go to school");
		}
		return temp;
	}

	Child::Child(string name, string surname, unsigned int age, enum Sex sex) : Person(name, surname, age, sex)
	{

	}

	Child::~Child()
	{
		if (Mother != nullptr)
		{
			delete Mother;
		}
		if (Father != nullptr)
		{
			delete Father;
		}
	}
}
