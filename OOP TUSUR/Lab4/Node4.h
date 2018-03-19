#pragma once
#include "Person4.h"

namespace Lab4
{
	struct Node
	{
		Person Data;
		Node* Next = NULL;
		Node* Prev = NULL;
	};
}