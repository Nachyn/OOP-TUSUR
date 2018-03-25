#include "FunctionsDoublyLinkedList.h"

namespace Lab4
{
	DoublyLinkedList AddEnd(DoublyLinkedList list, Person * person)
	{
		Node* temp = new Node();
		temp->Data = *person;

		if (list.Head != NULL)
		{
			temp->Prev = list.Tail;
			list.Tail->Next = temp;
			list.Tail = temp;
		}
		else
		{
			list.Head = list.Tail = temp;
		}

		return list;
	}

	void ShowNodeInConsole(Node& node, string message)
	{
		cout << message << " Surname: " << node.Data.Surname << endl;
		cout << message << " Name: " << node.Data.Name << endl;
		cout << message << " Sex: " << node.Data.Sex << endl << endl;
	}



	void ShowInConsole(DoublyLinkedList list)
	{
		cout << endl;
		Node* temp = list.Head;
		while (temp != NULL)
		{
			ShowNodeInConsole(*temp);
			temp = temp->Next;
		}

		if (list.Head != NULL)
		{
			cout << "-------------------------------------------------" << endl;
			ShowNodeInConsole(*list.Head, "Head =");
			ShowNodeInConsole(*list.Tail, "Tail =");
			cout << "-------------------------------------------------";
		}
		else
		{
			cout << "Head = NULL " << " Tail = NULL " << endl;
		}
	}

	Person* GetByIndex(DoublyLinkedList list, int index)
	{
		if (index < 0)
		{
			return NULL;
		}
		int i = 0;
		Node* temp = list.Head;
		while (i < index)
		{
			if (temp == NULL)
			{
				return NULL;
			}
			temp = temp->Next;
			i++;
		};
		return &temp->Data;
	}

	DoublyLinkedList RemoveByIndex(DoublyLinkedList list, int index)
	{
		Person* element = GetByIndex(list, index);
		Node* temp = list.Head;

		while (temp != NULL)
		{
			if (&temp->Data == element)
			{
				if (list.Head == temp)
				{
					if (temp->Next == NULL)
					{
						list.Head = NULL;
						list.Tail = NULL;
						return list;
					}
					list.Head->Next->Prev = NULL;
					list.Head = list.Head->Next;
					return list;
				}

				if (list.Tail == temp)
				{
					list.Tail->Prev->Next = NULL;
					list.Tail = list.Tail->Prev;
					return list;
				}

				if (list.Head != temp && list.Tail != temp)
				{
					temp->Prev->Next = temp->Next;
					temp->Next->Prev = temp->Prev;
					return list;
				}
			}
			temp = temp->Next;
		}
		return list;
	}

	DoublyLinkedList InsertByindex(DoublyLinkedList list, Person * person, int index)
	{
		if (list.Head == NULL || index < 0)
		{
			return list;
		}

		Node* temp = list.Head;
		int i = 0;
		while (i < index)
		{
			if (temp == NULL)
			{
				return list;
			}
			temp = temp->Next;
			i++;
		};

		if (temp == list.Head)
		{
			Node* newNode = new Node();
			newNode->Data = *person;

			list.Head->Prev = newNode;
			newNode->Next = list.Head;

			list.Head = newNode;
			return list;
		}

		if (temp == list.Tail)
		{
			Node* newNode = new Node();
			newNode->Data = *person;
			list.Tail->Prev->Next = newNode;
			newNode->Prev = list.Tail->Prev;
			newNode->Next = list.Tail;
			list.Tail->Prev = newNode;
			list.Tail->Next = NULL;
			return list;
		}


		if (temp != NULL)
		{
			Node* newNode = new Node();
			newNode->Data = *person;
			temp->Prev->Next = newNode;
			newNode->Prev = temp->Prev;
			newNode->Next = temp;
			temp->Prev = newNode;
		}
		return list;
	}

	DoublyLinkedList Clear(DoublyLinkedList list)
	{
		Node* next = list.Head;
		while (next != NULL)
		{
			Node* tempNext = next->Next;
			delete next;
			next = tempNext;
		}
		list.Head = NULL;
		list.Tail = NULL;
		return list;
	}

	Person ReadPerson()
	{
		Person newPerson;
		cout << "Insert Surname: ";
		cin >> newPerson.Surname;
		cout << endl << "Insert Name: ";
		cin >> newPerson.Name;
		cout << endl << "Insert Sex: ";
		int sex;

		do
		{
			sex = CheckSymbol();
		} 
		while (sex != 0 && sex != 1);
		
		switch (sex)
		{
			case Female:
				newPerson.Sex = Female;
				break;
			case Male:
				newPerson.Sex = Male;
				break;
			default:
				break;
		}
		return newPerson;
	}

	Person MakeRandomPerson()
	{
		string surnames[] = { "Holiday","Jacobson","James", "Allford", "Bawerman",
			"MacAdam", "Marlow", "Bosworth", "Neal","Conors",
			"Daniels", "Parson", "Quincy", "Richards", "Fane" };
		string names[] = { "Michael","Joshua","Matthew","Ethan","Andrew",
			"Alexander", "Tyler", "James", "John","Samuel",
			"Christian","Logan","Jose","Justin","Gabriel" };
		int surname = rand() % 15;
		int name = rand() % 15;
		Person newPerson;
		newPerson.Name = names[name];
		newPerson.Surname = surnames[surname];
		newPerson.Sex = Male;
		return newPerson;
	}
}

