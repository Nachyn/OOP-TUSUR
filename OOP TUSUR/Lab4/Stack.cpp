#include "Stack.h"

namespace Lab4
{
	void Push(StackItem*& stackItem, int value)
	{
		StackItem *newStack = new StackItem;
		newStack->Value = value;
		newStack->Next = stackItem;
		stackItem = newStack;
	}

	int Pop(StackItem*& stackItem)
	{
		if (stackItem == NULL)
		{
			return -1;
		}
		int temp = stackItem->Value;
		StackItem *newStack = stackItem;

		stackItem = stackItem->Next;
		delete newStack;
		return temp;
	}

	int Top(StackItem*& stackItem)
	{
		if (stackItem == NULL)
		{
			return -1;
		}
		return stackItem->Value;
	}

	int Size(StackItem*& stackItem)
	{
		int size = 0;
		StackItem* temp = stackItem;
		while (temp != NULL)
		{
			temp = temp->Next;
			size++;
		}
		return size;
	}

	bool IsEmpty(StackItem*& stackItem)
	{
		return stackItem == NULL;
	}
}
