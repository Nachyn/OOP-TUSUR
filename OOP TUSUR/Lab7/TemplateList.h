#pragma once
#include "../CheckSymbol.h"

namespace Lab7
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
		friend std::ostream& operator<<(std::ostream& os, Person& p)
		{
			os << "Surname: " << p.Surname << std::endl;
			os << "Name: " << p.Name << std::endl;
			os << "Age: " << p.Age << std::endl;
			os << "Sex: " << p.Sex << std::endl;
			return os;
		}
		bool operator==(const Person& right)
		{
			return(!strcmp(Name, right.Name) &&
				!strcmp(Surname, right.Surname) &&
				Age == right.Age && Sex == right.Sex) ? true : false;
		}
	};

	template <class T>
	class TemplateListItem
	{
	public:
		TemplateListItem(T person)
		{
			Value = person;
		}
		T Value;
		TemplateListItem* Next = NULL;
		TemplateListItem* Prev = NULL;

		bool operator==(const TemplateListItem& right)
		{
			return Value == right.Value ? true : false;
		}
	};

	template <class T>
	class TemplateList
	{
	public:
		friend std::ostream& operator<<(std::ostream& os, TemplateList& list)
		{
			TemplateListItem<T>* temp = list._head;
			cout << "Подсписок: ";
			while (temp != NULL)
			{
				cout << temp->Value << "  ";
				temp = temp->Next;
			}
			return os;
		}
		bool operator==(const TemplateList& right);
		void Add(T element);
		void InsertByIndex(T element, int index);
		T* Find(int index);
		int IndexOf(T element);
		void Remove(T element);
		void RemoveAt(int index);
		void Clear();
		int GetCount();
		void ShowInConsole();
		static Person GetRandomPerson();
		TemplateList() { }
	private:
		TemplateListItem<T> * _head;
		TemplateListItem<T>* _tail;
		int _count;
	};
}