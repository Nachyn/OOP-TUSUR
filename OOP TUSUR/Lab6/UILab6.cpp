#include "UILab6.h"

void UILab6()
{
	Lab6::Adult* adultl1 = Lab6::Adult::GetRandomAdult();
	Lab6::Adult* adultl2 = Lab6::Adult::GetRandomAdult();
	Lab6::Adult* adultl3 = Lab6::Adult::GetRandomAdult();
	//TODO: ��������� ���������
	Lab6::PersonList list;
	list.Add(adultl1);
	cout << "��������: " << adultl1->Name << " " << adultl1->Surname << endl;

	list.Add(adultl2);
	cout << "��������: " << adultl2->Name << " " << adultl2->Surname << endl;

	list.Add(adultl3);
	cout << "��������: " << adultl3->Name << " " << adultl3->Surname << endl;

	cout << "==============����� ������================" << endl;
	list.ShowInConsole();
	cout << "==============����� ������================" << endl;

	
	Lab6::Person* find = list.Find(0);
	cout << "�� ������� ������� ������:" << endl;
	cout << find->GetDescription();

	cout << endl << "��� �� ������� ������ �� �������: " << list.IndexOf(find);
	cout << endl;

	list.Remove(find);
	cout << "�������: " << find->Name << " " << find->Surname << endl;

	cout << "==============����� ������================" << endl;
	list.ShowInConsole();
	cout << "==============����� ������================" << endl;

	
	list.RemoveAt(0);
	cout << "������� ����, ������� ��������� �� ������� 0" << endl;

	cout << "==============����� ������================" << endl;
	list.ShowInConsole();
	cout << "==============����� ������================" << endl;

	list.Clear();
	cout << "=========================���� ������ ====================" << endl;

	cout << "==============����� ������================" << endl;
	list.ShowInConsole();
	cout << "==============����� ������================" << endl;

	system("pause");
}