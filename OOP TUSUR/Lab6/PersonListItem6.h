#pragma once
#include "Person6.h"
namespace Lab6
{
	class PersonListItem
	{
		//TODO: ����� �� ���������� ����
		public:
			PersonListItem(Person *person)
			{
				Value = person;
			}
			//TODO: ������������?
			Person* Value;
			PersonListItem* Next = NULL;
			PersonListItem* Prev = NULL;
	};
}