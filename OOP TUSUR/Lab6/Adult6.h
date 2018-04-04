#pragma once
#include "Person6.h"

namespace Lab6
{
	//TODO: Деструкторы во все классы!(+)
	class Adult : public Person
	{
		public:
			Person* MarriedOn = nullptr;
			//TODO: Почему не строка?(+)
			string WorkPlace;
			virtual bool SetAge(unsigned int age) override;
			virtual string GetDescription() override;
			Adult();
			~Adult();
	};
}