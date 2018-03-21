#pragma once
#include "../CheckSymbol.h"

namespace Lab4
{
	struct StackItem
	{
		int Value;
		struct StackItem *Next;
	};
	//TODO: ��� � StackItem �������������, � ��������� - ���
	void Push(StackItem*& stack, int value);
	int Pop(StackItem*& stack);
	int Top(StackItem*& stack);
	int Size(StackItem*& stack);
	bool IsEmpty(StackItem*& stack);
}