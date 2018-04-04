#pragma once
#include "../CheckSymbol.h"
#include "../Sex.h"

namespace Lab6
{
	//TODO: Должен быть базовым
	//TODO: Деструкторы во все классы!
	class Person
	{
		private:
			int Age;
		public:
			//TODO: Почему не строками?
			char Name[20];
			char Surname[20];
			Sex Sex;
			virtual void SetAge(int age);
			virtual int GetAge();
			Person() { };
			virtual string GetDescription();
			bool operator==(const Person& right);
	};
}