#pragma once
#include "../CheckSymbol.h"

namespace Lab5
{
	enum Sex { Female, Male };

	class Person
	{
	public:
		char Name[20];
		char Surname[20];
		int Age;
		Sex Sex;
		Person() { };
		bool operator==(const Person& right)
		{
			return(!strcmp(Name, right.Name) &&
				!strcmp(Surname, right.Surname) &&
				Age == right.Age && Sex == right.Sex) ? true : false;
		}
	};

	class PersonListItem
	{
	public:
		PersonListItem(Person person)
		{
			Value = person;
		}
		Person Value;
		PersonListItem* Next = NULL;
		PersonListItem* Prev = NULL;
	};

	class PersonList
	{
	public:
		void Add(Person * person);
		Person* Find(int index);
		int IndexOf(Person * person);
		void Remove(Person * person);
		void RemoveAt(int index);
		void Clear();
		int GetCount();
		void ShowInConsole();
		void Read();
		static Person GetRandomPerson();
		PersonList() { };
	private:
		PersonListItem * _head;
		PersonListItem* _tail;
		int _count;
	};
}