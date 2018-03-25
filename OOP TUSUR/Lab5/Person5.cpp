#include "Person5.h"

namespace Lab5
{
	bool Person::operator==(const Person& right)
	{
		return(!strcmp(Name, right.Name) &&
			!strcmp(Surname, right.Surname) &&
			Age == right.Age && Sex == right.Sex);
	}
}