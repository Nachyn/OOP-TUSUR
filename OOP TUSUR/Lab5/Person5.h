#pragma once
#include "../CheckSymbol.h"
#include "../Sex.h"

namespace Lab5
{
	class Person
	{
		public:
			char Name[20];
			char Surname[20];
			int Age;
			Sex Sex;
			Person() { };
			bool operator==(const Person& right);
	};
}