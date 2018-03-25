#pragma once
namespace Lab4
{
	struct StackItem
	{
		int Value;
		struct StackItem *Next;
	};
}