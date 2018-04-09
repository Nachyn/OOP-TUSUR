#pragma once
#include "UIPerson.h"

void UIPerson()
{
	TemplateList<Person>* list = new TemplateList<Person>();
	bool key = true;
	while (key)
	{
		cout << "[1] Дообавить рандом элемент" << endl
			<< "[2] Очистить список" << endl
			<< "[3] Найти по индексу" << endl
			<< "[4] Получить количество элементов в списке" << endl
			<< "[5] Вывести список" << endl
			<< "[6] Вставить рандомный элемент по индексу" << endl
			<< "[7] Удалить по индексу" << endl
			<< "[0] Выход" << endl
			<< "-> Выберите: ";
		switch (CheckSymbol())
		{
		case 0:
			key = false;
			break;
		case 1:
			system("cls");
			list->Add(TemplateList<Person>::GetRandomPerson());
			break;
		case 2:
			system("cls");
			list->Clear();
			cout << "Список очищен" << endl;
			break;
		case 3:
		{
			system("cls");
			cout << "Введите индекс: " << endl;
			int index = CheckSymbol();
			cout << "Найденный элемент: ";
			Person* findElement = list->Find(index);
			if (findElement != nullptr)
			{
				cout << *findElement;
			}
			else
			{
				cout << "Элемент не найден";
			}
			break;
		}
		case 4:
			system("cls");
			cout << "Количество элементов в списке: ";
			cout << list->GetCount();
			break;
		case 5:
			system("cls");
			list->GetItemsInfo();
			break;
		case 6:
		{
			system("cls");
			cout << " Введите индекс: ";
			int index = CheckSymbol();
			list->InsertByIndex(TemplateList<Person>::GetRandomPerson(), index);
			break;
		}
		case 7:
			system("cls");
			cout << "Введите индекс: ";
			list->RemoveAt(CheckSymbol());
			break;
		}
		system("pause");
		system("cls");
	}
	delete list;
}
