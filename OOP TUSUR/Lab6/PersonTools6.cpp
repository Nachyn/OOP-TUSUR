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
		Adult* newPerson = new Adult();
		newPerson->Name = names[rand() % 15];
		newPerson->Surname = surnames[rand() % 15];
		newPerson->SetAge(rand() % 20 + 18);
		rand() % 2 == 0 ? newPerson->Sex = Male : newPerson->Sex = Female;
		if (rand() % 2 == 0)
		{
			Adult* spouse = new Adult();
			spouse->Name = names[rand() % 15];
			spouse->Surname = surnames[rand() % 15];
			spouse->SetAge(rand() % 20 + 18);
			newPerson->Sex == Male ? spouse->Sex = Female : spouse->Sex = Male;
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