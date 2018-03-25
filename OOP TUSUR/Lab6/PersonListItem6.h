#pragma once
#include "Person6.h"
namespace Lab6
{
	class PersonListItem
	{
		public:
			PersonListItem(Person *person)
			{
				Value = person;
			}
			Person* Value;
			PersonListItem* Next = NULL;
			PersonListItem* Prev = NULL;
	};
}