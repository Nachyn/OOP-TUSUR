#pragma once
#include "../CheckSymbol.h"
#include "../Sex.h"

namespace Lab6
{
	//TODO: ������ ���� �������
	//TODO: ����������� �� ��� ������!
	class Person
	{
		private:
			int Age;
		public:
			//TODO: ������ �� ��������?
			char Name[20];
			char Surname[20];
			Sex Sex;
			virtual void SetAge(int age);
			virtual int GetAge();
			Person() { };
			virtual string GetDescription();
			bool operator==(const Person& right);
	};
}