#pragma once
#include "../CheckSymbol.h"
#include "PersonListItem5.h"

namespace Lab5
{
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
			//TODO: Вообще получение рандомной персоны не должно тут храниться
			static Person GetRandomPerson();
			//TODO: Неправильное использование конструктора
			PersonList() { };
			//TODO: Где деструктор?
		private:
			//TODO: Некорректное именование
			PersonListItem * _Head;
			PersonListItem* _Tail;
			void ShowNodeInConsole(PersonListItem list, string message = "");
			bool ValidationName(char name[]);
	};
}