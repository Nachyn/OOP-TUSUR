#pragma once
#include "../CheckSymbol.h"
#include "TemplateListItem.h"
#include "../Lab6/Person6.h"

namespace Lab7
{
	template <typename T>
	class TemplateList
	{
	public:
		friend std::ostream& operator<<(std::ostream& os, TemplateList& list)
		{
			TemplateListItem<T>* temp = list._head;
			cout << "Подсписок: ";
			while (temp != NULL)
			{
				cout << temp->Value << "  ";
				temp = temp->Next;
			}
			return os;
		}

		bool operator==(const TemplateList& right)
		{
			TemplateListItem<T>* temp = _head;
			TemplateListItem<T>* temp2 = right._head;
			while (temp != NULL)
			{
				if (temp != temp2)
				{
					return false;
				}
				temp = temp->Next;
				temp2 = temp2->Next;
			}
			return true;
		}

		void Add(T element)
		{
			TemplateListItem<T>* temp = new TemplateListItem<T>(element);
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

		void InsertByIndex(T element, int index)
		{
			if (_head == NULL || index < 0)
			{
				return;
			}

			TemplateListItem<T>* temp = _head;
			int i = 0;
			while (i < index)
			{
				temp = temp->Next;
				i++;
				if (temp == NULL)
				{
					Add(element);
					return;
				}
			};

			if (temp == _head)
			{
				TemplateListItem<T>* newNode = new TemplateListItem<T>(element);
				_head->Prev = newNode;
				newNode->Next = _head;

				_head = newNode;
				return;
			}

			if (temp == _tail)
			{
				TemplateListItem<T>* newNode = new TemplateListItem<T>(element);
				_tail->Prev->Next = newNode;
				newNode->Prev = _tail->Prev;
				newNode->Next = _tail;
				_tail->Prev = newNode;
				_tail->Next = NULL;
				return;
			}


			if (temp != NULL)
			{
				TemplateListItem<T>* newNode = new TemplateListItem<T>(element);
				temp->Prev->Next = newNode;
				newNode->Prev = temp->Prev;
				newNode->Next = temp;
				temp->Prev = newNode;
			}
			return;
		}

		T* Find(int index)
		{
			if (index < 0)
			{
				return nullptr;
			}
			int i = 0;
			TemplateListItem<T>* temp = _head;
			while (i < index)
			{
				if (temp == nullptr)
				{
					return nullptr;
				}
				temp = temp->Next;
				i++;
			};
			return &temp->Value;
		}

		int IndexOf(T element)
		{
			TemplateListItem<T>* temp = _head;
			int index = 0;
			while (temp != NULL)
			{
				if (temp->Value == element)
				{
					return index;
				}
				index++;
				temp = temp->Next;
			}
			return -1;
		}

		void Remove(T element)
		{
			TemplateListItem<T>* temp = _head;
			while (temp != NULL)
			{
				if (temp->Value == element)
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

		void RemoveAt(int index)
		{
			T* person = Find(index);
			TemplateListItem<T>* temp = _head;
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

		void Clear()
		{
			TemplateListItem<T>* next = _head;
			while (next != NULL)
			{
				TemplateListItem<T>* tempNext = next->Next;
				if (typeid(next->Value) == typeid(TemplateList<double>))
				{
					//(TemplateList<double>)(next->Value).Clear();
				}
				delete next;
				next = tempNext;
			}
			_head = NULL;
			_tail = NULL;
		}

		int GetCount()
		{
			int count = 0;
			TemplateListItem<T>* temp = _head;
			while (temp != NULL)
			{
				temp = temp->Next;
				count++;
			}
			return count;
		}

		void GetItemsInfo()
		{
			TemplateListItem<T>* temp = _head;
			while (temp != nullptr)
			{ 
				cout << temp->Value << endl;
				temp = temp->Next;
			}

			if (_head != nullptr)
			{
				cout << "------------------------" << endl;
				cout << "Head = " << _head->Value << endl;
				cout << "Tail = " << _tail->Value << endl;
				cout << "------------------------" << endl;
			}
			else
			{
				cout << "------------------------" << endl;
				cout << "Head = NULL Tail = NULL" << endl;
				cout << "------------------------" << endl;
			}
		}

		static Lab6::Person GetRandomPerson()
		{
			string surnames[] = { "Holiday","Jacobson","James", "Allford", "Bawerman",
				"MacAdam", "Marlow", "Bosworth", "Neal","Conors",
				"Daniels", "Parson", "Quincy", "Richards", "Fane" };
			string names[] = { "Michael","Joshua","Matthew","Ethan","Andrew",
				"Alexander", "Tyler", "James", "John","Samuel",
				"Christian","Logan","Jose","Justin","Gabriel" };

			string name = names[rand() % 15];
			string surname = surnames[rand() % 15];
			unsigned int age = rand() % 20 + 18;
			Sex sex;

			if (rand() % 2 == 0)
			{
				sex = Male;
			}
			else
			{
				sex = Female;
			}
			Lab6::Person newPerson(name, surname, age, sex);
			return newPerson;
		}

		TemplateList() { }
	private:
		TemplateListItem<T>* _head = nullptr;
		TemplateListItem<T>* _tail = nullptr;
		int _count;
	};
}