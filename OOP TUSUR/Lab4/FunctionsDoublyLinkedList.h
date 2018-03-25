#pragma once
#include "../CheckSymbol.h"
#include "DoublyLinkedList.h"

namespace Lab4
{
	DoublyLinkedList AddEnd(DoublyLinkedList list, Person* person);
	void ShowNodeInConsole(Node& node, string message = "");
	void ShowInConsole(DoublyLinkedList list);
	Person* GetByIndex(DoublyLinkedList list, int index);
	DoublyLinkedList RemoveByIndex(DoublyLinkedList list, int index);
	DoublyLinkedList InsertByindex(DoublyLinkedList list, Person* person, int index);
	DoublyLinkedList Clear(DoublyLinkedList list);

	Person ReadPerson();
	Person MakeRandomPerson();
}