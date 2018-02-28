#include "DoublyLinkedList.h"

namespace Lab4
{
	DoublyLinkedList AddEnd(DoublyLinkedList list, Person * person)
	{
		Node* temp = new Node();
		temp->data = *person;

		if (list.head != NULL)
		{
			temp->prev = list.tail;
			list.tail->next = temp;
			list.tail = temp;
		}
		else
		{
			list.head = list.tail = temp;
		}

		return list;
	}

	void ShowInConsole(DoublyLinkedList list)
	{
		cout << endl;
		Node* temp = list.head;
		while (temp != NULL)
		{
			cout << "Surname: " << temp->data.Surname << endl;
			cout << "Name: " << temp->data.Name << endl;
			cout << "Sex: " << temp->data.SexPerson << endl << endl;
			temp = temp->next;
		}

		if (list.head != NULL)
		{
			cout << "-------------------------------------------------" << endl;
			cout << "head = " << "Surname: " << list.head->data.Surname << endl;
			cout << "head = " << "Name: " << list.head->data.Name << endl;
			cout << "head = " << "Sex: " << list.head->data.SexPerson << endl << endl;

			cout << "tail = " << "Surname: " << list.tail->data.Surname << endl;
			cout << "tail = " << "Name: " << list.tail->data.Name << endl;
			cout << "tail = " << "Sex: " << list.tail->data.SexPerson << endl << endl;
			cout << "-------------------------------------------------";
		}
		else
		{
			cout << "head = NULL " << " tail = NULL " << endl;
		}
	}

	Person * GetByIndex(DoublyLinkedList list, int index)
	{
		if (index < 0)
		{
			return NULL;
		}
		int i = 0;
		Node* temp = list.head;
		while (i < index)
		{
			if (temp == NULL)
			{
				return NULL;
			}
			temp = temp->next;
			i++;
		};
		return &temp->data;
	}

	DoublyLinkedList RemoveByIndex(DoublyLinkedList list, int index)
	{
		Person* element = GetByIndex(list, index);
		Node* temp = list.head;

		while (temp != NULL)
		{
			if (&temp->data == element)
			{
				if (list.head == temp)
				{
					if (temp->next == NULL)
					{
						list.head = NULL;
						list.tail = NULL;
						return list;
					}
					list.head->next->prev = NULL;
					list.head = list.head->next;
					return list;
				}

				if (list.tail == temp)
				{
					list.tail->prev->next = NULL;
					list.tail = list.tail->prev;
					return list;
				}

				if (list.head != temp && list.tail != temp)
				{
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					return list;
				}
			}
			temp = temp->next;
		}
		return list;
	}

	DoublyLinkedList InsertByindex(DoublyLinkedList list, Person * person, int index)
	{
		if (list.head == NULL || index < 0)
		{
			return list;
		}

		Node* temp = list.head;
		int i = 0;
		while (i < index)
		{
			if (temp == NULL)
			{
				return list;
			}
			temp = temp->next;
			i++;
		};

		if (temp == list.head)
		{
			Node* newNode = new Node();
			newNode->data = *person;

			list.head->prev = newNode;
			newNode->next = list.head;

			list.head = newNode;
			return list;
		}

		if (temp == list.tail)
		{
			Node* newNode = new Node();
			newNode->data = *person;
			list.tail->prev->next = newNode;
			newNode->prev = list.tail->prev;
			newNode->next = list.tail;
			list.tail->prev = newNode;
			list.tail->next = NULL;
			return list;
		}


		if (temp != NULL)
		{
			Node* newNode = new Node();
			newNode->data = *person;
			temp->prev->next = newNode;
			newNode->prev = temp->prev;
			newNode->next = temp;
			temp->prev = newNode;
		}
		return list;
	}

	DoublyLinkedList Clear(DoublyLinkedList list)
	{
		Node* next = list.head;
		while (next != NULL)
		{
			Node* tempNext = next->next;
			delete next;
			next = tempNext;
		}
		list.head = NULL;
		list.tail = NULL;
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
		int n;

		do
		{
			n = CheckSymbol();
		} while (n != 0 && n != 1);
		switch (n)
		{
		case Female:
			newPerson.SexPerson = Female;
			break;
		case Male:
			newPerson.SexPerson = Male;
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
		newPerson.SexPerson = Male;
		return newPerson;
	}
}

