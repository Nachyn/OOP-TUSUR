#pragma once
#include "PersonList6.h"

namespace Lab6
{
	void PersonList::Add(Person * person)
	{
		PersonListItem* temp = new PersonListItem(person);
		if (_Head != NULL)
		{
			temp->Prev = _Tail;
			_Tail->Next = temp;
			_Tail = temp;
		}
		else
		{
			_Head = _Tail = temp;
		}
	}

	Person* PersonList::Find(int index)
	{
		if (index < 0)
		{
			return NULL;
		}
		int i = 0;
		PersonListItem* temp = _Head;
		while (i < index)
		{
			if (temp == NULL)
			{
				return NULL;
			}
			temp = temp->Next;
			i++;
		};
		return temp->Value;
	}

	int PersonList::IndexOf(Person * person)
	{
		PersonListItem* temp = _Head;
		int index = 0;
		while (temp != NULL)
		{
			if (temp->Value == person)
			{
				return index;
			}
			index++;
			temp = temp->Next;
		}
		return -1;
	}

	void PersonList::Remove(Person * person)
	{
		PersonListItem* temp = _Head;
		while (temp != NULL)
		{
			if (temp->Value == person)
			{
				if (_Head == temp)
				{
					if (temp->Next == NULL)
					{
						_Head = NULL;
						_Tail = NULL;
						break;
					}
					_Head->Next->Prev = NULL;
					_Head = _Head->Next;
					break;
				}

				if (_Tail == temp)
				{
					_Tail->Prev->Next = NULL;
					_Tail = _Tail->Prev;
					break;
				}

				if (_Head != temp && _Tail != temp)
				{
					temp->Prev->Next = temp->Next;
					temp->Next->Prev = temp->Prev;
					break;
				}
			}
			temp = temp->Next;
		}
	}

	void PersonList::RemoveAt(int index)
	{
		Person* person = Find(index);
		PersonListItem* temp = _Head;
		while (temp != NULL)
		{
			if (temp->Value == person)
			{
				if (_Head == temp)
				{
					if (temp->Next == NULL)
					{
						_Head = NULL;
						_Tail = NULL;
						break;
					}
					_Head->Next->Prev = NULL;
					_Head = _Head->Next;
					break;
				}

				if (_Tail == temp)
				{
					_Tail->Prev->Next = NULL;
					_Tail = _Tail->Prev;
					break;
				}

				if (_Head != temp && _Tail != temp)
				{
					temp->Prev->Next = temp->Next;
					temp->Next->Prev = temp->Prev;
					break;
				}
			}
			temp = temp->Next;
		}
	}

	void PersonList::Clear()
	{
		PersonListItem* next = _Head;
		while (next != NULL)
		{
			PersonListItem* tempNext = next->Next;
			delete next->Value;
			delete next;
			next = tempNext;
		}
		_Head = NULL;
		_Tail = NULL;
	}

	int PersonList::GetCount()
	{
		int count = 0;
		PersonListItem* temp = _Head;
		while (temp != NULL)
		{
			temp = temp->Next;
			count++;
		}
		return count;
	}

	void PersonList::ShowInConsole()
	{
		cout << endl;
		PersonListItem* temp = _Head;
		while (temp != NULL)
		{//TODO: ѕолучаетс€, что список знает и то, что в нЄм хранитс€ - это не правильно.
			//“аким образом нарушаетс€ принцип "единственной об€занности" класса.
			if (temp->Value->GetAge() < 18)
			{
				cout << "This is a child: ";
				cout << temp->Value->GetDescription() << endl;
			}
			else
			{
				cout << "This is a Adilt: ";
				cout << temp->Value->GetDescription() << endl;
			}
			temp = temp->Next;
		}

		if (_Head != NULL)
		{
			cout << "-------------------------------------------------" << endl;
			cout << "Head = " << _Head->Value->GetDescription() << endl;
			cout << "Tail = " << _Tail->Value->GetDescription() << endl;
			cout << "-------------------------------------------------" << endl;
		}
		else
		{
			cout << "Head = NULL " << " Tail = NULL " << endl;
		}
	}
}