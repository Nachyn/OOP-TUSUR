#include "Adult6.h"
namespace Lab6
{
	void Adult::SetAge(int age)
	{
		//TODO: ������� ���������. ������ �� �� ����� ������������� �������� 
		//��� ����� �������� � ������������ ������?
		if (age < 18)
		{
			Person::SetAge(18);
		}
		else
		{
			Person::SetAge(age);
		}
	}

	int Adult::GetAge()
	{
		return Person::GetAge();
	}

	string Adult::GetDescription()
	{
		string temp = Person::GetDescription();
		if (strlen(WorkPlace) == 0)
		{
			temp.append(", unemployed");
		}
		else
		{
			temp.append(", ").append(WorkPlace);
		}
		if (MarriedOn != NULL)
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

	Adult* Adult::GetRandomAdult()
	{
		string surnames[] = { "Holiday","Jacobson","James", "Allford", "Bawerman",
			"MacAdam", "Marlow", "Bosworth", "Neal","Conors",
			"Daniels", "Parson", "Quincy", "Richards", "Fane" };
		string names[] = { "Michael","Joshua","Matthew","Ethan","Andrew",
			"Alexander", "Tyler", "James", "John","Samuel",
			"Christian","Logan","Jose","Justin","Gabriel" };
		int surname = rand() % 15;
		int name = rand() % 15;
		Adult* newPerson = new Adult();
		for (int i = 0; i <= strlen(names[name].c_str()); i++)
		{
			newPerson->Name[i] = names[name][i];
		}
		for (int i = 0; i <= strlen(surnames[surname].c_str()); i++)
		{
			newPerson->Surname[i] = surnames[surname][i];
		}
		newPerson->SetAge(rand() % 20 + 18);
		rand() % 2 == 0 ? newPerson->Sex = Male : newPerson->Sex = Female;
		if (rand() % 2 == 0)
		{
			Adult* spouse = new Adult();
			int surname = rand() % 15;
			int name = rand() % 15;
			for (int i = 0; i < strlen(names[name].c_str()); i++)
			{
				spouse->Name[i] = names[name][i];
			}
			for (int i = 0; i < strlen(surnames[surname].c_str()); i++)
			{
				spouse->Surname[i] = surnames[surname][i];
			}
			spouse->SetAge(rand() % 20 + 18);
			newPerson->Sex == Male ? spouse->Sex = Female : spouse->Sex = Male;
			spouse->MarriedOn = (Person*)newPerson;
			newPerson->MarriedOn = spouse;
		}
		if (rand() % 2 == 0)
		{
			newPerson->WorkPlace[0] = 'Z';
			newPerson->WorkPlace[1] = '-';
			newPerson->WorkPlace[2] = 'C';
			newPerson->WorkPlace[3] = 'o';
			newPerson->WorkPlace[4] = 'm';
			newPerson->WorkPlace[5] = 'p';
			newPerson->WorkPlace[6] = '\0';
		}
		return newPerson;
	}
}