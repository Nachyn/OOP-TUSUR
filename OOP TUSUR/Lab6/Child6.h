#pragma once
#include "Person6.h"

namespace Lab6
{
	//TODO: Деструкторы во все классы!
	class Child : public Person
	{
		public:
			Person * Mother;
			Person* Father;
			//TODO: Почему не строка
			char School[100];
			virtual void SetAge(int age) override;
			virtual int GetAge()override;
			virtual string GetDescription() override;
	};
}