#include "Lab1/Tasks.h"
#include "Lab2/Tasks2.h"
#include "Lab3/Tasks3.h"
#include "Lab4/UILab4.h"
#include "Lab5/UILab5.h"
#include "Lab6/UILab6.h"
#include "Lab7/UILab7.h"

using namespace std;

int main()
{
	setlocale(0, "");
	srand(time(0));
	int chooseLab;
	while (true)
	{
		cout << endl
			<< "------------------" << endl
			<< "[1] Lab 1" << endl
			<< "[2] Lab 2" << endl
			<< "[3] Lab 3" << endl
			<< "[4] Lab 4" << endl
			<< "[5] Lab 5" << endl
			<< "[6] Lab 6" << endl
			<< "[7] Lab 7" << endl
			<< "[0] Exit" << endl
			<< "------------------" << endl
			<< "Choose 0-7: ";
		//TODO: Именование.(+)
		chooseLab = CheckSymbol();
		system("cls");
		switch (chooseLab)
		{
			case 1:
				Lab1::UILab1(); break;
			case 2:
				Lab2::UILab2(); break;
			case 3:
				Lab3::UILab3(); break;
			case 4:
				UILab4(); break;
			case 5:
				UILab5(); break;
			case 6:
				UILab6(); break;
			case 7:
				UILab7(); break;
			case 0:
				return 0;
			default:
				cout << "Повторите ввод"; break;
		}
	}
	return 0;
}