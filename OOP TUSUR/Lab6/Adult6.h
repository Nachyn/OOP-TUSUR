#pragma once
#include "Person6.h"

namespace Lab6
{
	//TODO: Деструкторы во все классы!
	class Adult : public Person
	{
		public:
			Person * MarriedOn = NULL;
			//TODO: Почему не строка?
			char WorkPlace[100];
			virtual void SetAge(int age) override;
			virtual int GetAge() override;
			virtual string GetDescription() override;
			static Adult* GetRandomAdult();
	};
}