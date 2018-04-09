#pragma once
#include "../CheckSymbol.h"
#include "../Sex.h"

namespace Lab6
{
	class Person
	{
		private:
			int Age;
		public:
			//TODO: Нарушение инкапсуляции, публичные поля.
			string Name;
			string Surname;
			Sex Sex;
			virtual bool SetAge(unsigned int age);
			virtual int GetAge();
			Person();
			~Person();
			virtual string GetDescription();
			string GetShortDescription();
			bool operator==(const Person& right);
	};
}