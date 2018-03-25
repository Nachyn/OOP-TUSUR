#include "UILab5.h"

void UILab5()
{
	Lab5::PersonList list1;
	Lab5::PersonList list2;
	Lab5::Person p1 = list1.GetRandomPerson();


	list1.Add(&list1.GetRandomPerson());
	cout << "Добавлен рандомный человек в Список 1" << endl;

	list1.Add(&p1);
	cout << "Добавлен рандомный человек в Список 1" << endl;

	list1.Add(&list1.GetRandomPerson());
	cout << "Добавлен рандомный человек в Список 1" << endl;

	list1.Add(&list1.GetRandomPerson());
	cout << "Добавлен рандомный человек в Список 1" << endl;


	list2.Add(&list1.GetRandomPerson());
	cout << "Добавлен рандомный человек в Список 2" << endl;

	list2.Add(&p1);
	cout << "Добавлен человек по индексу 1 в Списке 1 в Список 2" << endl;

	list2.Add(&list1.GetRandomPerson());
	cout << "Добавлен рандомный человек в Список 2" << endl;

	cout << "==============ВЫВОД СПИСКА [1]================" << endl;
	list1.ShowInConsole();
	cout << "==============КОНЕЦ ВЫВОДА [1]================" << endl << endl;

	cout << "==============ВЫВОД СПИСКА [2]================" << endl;
	list2.ShowInConsole();
	cout << "==============КОНЕЦ ВЫВОДА [2]================" << endl << endl;

	list1.RemoveAt(1);
	cout << "Удален чел по индексу 1 в списке 1" << endl;
	//list1.Remove(&p1);

	cout << "==============ВЫВОД СПИСКА [1]================" << endl;
	list1.ShowInConsole();
	cout << "==============КОНЕЦ ВЫВОДА [1]================" << endl << endl;

	cout << "==============ВЫВОД СПИСКА [2]================" << endl;
	list2.ShowInConsole();
	cout << "==============КОНЕЦ ВЫВОДА [2]================" << endl << endl;

	cout << "Ввод чела в конец списка 1: " << endl;
	list1.Read();

	cout << "==============ВЫВОД СПИСКА [1]================" << endl;
	list1.ShowInConsole();
	cout << "==============КОНЕЦ ВЫВОДА [1]================" << endl << endl;

	system("pause");


	list1.Clear();
	cout << "=============СПИСОК [1] ОЧИЩЕН===========" << endl;

	cout << "==============ВЫВОД СПИСКА [1]================" << endl;
	list1.ShowInConsole();
	cout << "==============КОНЕЦ ВЫВОДА [1]================" << endl << endl;

	system("pause");
}
