#include "UILab7.h"
#include "../Lab6/Person6.h"
#include "UIDouble.h"
#include "UIPerson.h"
#include "UIList.h"

void UILab7()
{
	//TODO: Лучше разделить эти части, сделать выбор - выберите такой список, (+)
	//TODO: такой список, ещё список, а внутри уже показать/очистить. (+)
	//TODO: Иначе сейчас всё перемешано. (+)
	bool key = true;
	int chooseMenu;
	while (key)
	{
		system("cls");
		cout << "[1] Demonstrate on double" << endl
			<< "[2] Demonstrate on Person" << endl
			<< "[3] Demonstrate on List<double>" << endl
			<< "[0] Exit" << endl
			<< "> Choose 0-3: ";
		//TODO: Именование(+)
		chooseMenu = CheckSymbol();
		system("cls");
		switch (chooseMenu)
		{
			case 0:
				//TODO: Почему 0 идёт перед 3? (+)
				key = false;
				break;
			case 1://TODO: Дубли (+)
				UIDouble();
				break;
			case 2:
				//TODO: Дубли (+)
				UIPerson();
				break;
			case 3:
				UIList();
				break;
			default:
				cout << "Повторите ввод";
				break;
		}
	}
	system("pause");
}

