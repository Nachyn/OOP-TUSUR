#pragma once
#include "../CheckSymbol.h"
#include "../Sex.h"

namespace Lab6
{
	//TODO: ������ ���� �������(?)
	//TODO: ����������� �� ��� ������!(+)
	class Person
	{
		private:
			int Age;
		public:
			//TODO: ������ �� ��������?(+)
			string Name;
			string Surname;
			Sex Sex;
			virtual bool SetAge(unsigned int age);
			virtual int GetAge();
			Person();
			~Person();
			virtual string GetDescription();
			bool operator==(const Person& right);
	};
}