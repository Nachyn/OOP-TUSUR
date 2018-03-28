#pragma once
#include "../CheckSymbol.h"
#include "PersonListItem5.h"

namespace Lab5
{
	class PersonList
	{
		public:
			void Add(Person* person);
			Person* Find(int index);
			int IndexOf(Person* person);
			void Remove(Person* person);
			void RemoveAt(int index);
			void Clear();
			int GetCount();
			void ShowInConsole();
			void Read();
			//TODO: Вообще получение рандомной персоны не должно тут храниться (+ в задании);
			//6. Создайте в классе Person статический метод GetRandomPerson().
			//TODO: По заданию - всё верно. Я говорю про смысловую часть ООП декомпозиции.
			static Person* GetRandomPerson();
			PersonList();
			PersonList(int count, Person* first, ...);
			~PersonList();
		private:
			PersonListItem* _head;
			PersonListItem* _tail;
			void _showNodeInConsole(PersonListItem list, string message = "");
			bool _checkName(char name[]);
	};
}