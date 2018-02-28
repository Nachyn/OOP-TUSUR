#include "UILab5.h"

void UILab5()
{
	Lab5::PersonList list1;
	Lab5::PersonList list2;
	Lab5::Person p1 = list1.GetRandomPerson();

	list1.Add(&list1.GetRandomPerson());
	list1.Add(&p1);
	list1.Add(&list1.GetRandomPerson());
	list1.Add(&list1.GetRandomPerson());

	list2.Add(&list1.GetRandomPerson());
	list2.Add(&p1);
	list2.Add(&list1.GetRandomPerson());

	list1.ShowInConsole();
	list2.ShowInConsole();

	list1.RemoveAt(1);
	//list1.Remove(&p1);

	list1.ShowInConsole();
	list2.ShowInConsole();

	list1.Read();
	list1.ShowInConsole();
	system("pause");
	cout << "Лист1 очищен.";
	list1.Clear();

	list1.ShowInConsole();
	system("pause");
}
