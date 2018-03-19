#pragma once
#include "../CheckSymbol.h"
#include "Node4.h"

namespace Lab4
{
	struct DoublyLinkedList
	{
		Node* Head = NULL;
		Node* Tail = NULL;
	};

	DoublyLinkedList AddEnd(DoublyLinkedList list, Person* person);
	void ShowInConsole(DoublyLinkedList list);
	Person* GetByIndex(DoublyLinkedList list, int index);
	DoublyLinkedList RemoveByIndex(DoublyLinkedList list, int index);
	DoublyLinkedList InsertByindex(DoublyLinkedList list, Person* person, int index);
	DoublyLinkedList Clear(DoublyLinkedList list);

	Person ReadPerson();
	Person MakeRandomPerson();
}