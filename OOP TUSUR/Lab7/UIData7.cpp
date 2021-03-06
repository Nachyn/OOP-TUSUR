﻿#pragma once
#include "UIData7.h"
#include "../Lab6/Person6.h"
#include "../Lab6/PersonTools6.h"


void DoubleListMenu(TemplateList<double>* list, int number)
{
	if (list == nullptr)
	{
		return; //
	}

	bool key = true;
	while (key)
	{
		cout << "ЛИСТ под индексом: " << number << endl
			<< "[1] Дообавить элемент" << endl
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
				list->ShowItems();
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
}

void UIList()
{
	TemplateList<TemplateList<double>>* list = new TemplateList<TemplateList<double>>();
	bool key = true;
	while (key)
	{
		cout << "[1] Добавить Лист" << endl
			<< "[2] Очистить список" << endl
			<< "[3] *Работать с Листом по индексу*" << endl
			<< "[4] Получить количество элементов в списке" << endl
			<< "[5] Вывести список" << endl
			<< "[6] Внести по новый Лист по индексу" << endl
			<< "[7] Удалить Лист по индексу" << endl
			<< "[0] Выход" << endl
			<< "-> Выберите: ";
		switch (CheckSymbol())
		{
			case 0:
				key = false;
				break;
			case 1:
				system("cls");
				list->Add(*new TemplateList<double>);
				break;
			case 2:
				system("cls");
				list->Clear();
				cout << "Список очищен" << endl;
				break;
			case 3:
			{
				system("cls");
				cout << "Введите индекс: ";
				int index = CheckSymbol();
				DoubleListMenu(list->Find(index), index);
				break;
			}
			case 4:
				system("cls");
				cout << "Количество элементов в списке: ";
				cout << list->GetCount();
				break;
			case 5:
				system("cls");
				list->ShowItems();
				break;
			case 6:
			{
				system("cls");
				cout << " Введите индекс: ";
				int index = CheckSymbol();
				list->InsertByIndex(*new TemplateList<double>, index);
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

void UIPerson()
{
	TemplateList<Lab6::Person>* list = new TemplateList<Lab6::Person>();
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
			<< "[8] Добавить свой элемент" << endl
			<< "[0] Выход" << endl
			<< "-> Выберите: ";
		switch (CheckSymbol())
		{
			case 0:
				key = false;
				break;
			case 1:
				system("cls");
				list->Add(*Lab6::PersonTools::GetSingleAdult());
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
				Lab6::Person* findElement = list->Find(index);
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
				list->ShowItems();
				break;
			case 6:
			{
				system("cls");
				cout << " Введите индекс: ";
				int index = CheckSymbol();
				list->InsertByIndex(*Lab6::PersonTools::GetSingleAdult(), index);
				break;
			}
			case 7:
				system("cls");
				cout << "Введите индекс: ";
				list->RemoveAt(CheckSymbol());
				break;
			case 8:
				system("cls");
				list->Add(*Lab6::PersonTools::GetCreatePerson());
				break;
		}
		system("pause");
		system("cls");
	}
	delete list;
}

void UIDouble()
{
	TemplateList<double>* list = new TemplateList<double>();
	DoubleListMenu(list, 0);
	delete list;
}
