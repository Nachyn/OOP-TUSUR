#pragma once
#include "../CheckSymbol.h"

namespace Lab3
{
	//TODO: Каждую сущность в отдельный файл!
	enum Sex { Female, Male };

	struct Person
	{
		char Surname[40];
		char Name[20];
		//TODO: По именованию не правильно использовать префикс или постфикс Person в той же структуре.
		Sex SexPerson;
	};

	Person ReadPerson();
	void PrintPerson(Person person);
	int GetLength(char* str);
	char* Concatenate(char* string1, char* string2);
	char* GetSubstring(char* string, int startIndex, int charCount);
	int FindSubstring(char* string, char* substring);
	char* Uppercase(char* string);
	char* Lowercase(char* string);
	int Copy(char* string, char* resString, int i, int j);
	void SplitFilename(char* source, char* path, char* name, char* extension);
	char* ReplaceTabsOnSpaces(char* string);
	char* ReplaceSpacesOnTabs(char* string);
	void UILab3();
}