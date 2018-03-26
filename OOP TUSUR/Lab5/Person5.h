#pragma once
#include "../CheckSymbol.h"
#include "../Sex.h"

namespace Lab5
{
	class Person
	{
		public:
			//TODO: Насколько ваш код соответстует принципу ООП - инкапсуляция
			char Name[20];
			char Surname[20];
			int Age;
			Sex Sex;
			//TODO: Неправильно использование конструктора
			Person() { };
			bool operator==(const Person& right);
	};
}