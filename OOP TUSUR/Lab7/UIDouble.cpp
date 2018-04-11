#pragma once
#include "UIDouble.h"

void UIDouble()
{
	TemplateList<double>* list = new TemplateList<double>();
	bool key = true;
	while (key)
	{//TODO: Похоже, что менюшки дублируются.
		cout << "[1] Дообавить элемент" << endl
			<< "[2] Очистить список" << endl
			<< "[3] Найти по индексу" << endl
			<< "[4] Получить количество элементов в списке" << endl
			<< "[5] Вывести список" << endl
			<< "[6] Найти элемент" << endl
			<< "[7] Внести по индексу" << endl
			<< "[8] Удалить элемент" << endl
			<< "[9] Удалить по индексу" << endl
			<< "[0] Выход" << endl
			<< "-> Выберите: ";
		switch (CheckSymbol())
		{
		case 0:
			key = false;
			break;
		case 1:
			system("cls");
			cout << "Введите элемент: ";
			list->Add(CheckSymbol());
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
			double* findElement = list->Find(index);
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
			cout << "Введите искомый элемент: ";
			double findElement = CheckSymbol();
			cout << "Индекс: ";
			cout << list->IndexOf(findElement);
			break;
		}
		case 7:
		{
			system("cls");
			cout << "Введите элемент: ";
			double element = CheckSymbol();
			cout << " Введите индекс: ";
			int index = CheckSymbol();
			list->InsertByIndex(element, index);
			break;
		}
		case 8:
			system("cls");
			cout << "Введите элемент: ";
			list->Remove(CheckSymbol());
			break;
		case 9:
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
