#include "PersonList.h"

namespace Lab5
{
	void PersonList::Add(Person * person)
	{
		PersonListItem* temp = new PersonListItem(*person);
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

	Person * PersonList::Find(int index)
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
		return &temp->Value;
	}

	int PersonList::IndexOf(Person * person)
	{
		PersonListItem* temp = _head;
		int index = 0;
		while (temp != NULL)
		{
			if (temp->Value == *person)
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
			if (temp->Value == *person)
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
			if (temp->Value == *person)
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
			cout << "Surname: " << temp->Value.Surname << endl;
			cout << "Name: " << temp->Value.Name << endl;
			cout << "Sex: " << temp->Value.Sex << endl << endl;
			temp = temp->Next;
		}

		if (_head != NULL)
		{
			cout << "-------------------------------------------------" << endl;
			cout << "Head = " << "Surname: " << _head->Value.Surname << endl;
			cout << "Head = " << "Name: " << _head->Value.Name << endl;
			cout << "Head = " << "Sex: " << _head->Value.Sex << endl << endl;

			cout << "Tail = " << "Surname: " << _tail->Value.Surname << endl;
			cout << "Tail = " << "Name: " << _tail->Value.Name << endl;
			cout << "Tail = " << "Sex: " << _tail->Value.Sex << endl << endl;
			cout << "-------------------------------------------------";
		}
		else
		{
			cout << "Head = NULL " << " Tail = NULL " << endl;
		}
	}

	void PersonList::Read()
	{
		Person newPerson;
		bool key = true;
		while (key)
		{
			cout << endl << "Insert Surname: ";
			cin >> newPerson.Surname;
			key = false;
			for (int i = 0; i < strlen(newPerson.Surname); i++)
			{
				if (isdigit(newPerson.Surname[i]) || isspace(newPerson.Surname[i]))
				{
					key = true;
					break;
				}
				if (newPerson.Surname[i] == '-')
				{
					if (isalpha(newPerson.Surname[i + 1]))
					{
						newPerson.Surname[i + 1] = toupper(newPerson.Surname[i + 1]);
					}
					else
					{
						key = true;
						break;
					}
				}
			}
			newPerson.Surname[0] = toupper(newPerson.Surname[0]);
		}

		key = true;
		while (key)
		{
			cout << endl << "Insert Name: ";
			cin >> newPerson.Name;
			key = false;
			for (int i = 0; i < strlen(newPerson.Name); i++)
			{
				if (isdigit(newPerson.Name[i]) || isspace(newPerson.Name[i]))
				{
					key = true;
					break;
				}
				if (newPerson.Name[i] == '-')
				{
					if (isalpha(newPerson.Surname[i + 1]))
					{
						newPerson.Surname[i + 1] = toupper(newPerson.Surname[i + 1]);
					}
					else
					{
						key = true;
						break;
					}
				}
			}
			newPerson.Name[0] = toupper(newPerson.Name[0]);
		}
		cout << endl << "Insert Sex: ";
		int n;

		do
		{
			n = CheckSymbol();
		} while (n != 0 && n != 1);
		switch (n)
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
		this->Add(&newPerson);
	}

	Person PersonList::GetRandomPerson()
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
		for (int i = 0; i <= strlen(names[name].c_str()); i++)
		{
			newPerson.Name[i] = names[name][i];
		}
		for (int i = 0; i <= strlen(surnames[surname].c_str()); i++)
		{
			newPerson.Surname[i] = surnames[surname][i];
		}
		newPerson.Sex = Male;
		return newPerson;
	}
}
