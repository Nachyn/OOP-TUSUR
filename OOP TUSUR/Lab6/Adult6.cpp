#include "Adult6.h"
namespace Lab6
{
	void Adult::SetAge(unsigned int age)
	{
		if (age < 18)
		{
			throw new exception("Incorrect age. Need +18");
		}
		Person::SetAge(age);
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
				.append(MarriedOn->GetShortDescription());
		}
		else
		{
			temp.append(", single");
		}
		return temp;
	}

	Adult::Adult(string name, string surname, unsigned int age, enum Sex sex) : Person(name, surname, age, sex)
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