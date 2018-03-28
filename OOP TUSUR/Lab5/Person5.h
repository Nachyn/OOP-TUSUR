#pragma once
#include "../CheckSymbol.h"
#include "../Sex.h"

namespace Lab5
{
	class Person
	{
		public:
			Person(char name[20], char surname[20], int age, Sex sex);
			bool SetName(char name[20]);
			bool SetSurname(char surname[20]);
			void SetAge(int age);
			void SetSex(Sex sex);
			char* GetName();
			char* GetSurname();
			int GetAge();
			Sex GetSex();
			bool operator==(const Person& right);
		private:
			char Name[20];
			char Surname[20];
			int Age;
			Sex Sex;
	};
}