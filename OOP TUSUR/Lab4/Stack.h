#pragma once
#include "../CheckSymbol.h"

namespace Lab4
{
	struct StackItem
	{
		int Value;
		struct StackItem *Next;
	};
	//TODO: Тип в StackItem переименовали, а аргументы - нет(+)
	void Push(StackItem*& stackItem, int value);
	int Pop(StackItem*& stackItem);
	int Top(StackItem*& stackItem);
	int Size(StackItem*& stackItem);
	bool IsEmpty(StackItem*& stackItem);
}