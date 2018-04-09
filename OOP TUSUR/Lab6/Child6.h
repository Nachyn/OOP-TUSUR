#pragma once
#include "Person6.h"

namespace Lab6
{
	class Child : public Person
	{
		public:
			Person* Mother;
			Person* Father;
			string School;
			virtual void SetAge(unsigned int age) override;
			virtual string GetDescription() override;
			Child(string name, string surname, unsigned int age, enum Sex sex);
			~Child();
	};
}