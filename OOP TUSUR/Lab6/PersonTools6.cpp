#pragma once
#include "PersonTools6.h"

namespace Lab6
{
	Adult* PersonTools::GetRandomAdult()
	{
		string surnames[] = { "Holiday","Jacobson","James", "Allford", "Bawerman",
			"MacAdam", "Marlow", "Bosworth", "Neal","Conors",
			"Daniels", "Parson", "Quincy", "Richards", "Fane" };
		string names[] = { "Michael","Joshua","Matthew","Ethan","Andrew",
			"Alexander", "Tyler", "James", "John","Samuel",
			"Christian","Logan","Jose","Justin","Gabriel" };
		
		//TODO: Много магических чисел, лучше исправить(+)
		//TODO: Есть ниже дублирование.(+)
		string name = names[rand() % 15];
		string surname = surnames[rand() % 15];
		unsigned int age = rand() % 20 + 18;
		Sex sex;

		if (rand() % 2 == 0)
		{
			sex = Male;
		}
		else
		{
			sex = Female;
		}

		Adult* newPerson = new Adult(name, surname, age, sex);
		if (rand() % 2 == 0)
		{
			name = names[rand() % 15];
			surname = surnames[rand() % 15];
			age = rand() % 20 + 18;

			if (newPerson->GetSex() == Male)
			{
				sex = Female;
			}
			else
			{
				sex = Male;
			}
			Adult* spouse = new Adult(name, surname, age, sex);
			spouse->MarriedOn = newPerson;
			newPerson->MarriedOn = spouse;
		}

		if (rand() % 2 == 0)
		{
			newPerson->WorkPlace = "Microsoft";
		}
		return newPerson;
	}
}