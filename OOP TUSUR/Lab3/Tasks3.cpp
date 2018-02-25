#include "Tasks3.h"

namespace Lab3
{
	Person Lab3::ReadPerson()
	{
		Person newPerson;
		cout << "Insert Surname: ";
		cin >> newPerson.Surname;
		cout << endl << "Insert Name: ";
		cin >> newPerson.Name;
		cout << endl << "Insert Sex: ";
		int n;

		do
		{
			n = CheckSymbol();
		} while (n != 0 && n != 1);
		switch (n)
		{
		case Female:
			newPerson.SexPerson = Female;
			break;
		case Male:
			newPerson.SexPerson = Male;
			break;
		default:
			break;
		}
		return newPerson;
	}

	void PrintPerson(Person person)
	{
		cout << "Surname: " << person.Surname << endl;
		cout << "Name: " << person.Name << endl;
		cout << "SexPerson: " << person.SexPerson << endl;
	}

	int GetLength(char * str)
	{
		int length = 0;
		while (str[length] != '\0')
		{
			length++;
		}
		return length;
	}

	char * Concatenate(char * string1, char * string2)
	{
		char* newString = new char[200];
		int j = 0;

		for (int i = 0; i < GetLength(string1); i++)
		{
			newString[i] = string1[i];
			j++;
		}

		for (int i = 0; i < GetLength(string2); i++)
		{
			newString[j] = string2[i];
			j++;
		}
		newString[j] = '\0';

		return newString;
	}

	char * GetSubstring(char * string, int startIndex, int charCount)
	{
		char* newString = new char[200];
		if (startIndex < 0 || startIndex + charCount > GetLength(string))
		{
			return NULL;
		}
		int j = 0;
		for (int i = startIndex; i < startIndex + charCount; i++)
		{
			newString[j] = string[i];
			j++;
		}
		newString[j] = '\0';
		return newString;
	}

	int FindSubstring(char * string, char * substring)
	{
		if (GetLength(string) < GetLength(substring))
		{
			return -1;
		}
		for (int i = 0; i < GetLength(string); i++)
		{
			if (string[i] == substring[0])
			{
				bool subString = true;
				int str = ++i;
				for (int subStr = 1; subStr < GetLength(substring); subStr++)
				{
					if (str > GetLength(string))
					{
						return -1;
					}
					if (string[str] != substring[subStr])
					{
						subString = false;
					}
					str++;
				}
				if (subString)
				{
					return --i;
				}
			}
		}
		return -1;
	}

	char * Uppercase(char * string)
	{
		char* newString = new char[200];
		for (int i = 0; i < GetLength(string); i++)
		{
			newString[i] = string[i];
			newString[i + 1] = '\0';
		}

		for (int i = 0; i < GetLength(newString); i++)
		{
			if (newString[i] >= 97 && newString[i] <= 122)
			{
				newString[i] -= 32;
			}
		}
		return newString;
	}

	char * Lowercase(char * string)
	{
		char* newString = new char[200];
		for (int i = 0; i < GetLength(string); i++)
		{
			newString[i] = string[i];
			newString[i + 1] = '\0';
		}

		for (int i = 0; i < GetLength(newString); i++)
		{
			if (newString[i] >= 65 && newString[i] <= 90)
			{
				newString[i] += 32;
			}
		}
		return newString;
	}

	int Copy(char * string, char * resString, int i, int j)
	{
		while (string[i])
		{
			resString[j++] = string[i++];
		}
		resString[j] = '\0';
		return i;
	}

	void SplitFilename(char * source, char * path, char * name, char * extension)
	{

		int index = 0;
		int pointPlace;
		int subIndex = 0;
		while (source[index] != '\0')
		{
			if (source[index] == '.')
			{
				break;
			}
			index++;
		}
		if ((source[index - 1]) && (index))
		{
			pointPlace = index;
			index = Copy(source, extension, index, subIndex);

			while ((source[index] != '\\') && (index))
			{
				index--;
			}
			if (index != pointPlace - 1)
			{
				if (index)
				{
					for (subIndex = 0; subIndex < index + 1; subIndex++)
					{
						path[subIndex] = source[subIndex];
					}
					path[subIndex] = '\0';
					for (index = 0; subIndex<pointPlace;)
					{
						name[index++] = source[subIndex++];
					}
					name[index] = '\0';
				}
				else
				{
					for (index = 0; index<pointPlace; index++)
					{
						name[index] = source[index];
					}
					name[index] = '\0';
					path[0] = NULL;
				}
			}
			else
			{
				path[0] = NULL;
				extension[0] = NULL;
				name[0] = NULL;
			}
		}
		else
		{
			path[0] = NULL;
			extension[0] = NULL;
			name[0] = NULL;
		}
	}

	char * ReplaceTabsOnSpaces(char * string)
	{
		char* newString = new char[200];
		int e = 0;
		int j = 0;
		for (int i = 0; i < GetLength(string); i++)
		{
			if (string[i] == '\t')
			{
				newString[j++] = ':';
				newString[j++] = ':';
				newString[j++] = ':';
				newString[j++] = ':';
				e += 4;
			}
			else
			{
				newString[j] = string[i];
				j++;
				e++;
			}
		}
		newString[e] = '\0';
		return newString;
	}

	char * ReplaceSpacesOnTabs(char * string)
	{
		char* newString = new char[200];
		int e = 0;
		int j = 0;
		for (int i = 0; i < GetLength(string) - 4; i++)
		{
			j = i;
			if (string[j++] == ':' && string[j++] == ':' &&
				string[j++] == ':' && string[j++] == ':')
			{
				newString[i] = '\t';
			}
			else
			{
				newString[i] = string[i];
			}
			e++;
		}
		newString[e] = '\0';
		return newString;
	}

	void UILab3()
	{
		enum MenuEnum
		{
			GetLengthEnum = 1, ConcatenateEnum, GetSubstringEnum,
			FindSubstringEnum, UppercaseEnum, LowercaseEnum,
			SplitFilenameEnum, ReplaceTabsOnSpacesEnum, ReplaceSpacesOnTabsEnum
		};
		cout << "---Program Menu---" << endl;
		cout << "1. GetLength()" << endl;
		cout << "2. Concatenate()" << endl;
		cout << "3. GetSubstring()" << endl;
		cout << "4. FindSubstring()" << endl;
		cout << "5. Uppercase()" << endl;
		cout << "6. Lowercase()" << endl;
		cout << "7. SplitFilename()" << endl;
		cout << "8. ReplaceTabsOnSpaces()" << endl;
		cout << "9. ReplaceSpacesOnTabs()" << endl;
		cout << "10. Exit" << endl;
		cout << "---Choose function number for testing (1-10): ";

		bool exit = false;
		while (true)
		{
			if (exit)
			{
				break;
			}
			cout << "--------------------Choose function number for testing (1-10): ";
			int n = CheckSymbol();
			cout << endl << endl;

			switch (n)
			{
			case GetLengthEnum:
			{
				char* mass1 = (char*)"abc123";
				cout << GetLength(mass1) << endl;
				break;
			}

			case ConcatenateEnum:
			{
				char* mass2 = Concatenate(new char[10]{ '1', '2', '3', '\0' }, new char[10]{ 'a', 'b', 'c','\0' });
				for (int i = 0; i < GetLength(mass2); i++)
				{
					cout << mass2[i] << " ";
				}cout << endl;
				break;
			}

			case GetSubstringEnum:
			{
				char* mass3 = (char*)"abc123";
				char* subMass3 = GetSubstring(mass3, 3, 3);
				for (int i = 0; i < GetLength(subMass3); i++)
				{
					cout << subMass3[i] << " ";
				}cout << endl;
				break;
			}

			case FindSubstringEnum:
			{
				char* mass4 = (char*)"vybory2018putin";
				char* subStr = (char*)"naval";
				char* subStr2 = (char*)"putin";
				if (FindSubstring(mass4, subStr) == -1)
				{
					cout << "/naval/ NEnaiden v /vybory2018putin/" << endl;
				}
				if (FindSubstring(mass4, subStr2) != -1)
				{
					cout << "/putin/ naiden v /vybory2018putin/" << endl;
					cout << "na pozicii " << FindSubstring(mass4, subStr2) << endl;
				}
				break;
			}

			case UppercaseEnum:
			{
				char* mass5 = (char*)"Different cases in That string, also 1 and 2 numbers!.!#@48";
				cout << Uppercase(mass5) << endl;
				break;
			}

			case LowercaseEnum:
			{
				char* mass5 = (char*)"Different cases in That string, also 1 and 2 numbers!.!#@48";
				cout << Lowercase(mass5) << endl;
				break;
			}

			case SplitFilenameEnum:
			{
				char source6[50]{ 'd',':','\\','f','o','l','d','e','r','\\','s','u','b','f','o','l','d','e','r','\\','f','i','l','e','N','e','x','e','\0' };
				char path6[50];
				char name6[50];
				char extension6[50];

				SplitFilename(source6, path6, name6, extension6);
				cout << "source: " << source6 << endl;
				cout << "path: " << path6 << endl;
				cout << "name: " << name6 << endl;
				cout << "extension: " << extension6 << endl;
				break;
			}

			case ReplaceTabsOnSpacesEnum:
			{
				char* mass7 = (char*)":::Cake\tis\ta lie! C::ake\t\tis a lie! ";
				cout << ReplaceTabsOnSpaces(mass7) << endl;
				break;
			}

			case ReplaceSpacesOnTabsEnum:
			{
				char* mass7 = (char*)":::Cake\tis\ta lie! C::ake\t\tis a lie! ";
				cout << ReplaceSpacesOnTabs(mass7) << endl;
				break;
			}
			case 10:
				exit = true;
				break;

			default:
				cout << "Enter Again" << endl;
				break;
			}
		}

		Person person1 = ReadPerson();
		PrintPerson(person1);

		system("pause");
	}
}
