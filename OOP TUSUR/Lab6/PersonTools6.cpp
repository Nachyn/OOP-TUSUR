#pragma once
#include "PersonTools6.h"
#include "../Lab7/TemplateList.h"

namespace Lab6
{
	Adult* PersonTools::GetRandomAdult()
	{	
		Adult* adult = GetSingleAdult();
		Adult* spouse = GetSingleAdult();
		spouse->MarriedOn = adult;
		adult->MarriedOn = spouse;

		return adult;
	}

	Adult* PersonTools::GetSingleAdult()
	{
		string surnames[] = { "Holiday","Jacobson","James", "Allford", "Bawerman",
			"MacAdam", "Marlow", "Bosworth", "Neal","Conors",
			"Daniels", "Parson", "Quincy", "Richards", "Fane" };
		string names[] = { "Michael","Joshua","Matthew","Ethan","Andrew",
			"Alexander", "Tyler", "James", "John","Samuel",
			"Christian","Logan","Jose","Justin","Gabriel" };

		int randomName = rand() % 15;
		int randomSurname = rand() % 15;
		int randomAge = rand() % 20 + 18;

		string name = names[randomName];
		string surname = surnames[randomSurname];
		unsigned int age = randomAge;
		Sex sex = Male;

		if (rand() % 2 == 0)
		{
			sex = Female;
		}
		Adult* newAdult = new Adult(name, surname, age, sex);
		if (rand() % 2 == 0)
		{
			newAdult->WorkPlace = "Microsoft";
		}
		return newAdult;
	}

	bool PersonTools::CheckName(string name)
	{
		bool validate = true;
		for (int i = 0; i < name.length(); i++)
		{
			if (isdigit(name[i]) || isspace(name[i]))
			{
				validate = false;
				break;
			}
			if (name[i] == '-')
			{
				if (isalpha(name[i + 1]))
				{
					name[i + 1] = toupper(name[i + 1]);
				}
				else
				{
					validate = false;
					break;
				}
			}
		}
		name[0] = toupper(name[0]);
		return validate;
	}

	Person* PersonTools::GetCreatePerson()
	{
		string name;
		string surname;
		enum Sex sex;

		bool key = true;
		while (key)
		{
			cout << endl << "Insert Surname: ";
			cin >> surname;
			key = !CheckName(surname);
		}

		key = true;
		while (key)
		{
			cout << endl << "Insert Name: ";
			cin >> name;
			key = !CheckName(name);
		}

		cout << endl << "Insert Age: ";
		int age;
		do
		{
			age = CheckSymbol();
		} 
		while (age < 0 || age > 150);

		cout << endl << "Insert Sex(1-Male | 0-Female): ";
		int personSex;
		do
		{
			personSex = CheckSymbol();
		} 
		while (personSex != 0 && personSex != 1);

		switch (personSex)
		{
			case Female:
				sex = Female;
				break;
			case Male:
				sex = Male;
				break;
			default:
				break;
		}
		return new Person(name, surname, age, sex);
	}
}