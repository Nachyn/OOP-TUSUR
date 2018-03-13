#pragma once
#include "../CheckSymbol.h"
#include "Person3.h"

namespace Lab3
{
	Person ReadPerson();
	void PrintPerson(Person& person);
	int GetLength(char* str);
	char* Concatenate(char* string1, char* string2);
	char* GetSubstring(char* string, int startIndex, int charCount);
	int FindSubstring(char* string, char* substring);
	char* ConvertUppercase(char* string);
	char* ConvertLowercase(char* string);
	int Copy(char* string, char* resString, int i, int j);
	void SplitFilename(char* source, char* path, char* name, char* extension);
	char* ReplaceTabsOnSpaces(char* string, int countSpace);
	char* ReplaceSpacesOnTabs(char* string, int countSpace);
	void UILab3();
}