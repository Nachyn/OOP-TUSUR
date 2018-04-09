#pragma once
#include "PersonList6.h"

namespace Lab6
{
	void PersonList::Add(Person * person)
	{
		PersonListItem* temp = new PersonListItem(person);
		if (_head != nullptr)
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
			return nullptr;
		}
		int i = 0;
		PersonListItem* temp = _head;
		while (i < index)
		{
			if (temp == nullptr)
			{
				return nullptr;
			}
			temp = temp->Next;
			i++;
		};
		return temp->GetValue();
	}

	int PersonList::IndexOf(Person* person)
	{
		PersonListItem* temp = _head;
		int index = 0;
		while (temp != nullptr)
		{
			if (temp->GetValue() == person)
			{
				return index;
			}
			index++;
			temp = temp->Next;
		}
		return -1;
	}

	void PersonList::Remove(Person* person)
	{
		PersonListItem* temp = _head;
		while (temp != nullptr)
		{
			if (temp->GetValue() == person)
			{
				if (_head == temp)
				{
					if (temp->Next == nullptr)
					{
						_head = nullptr;
						_tail = nullptr;
						break;
					}
					_head->Next->Prev = nullptr;
					_head = _head->Next;
					break;
				}

				if (_tail == temp)
				{
					_tail->Prev->Next = nullptr;
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
		while (temp != nullptr)
		{
			if (temp->GetValue() == person)
			{
				if (_head == temp)
				{
					if (temp->Next == nullptr)
					{
						_head = nullptr;
						_tail = nullptr;
						break;
					}
					_head->Next->Prev = nullptr;
					_head = _head->Next;
					break;
				}

				if (_tail == temp)
				{
					_tail->Prev->Next = nullptr;
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
		while (next != nullptr)
		{
			PersonListItem* tempNext = next->Next;
			delete next->GetValue();
			delete next;
			next = tempNext;
		}
		_head = nullptr;
		_tail = nullptr;
	}

	int PersonList::GetCount()
	{
		int count = 0;
		PersonListItem* temp = _head;
		while (temp != nullptr)
		{
			temp = temp->Next;
			count++;
		}
		return count;
	}

	string PersonList::GetItemsInfo()
	{
		string info;
		PersonListItem* temp = _head;
		while (temp != nullptr)
		{   //TODO: ������� ������������ ��������������� �� ����� ����������, � ��������� ������ ����(+)
			//TODO: � ���������� �����(+)
			info.append(temp->GetValue()->GetDescription()).append("\n");
			temp = temp->Next;
		}

		if (_head != nullptr)
		{
			info.append("Head = ").append(_head->GetValue()->GetDescription()).append("\n");
			info.append("Tail = ").append(_tail->GetValue()->GetDescription()).append("\n");
		}
		else
		{
			info.append("Head = NULL Tail = NULL");
		}
		return info;
	}

	PersonList::PersonList()
	{

	}

	PersonList::~PersonList()
	{
		Clear();
	}
}