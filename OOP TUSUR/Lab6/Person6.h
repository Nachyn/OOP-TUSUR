#pragma once
#include "../CheckSymbol.h"
#include "../Sex.h"

namespace Lab6
{
	//TODO: Должен быть базовым(?)
	//TODO: Деструкторы во все классы!(+)
	class Person
	{
		private:
			int Age;
		public:
			//TODO: Почему не строками?(+)
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