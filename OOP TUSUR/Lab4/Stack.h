#pragma once
#include "../CheckSymbol.h"

namespace Lab4
{
	struct StackItem
	{
		int Value;
		struct StackItem *Next;
	};

	void Push(StackItem*& stackItem, int value);
	int Pop(StackItem*& stackItem);
	int Top(StackItem*& stackItem);
	int Size(StackItem*& stackItem);
	bool IsEmpty(StackItem*& stackItem);
}