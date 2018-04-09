#pragma once
#include "../CheckSymbol.h"
#include "../Sex.h"

namespace Lab6
{
	class Person
	{
		private:
			unsigned int Age;
			string Name;
			string Surname;
			Sex Sex;
		public:
			//TODO: Нарушение инкапсуляции, публичные поля. (+)
			void SetName(string name);
			void SetSurname(string surname);
			void SetSex(enum Sex sex);
			virtual void SetAge(unsigned int age);
			
			enum Sex GetSex();
			virtual string GetDescription();
			string GetShortDescription();
			bool operator==(const Person& right);
			Person(string name, string surname, unsigned int age, enum Sex sex);
			~Person();

			Person() { }; //Для 7й лабы.
			friend std::ostream& operator<<(std::ostream& os, Person& p) //Для 7й лабы.
			{
				os << "Surname: " << p.Surname << std::endl;
				os << "Name: " << p.Name << std::endl;
				os << "Age: " << p.Age << std::endl;
				if (p.Sex == Male)
				{
					os << "Male" << endl;
				}
				else
				{
					os << "Female" << endl;
				}
				return os;
			}
	};
}