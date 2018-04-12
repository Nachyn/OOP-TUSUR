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
			void ShowItems()
			{
				Lab7::TemplateListItem<T>* temp = _head;
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
			friend std::ostream& operator<<(std::ostream& os, TemplateList& list)
			{
				TemplateListItem<T>* temp = list._head;
				cout << "Подсписок: ";
				while (temp != nullptr)
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
				while (temp != nullptr)
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
		
			void InsertByIndex(T element, int index)
			{
				if (_head == nullptr || index < 0)
				{
					return;
				}

				TemplateListItem<T>* temp = _head;
				int i = 0;
				while (i < index)
				{
					temp = temp->Next;
					i++;
					if (temp == nullptr)
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

			void RemoveAt(int index)
			{
				T* person = Find(index);
				TemplateListItem<T>* temp = _head;
				while (temp != nullptr)
				{
					if (temp->Value == *person)
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

			void Clear()
			{
				TemplateListItem<T>* next = _head;
				while (next != nullptr)
				{
					TemplateListItem<T>* tempNext = next->Next;
					delete next;
					next = tempNext;
				}
				_head = nullptr;
				_tail = nullptr;
			}

			int GetCount()
			{
				int count = 0;
				TemplateListItem<T>* temp = _head;
				while (temp != nullptr)
				{
					temp = temp->Next;
					count++;
				}
				return count;
			}
			TemplateList() { }
		private:
			TemplateListItem<T>* _head = nullptr;
			TemplateListItem<T>* _tail = nullptr;
			int _count;
	};

	
}

