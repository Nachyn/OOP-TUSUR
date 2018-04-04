#pragma once
#include "Person6.h"
namespace Lab6
{
	class PersonListItem
	{
		//TODO: ƒубль из предыдущей лабы
		public:
			PersonListItem(Person *person)
			{
				Value = person;
			}
			//TODO: »нкапсул€ци€?
			Person* Value;
			PersonListItem* Next = NULL;
			PersonListItem* Prev = NULL;
	};
}