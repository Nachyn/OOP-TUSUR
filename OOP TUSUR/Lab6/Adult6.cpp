#include "Adult6.h"
namespace Lab6
{
	bool Adult::SetAge(unsigned int age)
	{
		if (age < 18)
		{
			return false;
		}
		return Person::SetAge(age);
	}

	string Adult::GetDescription()
	{
		string temp = Person::GetDescription();
		if (WorkPlace.length() < 1)
		{
			temp.append(", unemployed");
		}
		else
		{
			temp.append(", ").append(WorkPlace);
		}
		if (MarriedOn != nullptr)
		{
			temp.append(", married on ")
				.append(MarriedOn->Name)
				.append(" ")
				.append(MarriedOn->Surname);
		}
		else
		{
			temp.append(", single");
		}
		return temp;
	}

	Adult::Adult()
	{

	}

	Adult::~Adult()
	{
		if (MarriedOn != nullptr)
		{
			delete MarriedOn;
		}
	}
}