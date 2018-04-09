#include "Child6.h"

namespace Lab6
{
	bool Child::SetAge(unsigned int age)
	{
		if (age > 17)
		{
			return false;
		}
		return Person::SetAge(age);
	}

	string Child::GetDescription()
	{
		string temp = Person::GetDescription();
		if (Mother != nullptr && Father != nullptr)
		{//TODO: Ниже четыре дубля.(?)
			temp.append(", parents are ")
				.append(Mother->Name)
				.append(" ")
				.append(Mother->Surname)
				.append(" and ")
				.append(Father->Name)
				.append(" ")
				.append(Father->Surname);
		}
		else if (Mother != NULL)
		{
			temp.append(", mother is ")
				.append(Mother->Name)
				.append(" ")
				.append(Mother->Surname);
		}
		else if (Father != NULL)
		{
			temp.append(", father is ")
				.append(Father->Name)
				.append(" ")
				.append(Father->Surname);
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

	Child::Child()
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
