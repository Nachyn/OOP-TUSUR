#pragma once
#include "Person6.h"

namespace Lab6
{
	//TODO: Деструкторы во все классы!(+)
	class Child : public Person
	{
		public:
			Person* Mother;
			Person* Father;
			//TODO: Почему не строка(+)
			string School;
			virtual bool SetAge(unsigned int age) override;
			virtual string GetDescription() override;
			Child();
			~Child();
	};
}