#pragma once
#include "Person5.h"

namespace Lab5
{
	class PersonListItem
	{
		public:
			PersonListItem(Person* person)
			{
				Value = person;
			}
			//TODO: Нужно Value публично?(+) 
			Person* GetValue();
			PersonListItem* Next = NULL;
			PersonListItem* Prev = NULL;
		private:
			Person* Value = NULL;
	};
}