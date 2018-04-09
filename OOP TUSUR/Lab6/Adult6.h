#pragma once
#include "Person6.h"

namespace Lab6
{
	class Adult : public Person
	{
		public:
			Person* MarriedOn = nullptr;
			string WorkPlace;
			virtual void SetAge(unsigned int age) override;
			virtual string GetDescription() override;
			Adult(string name, string surname, unsigned int age, enum Sex sex);
			~Adult();
	};
}