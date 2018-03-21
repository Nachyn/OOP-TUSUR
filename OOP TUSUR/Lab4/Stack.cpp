#include "Stack.h"

namespace Lab4
{
	void Push(StackItem *& stack, int value)
	{
		StackItem *newStack = new StackItem;
		newStack->Value = value;
		newStack->Next = stack;
		stack = newStack;
	}

	int Pop(StackItem *& stack)
	{
		if (stack == NULL)
		{
			return -1;
		}
		int temp = stack->Value;
		StackItem *newStack = stack;

		stack = stack->Next;
		delete newStack;
		return temp;
	}

	int Top(StackItem *& stack)
	{
		if (stack == NULL)
		{
			return -1;
		}
		return stack->Value;
	}

	int Size(StackItem *& stack)
	{
		int size = 0;
		StackItem* temp = stack;
		while (temp != NULL)
		{
			temp = temp->Next;
			size++;
		}
		return size;
	}

	bool IsEmpty(StackItem *& stack)
	{
		return stack == NULL;
	}
}
