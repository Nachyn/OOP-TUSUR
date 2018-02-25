#pragma once
#include "../CheckSymbol.h"

namespace Lab4
{
	enum Sex { Female, Male };

	struct Person
	{
		string Surname;
		string Name;
		Sex SexPerson;
	};

	struct Node
	{
		Person data;
		Node* next = NULL;
		Node* prev = NULL;
	};

	struct DoublyLinkedList
	{
		Node* head = NULL;
		Node* tail = NULL;
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