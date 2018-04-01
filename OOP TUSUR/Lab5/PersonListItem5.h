#pragma once
#include "Person5.h"

namespace Lab5
{
	class PersonListItem
	{
		public:
			PersonListItem(Person* person)
			{
				_value = person;
			}
			Person* GetValue();
			PersonListItem* Next = nullptr;
			PersonListItem* Prev = nullptr;
		private:
			Person* _value = nullptr;
	};
}