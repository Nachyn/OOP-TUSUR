#pragma once
#include "../CheckSymbol.h"
#include "StackItem.h"

namespace Lab4
{
	void Push(StackItem*& stackItem, int value);
	int Pop(StackItem*& stackItem);
	int Top(StackItem*& stackItem);
	int Size(StackItem*& stackItem);
	bool IsEmpty(StackItem*& stackItem);
}