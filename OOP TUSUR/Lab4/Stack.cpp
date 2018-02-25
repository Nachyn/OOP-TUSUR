#include "Stack.h"

namespace Lab4
{
	void Push(Stack *& stack, int value)
	{
		Stack *newStack = new Stack;
		newStack->Value = value;
		newStack->Next = stack;
		stack = newStack;
	}

	int Pop(Stack *& stack)
	{
		if (stack == NULL)
		{
			return -1;
		}
		int temp = stack->Value;
		Stack *newStack = stack;

		stack = stack->Next;
		delete newStack;
		return temp;
	}

	int Top(Stack *& stack)
	{
		if (stack == NULL)
		{
			return -1;
		}
		return stack->Value;
	}

	int Size(Stack *& stack)
	{
		int size = 0;
		Stack* temp = stack;
		while (temp != NULL)
		{
			temp = temp->Next;
			size++;
		}
		return size;
	}

	bool isEmpty(Stack *& stack)
	{
		return stack == NULL ? true : false;
	}
}
