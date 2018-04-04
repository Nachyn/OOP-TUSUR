#include "Child6.h"

namespace Lab6
{
	void Child::SetAge(int age)
	{
		//TODO: ������� ���������. ������ �� �� ����� ������������� �������� 
		//��� ����� �������� � ������������ ������?
		if (age > 17)
		{
			Person::SetAge(10);
		}
		else
		{
			Person::SetAge(age);
		}

	}
	//TODO: ����� �����������, ���� ��� ������ ����� ��������?
	int Child::GetAge()
	{
		return Person::GetAge();
	}

	string Child::GetDescription()
	{
		string temp = Person::GetDescription();
		if (Mother != NULL && Father != NULL)
		{//TODO: ���� ������ �����.
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

		if (strlen(School) != 0)
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
}
