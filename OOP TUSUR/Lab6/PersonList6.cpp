#pragma once
#include "PersonList6.h"

namespace Lab6
{
	void PersonList::Add(Person * person)
	{
		PersonListItem* temp = new PersonListItem(person);
		if (_head != NULL)
		{
			temp->Prev = _tail;
			_tail->Next = temp;
			_tail = temp;
		}
		else
		{
			_head = _tail = temp;
		}
	}

	Person* PersonList::Find(int index)
	{
		if (index < 0)
		{
			return NULL;
		}
		int i = 0;
		PersonListItem* temp = _head;
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
		PersonListItem* temp = _head;
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
		PersonListItem* temp = _head;
		while (temp != NULL)
		{
			if (temp->Value == person)
			{
				if (_head == temp)
				{
					if (temp->Next == NULL)
					{
						_head = NULL;
						_tail = NULL;
						break;
					}
					_head->Next->Prev = NULL;
					_head = _head->Next;
					break;
				}

				if (_tail == temp)
				{
					_tail->Prev->Next = NULL;
					_tail = _tail->Prev;
					break;
				}

				if (_head != temp && _tail != temp)
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
		PersonListItem* temp = _head;
		while (temp != NULL)
		{
			if (temp->Value == person)
			{
				if (_head == temp)
				{
					if (temp->Next == NULL)
					{
						_head = NULL;
						_tail = NULL;
						break;
					}
					_head->Next->Prev = NULL;
					_head = _head->Next;
					break;
				}

				if (_tail == temp)
				{
					_tail->Prev->Next = NULL;
					_tail = _tail->Prev;
					break;
				}

				if (_head != temp && _tail != temp)
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
		PersonListItem* next = _head;
		while (next != NULL)
		{
			PersonListItem* tempNext = next->Next;
			delete next->Value;
			delete next;
			next = tempNext;
		}
		_head = NULL;
		_tail = NULL;
	}

	int PersonList::GetCount()
	{
		int count = 0;
		PersonListItem* temp = _head;
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
		PersonListItem* temp = _head;
		while (temp != NULL)
		{
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

		if (_head != NULL)
		{
			cout << "-------------------------------------------------" << endl;
			cout << "Head = " << _head->Value->GetDescription() << endl;
			cout << "Tail = " << _tail->Value->GetDescription() << endl;
			cout << "-------------------------------------------------" << endl;
		}
		else
		{
			cout << "Head = NULL " << " Tail = NULL " << endl;
		}
	}
}