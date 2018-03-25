#include "UILab6.h"

void UILab6()
{
	Lab6::Adult* adultl1 = Lab6::Adult::GetRandomAdult();
	Lab6::Adult* adultl2 = Lab6::Adult::GetRandomAdult();
	Lab6::Adult* adultl3 = Lab6::Adult::GetRandomAdult();

	Lab6::PersonList list;
	list.Add(adultl1);
	cout << "Äîáàâëåí: " << adultl1->Name << " " << adultl1->Surname << endl;

	list.Add(adultl2);
	cout << "Äîáàâëåí: " << adultl2->Name << " " << adultl2->Surname << endl;

	list.Add(adultl3);
	cout << "Äîáàâëåí: " << adultl3->Name << " " << adultl3->Surname << endl;

	cout << "==============ÂÛÂÎÄ ÑÏÈÑÊÀ================" << endl;
	list.ShowInConsole();
	cout << "==============ÊÎÍÅÖ ÂÛÂÎÄÀ================" << endl;

	
	Lab6::Person* find = list.Find(0);
	cout << "Ïî ïåðâîìó èíäåêñó íàéäåí:" << endl;
	cout << find->GetDescription();

	cout << endl << "Òîò æå ÷åëîâåê íàéäåí ïî èíäåêñó: " << list.IndexOf(find);
	cout << endl;

	list.Remove(find);
	cout << "Óäàëèëè: " << find->Name << " " << find->Surname << endl;

	cout << "==============ÂÛÂÎÄ ÑÏÈÑÊÀ================" << endl;
	list.ShowInConsole();
	cout << "==============ÊÎÍÅÖ ÂÛÂÎÄÀ================" << endl;

	
	list.RemoveAt(0);
	cout << "Óäàëèëè ÷åëà, êîòîðûé íàõîäèëñÿ ïî èíäåêñó 0" << endl;

	cout << "==============ÂÛÂÎÄ ÑÏÈÑÊÀ================" << endl;
	list.ShowInConsole();
	cout << "==============ÊÎÍÅÖ ÂÛÂÎÄÀ================" << endl;

	list.Clear();
	cout << "=========================ËÈÑÒ Î×ÈÙÅÍ ====================" << endl;

	cout << "==============ÂÛÂÎÄ ÑÏÈÑÊÀ================" << endl;
	list.ShowInConsole();
	cout << "==============ÊÎÍÅÖ ÂÛÂÎÄÀ================" << endl;

	system("pause");
}