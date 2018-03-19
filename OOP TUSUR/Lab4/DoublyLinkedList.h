#pragma once
#include "../CheckSymbol.h"

namespace Lab4
{
	enum Sex { Female, Male };

	struct Person
	{
		string Surname;
		string Name;
		Sex Sex;
	};

	struct Node
	{
		Person Data;
		Node* Next = NULL;
		Node* Prev = NULL;
	};

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