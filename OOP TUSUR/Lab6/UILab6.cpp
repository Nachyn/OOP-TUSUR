#include "UILab6.h"

void UILab6()
{
	Lab6::Adult* adultl1 = Lab6::Adult::GetRandomAdult();
	Lab6::Adult* adultl2 = Lab6::Adult::GetRandomAdult();
	Lab6::Adult* adultl3 = Lab6::Adult::GetRandomAdult();

	Lab6::PersonList list;
	list.Add(adultl1);
	list.Add(adultl2);
	list.Add(adultl3);
	list.ShowInConsole();

	Lab6::Person* find = list.Find(0);
	cout << find->GetDescription();

	cout << endl << list.IndexOf(find);
	list.Remove(find);

	list.ShowInConsole();
	list.RemoveAt(0);
	list.ShowInConsole();

	system("pause");
}