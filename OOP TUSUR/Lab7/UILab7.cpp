#include "UILab7.h"
#include "../Lab6/Person6.h"
#include "UIData7.h"

void UILab7()
{
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

		chooseMenu = CheckSymbol();
		system("cls");
		switch (chooseMenu)
		{
			case 0:

				key = false;
				break;
			case 1:
				UIDouble();
				break;
			case 2:
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
