#pragma once
#include "Person6.h"
namespace Lab6
{
	class PersonListItem
	{
		public:
			PersonListItem(Person* person)
			{
				Value = person;
			}
			Person* GetValue();
			PersonListItem* Next = nullptr;
			PersonListItem* Prev = nullptr;
		private:
			Person* Value = nullptr;
	};
}