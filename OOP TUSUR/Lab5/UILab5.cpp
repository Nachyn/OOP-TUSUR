#include "UILab5.h"

void UILab5()
{
	Lab5::PersonList list1;
	Lab5::PersonList list2;
	Lab5::Person p1 = list1.GetRandomPerson();

	//TODO: ��� ������ ���������� ���������
	//TODO: �������� ���� ��� ���������� ��������� � ������.
	//TODO: ������ �� ����� ������ ���� ��� ���� ��������� �������������� ������.
	list1.Add(&list1.GetRandomPerson());
	cout << "�������� ��������� ������� � ������ 1" << endl;

	list1.Add(&p1);
	cout << "�������� ��������� ������� � ������ 1" << endl;

	list1.Add(&list1.GetRandomPerson());
	cout << "�������� ��������� ������� � ������ 1" << endl;

	list1.Add(&list1.GetRandomPerson());
	cout << "�������� ��������� ������� � ������ 1" << endl;


	list2.Add(&list1.GetRandomPerson());
	cout << "�������� ��������� ������� � ������ 2" << endl;

	list2.Add(&p1);
	cout << "�������� ������� �� ������� 1 � ������ 1 � ������ 2" << endl;

	list2.Add(&list1.GetRandomPerson());
	cout << "�������� ��������� ������� � ������ 2" << endl;

	cout << "==============����� ������ [1]================" << endl;
	list1.ShowInConsole();
	cout << "==============����� ������ [1]================" << endl << endl;

	cout << "==============����� ������ [2]================" << endl;
	list2.ShowInConsole();
	cout << "==============����� ������ [2]================" << endl << endl;

	list1.RemoveAt(1);
	cout << "������ ��� �� ������� 1 � ������ 1" << endl;
	//list1.Remove(&p1);

	cout << "==============����� ������ [1]================" << endl;
	list1.ShowInConsole();
	cout << "==============����� ������ [1]================" << endl << endl;

	cout << "==============����� ������ [2]================" << endl;
	list2.ShowInConsole();
	cout << "==============����� ������ [2]================" << endl << endl;

	cout << "���� ���� � ����� ������ 1: " << endl;
	list1.Read();

	cout << "==============����� ������ [1]================" << endl;
	list1.ShowInConsole();
	cout << "==============����� ������ [1]================" << endl << endl;

	system("pause");


	list1.Clear();
	cout << "=============������ [1] ������===========" << endl;

	cout << "==============����� ������ [1]================" << endl;
	list1.ShowInConsole();
	cout << "==============����� ������ [1]================" << endl << endl;

	system("pause");
}
