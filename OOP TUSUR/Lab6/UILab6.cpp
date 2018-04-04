#include "UILab6.h"

void UILab6()
{
	Lab6::Adult* adultl1 = Lab6::Adult::GetRandomAdult();
	Lab6::Adult* adultl2 = Lab6::Adult::GetRandomAdult();
	Lab6::Adult* adultl3 = Lab6::Adult::GetRandomAdult();
	//TODO: Выводятся иероглифы
	Lab6::PersonList list;
	list.Add(adultl1);
	cout << "Добавлен: " << adultl1->Name << " " << adultl1->Surname << endl;

	list.Add(adultl2);
	cout << "Добавлен: " << adultl2->Name << " " << adultl2->Surname << endl;

	list.Add(adultl3);
	cout << "Добавлен: " << adultl3->Name << " " << adultl3->Surname << endl;

	cout << "==============ВЫВОД СПИСКА================" << endl;
	list.ShowInConsole();
	cout << "==============КОНЕЦ ВЫВОДА================" << endl;

	
	Lab6::Person* find = list.Find(0);
	cout << "По первому индексу найден:" << endl;
	cout << find->GetDescription();

	cout << endl << "Тот же человек найден по индексу: " << list.IndexOf(find);
	cout << endl;

	list.Remove(find);
	cout << "Удалили: " << find->Name << " " << find->Surname << endl;

	cout << "==============ВЫВОД СПИСКА================" << endl;
	list.ShowInConsole();
	cout << "==============КОНЕЦ ВЫВОДА================" << endl;

	
	list.RemoveAt(0);
	cout << "Удалили чела, который находился по индексу 0" << endl;

	cout << "==============ВЫВОД СПИСКА================" << endl;
	list.ShowInConsole();
	cout << "==============КОНЕЦ ВЫВОДА================" << endl;

	list.Clear();
	cout << "=========================ЛИСТ ОЧИЩЕН ====================" << endl;

	cout << "==============ВЫВОД СПИСКА================" << endl;
	list.ShowInConsole();
	cout << "==============КОНЕЦ ВЫВОДА================" << endl;

	system("pause");
}