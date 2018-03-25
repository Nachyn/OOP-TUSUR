#pragma once
#include "Person5.h"

namespace Lab5
{
	class PersonListItem
	{
	public:
		PersonListItem(Person person)
		{
			Value = person;
		}
		Person Value;
		PersonListItem* Next = NULL;
		PersonListItem* Prev = NULL;
	};
}