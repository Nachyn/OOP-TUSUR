#pragma once
#include "Adult6.h"
namespace Lab6
{
	class PersonTools
	{
		public:
			static Adult* GetRandomAdult();
			static Adult* GetSingleAdult();
			static Person* GetCreatePerson();
		private:
			static bool CheckName(string name);
	};
}