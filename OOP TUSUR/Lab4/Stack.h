#pragma once
#include "../CheckSymbol.h"

namespace Lab4
{
	struct Stack
	{
		int Value;
		struct Stack *Next;
	};

	void Push(Stack* &stack, int value);
	int Pop(Stack* &stack);
	int Top(Stack* &stack);
	int Size(Stack* &stack);
	bool isEmpty(Stack* &stack);
}