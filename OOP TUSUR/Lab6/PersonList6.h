#pragma once
#include "../CheckSymbol.h"
#include "Adult6.h"
#include "Child6.h"
#include "PersonListItem6.h"

namespace Lab6
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
			PersonList();
			~PersonList();
			//TODO: Деструктор?(+)
		private:
			//TODO: именование не по RSDN(+)
			PersonListItem* _head = nullptr;
			PersonListItem* _tail = nullptr;
	};
}