#include "UILab4.h"

void UILab4()
{
	Lab4::DoublyLinkedList list;
	bool key = true;
	Lab4::Person newPerson;
	int n, index;
	while (key)
	{
		system("color 02");
		cout << endl
			<< "-------------------------------------------------" << endl
			<< "[1] ������� �������� � �����" << endl
			<< "[2] ����� ������" << endl
			<< "[3] ����� �������� �� �������" << endl
			<< "[4] ������� �������� �� �������" << endl
			<< "[5] �������� �������� �� �������" << endl
			<< "[6] �������� ���������� ������" << endl
			<< "[7] ���������������� � �������� ������ Person" << endl
			<< "[0] ����� �� ���������" << endl
			<< "-------------------------------------------------" << endl
			<< "������� ����� ������� ��� �� ���������: ";
		n = CheckSymbol();
		system("cls");
		system("color 04");
		switch (n)
		{
		case 1:
			newPerson = Lab4::ReadPerson();
			list = AddEnd(list, &newPerson);
			cout << "�������� ��������" << endl;
			break;

		case 2:
			ShowInConsole(list);
			break;

		case 3:
		{
			cout << "������� ������: ";
			index = CheckSymbol();
			Lab4::Person* newPerson = GetByIndex(list, index);
			if (newPerson != NULL)
			{
				cout << "Surname: " << newPerson->Surname << endl;
				cout << "Name: " << newPerson->Name << endl;
				cout << "Sex: " << newPerson->SexPerson << endl;
			}
			break;
		}

		case 4:
			newPerson = Lab4::ReadPerson();
			cout << "������� ������: ";
			index = CheckSymbol();
			list = InsertByindex(list, &newPerson, index);
			break;

		case 5:
			cout << "������� ������: ";
			index = CheckSymbol();
			list = RemoveByIndex(list, index);
			break;
		case 6:
			list = Clear(list);
			cout << "������ ������";
			break;
		case 7:
		{
			Lab4::Person randomPerson = Lab4::MakeRandomPerson();
			list = AddEnd(list, &randomPerson);
			cout << "�������� ��������" << endl;
			break;
		}
		case 0:
			key = false;
			break;

		default:
			cout << "��������� ����";
			break;
		}

	}
	system("color 06");
	Lab4::Stack* stack = NULL;
	cout << "size: " << Size(stack) << endl;
	cout << "top: " << Top(stack) << endl;
	cout << "isEmpty: " << isEmpty(stack) << endl << endl;

	cout << "push: 100" << endl; Push(stack, 100);
	cout << "push: 200" << endl; Push(stack, 200);
	cout << "push: 300" << endl; Push(stack, 300);
	cout << "push: 400" << endl; Push(stack, 400);

	cout << "pop: " << Pop(stack) << endl;
	cout << "pop: " << Pop(stack) << endl;
	cout << endl;
	cout << "size: " << Size(stack) << endl;
	cout << "top: " << Top(stack) << endl;
	cout << "isEmpty: " << isEmpty(stack) << endl;
	cout << endl;
	cout << "pop: " << Pop(stack) << endl;
	cout << "pop: " << Pop(stack) << endl;
	cout << "pop: " << Pop(stack) << endl;
	system("pause");
	system("color 0F");
}
