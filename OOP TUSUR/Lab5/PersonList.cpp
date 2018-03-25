#include "PersonList.h"

namespace Lab5
{
	void PersonList::Add(Person* person)
	{
		PersonListItem* temp = new PersonListItem(*person);
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
		return &temp->Value;
	}

	int PersonList::IndexOf(Person* person)
	{
		PersonListItem* temp = _Head;
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

	void PersonList::Remove(Person* person)
	{
		PersonListItem* temp = _Head;
		while (temp != NULL)
		{
			if (temp->Value == *person)
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
			if (temp->Value == *person)
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

	void PersonList::ShowNodeInConsole(PersonListItem list, string message)
	{
		cout << message << " Surname: " << list.Value.Surname << endl;
		cout << message << " Name: " << list.Value.Name << endl;
		cout << message << " Sex: ";
		list.Value.Sex == 1 ? cout << "Male" : cout << "Female";
		cout << endl << endl;
	}

	void PersonList::ShowInConsole()
	{
		cout << endl;
		PersonListItem* temp = _Head;
		while (temp != NULL)
		{
			ShowNodeInConsole(*temp);
			temp = temp->Next;
		}

		if (_Head != NULL)
		{
			cout << "-------------------------------------------------" << endl;
			ShowNodeInConsole(*_Head, "Head =");
			ShowNodeInConsole(*_Tail, "Tail =");
			cout << "-------------------------------------------------" << endl;
		}
		else
		{
			cout << "Head = NULL " << " Tail = NULL " << endl;
		}
	}

	bool PersonList::ValidationName(char name[])
	{
		bool validate = true;
		for (int i = 0; i < strlen(name); i++)
		{
			if (isdigit(name[i]) || isspace(name[i]))
			{
				validate = false;
				break;
			}
			if (name[i] == '-')
			{
				if (isalpha(name[i + 1]))
				{
					name[i + 1] = toupper(name[i + 1]);
				}
				else
				{
					validate = false;
					break;
				}
			}
		}
		name[0] = toupper(name[0]);
		return validate;
	}

	void PersonList::Read()
	{
		Person newPerson;
		bool key = true;
		while (key)
		{
			cout << endl << "Insert Surname: ";
			cin >> newPerson.Surname;
			key = !ValidationName(newPerson.Surname);
		}

		key = true;
		while (key)
		{
			cout << endl << "Insert Name: ";
			cin >> newPerson.Name;
			key = !ValidationName(newPerson.Name);
		}

		cout << endl << "Insert Sex: ";
		int n;
		do
		{
			n = CheckSymbol();
		} 
		while (n != 0 && n != 1);

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
