#pragma once
#include "Sex4.h"
#include "../CheckSymbol.h"

namespace Lab4
{//TODO: Именование файла должно отражать именование сущности, хранящейся в нём.
	//TODO: Также с другими файлами
	struct Person
	{
		string Surname;
		string Name;
		Sex Sex;
	};
}