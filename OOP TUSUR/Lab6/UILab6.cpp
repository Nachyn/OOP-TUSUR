#include "UILab6.h"
#include "PersonTools6.h"

void UILab6()
{
	Lab6::Adult* adultl1 = Lab6::PersonTools::GetRandomAdult();
	Lab6::Adult* adultl2 = Lab6::PersonTools::GetRandomAdult();
	Lab6::Adult* adultl3 = Lab6::PersonTools::GetRandomAdult();
	//TODO: Выводятся иероглифы (+)
	Lab6::PersonList* list = new Lab6::PersonList;
	list->Add(adultl1);
	cout << "Added: " << adultl1->GetShortDescription() << endl;

	list->Add(adultl2);
	cout << "Added: " << adultl2->GetShortDescription() << endl;

	list->Add(adultl3);
	cout << "Added: " << adultl3->GetShortDescription() << endl;

	cout << "==============ShowInConsole================" << endl;
	cout << list->GetItemsInfo();
	cout << "==============End_ShowInConsole================" << endl;

	
	Lab6::Person* find = list->Find(0);
	cout << "The first index found:" << endl;
	cout << find->GetDescription() << endl;

	cout << endl << "The same person is found by the index: " << list->IndexOf(find);
	cout << endl << endl;

	list->Remove(find);
	cout << "Removed: " << find->GetShortDescription() << endl;

	cout << "==============ShowInConsole================" << endl;
	cout << list->GetItemsInfo();
	cout << "==============End_ShowInConsole================" << endl;

	
	list->RemoveAt(0);
	cout << "Removed the person who was on the index 0." << endl;

	cout << "==============ShowInConsole================" << endl;
	cout << list->GetItemsInfo();
	cout << "==============End_ShowInConsole================" << endl;

	list->Clear();
	cout << "===============ListCleared====================" << endl;

	cout << "==============ShowInConsole================" << endl;
	cout << list->GetItemsInfo();
	cout << "==============End_ShowInConsole================" << endl;

	system("pause");
	delete adultl1;
	delete list;
}