#include "Tasks2.h"

namespace Lab2
{
	int globalVariable = 7;

	double MakeCalculation(int value1, int value2)
	{
		char key;
		cout << "Enter mathematic operation (+, -, *, /, %): ";
		cin >> key;

		while ((key != '+') && (key != '-') && (key != '*') && (key != '/') && (key != '%'))
		{
			cout << ("\nINCORRECT SYMBOL!!!\nPlease, enter (+, -, *, /, %):");
			cin >> key;
		}

		switch (key)
		{
		case '+':
			return value1 + value2;
			break;

		case '-':
			return value1 - value2;
			break;

		case '*':
			return value1 * value2;
			break;

		case '/':
			return value1 / value2;

		case '%':
			return value1 % value2;
			break;

		default:
			return -1;
			break;
		}
	}

	int GetRoots(int a, int b, int c, double** x1, double** x2)
	{
		double D = b * b - (4 * a*c);
		double sqrtD = sqrt(D);

		if (D < 0)
		{
			*x1 = *x2 = NULL;
			return 0;
		}
		if (a == 0) {
			**x1 = (-c/b);
			*x2 = NULL;
			return 1;
		}
		if ((int)D == 0)
		{
			**x1 = -(b / 2 * a);
			*x2 = NULL;
			return 1;
		}
		**x1 = (-b - sqrtD) / (2 * a);
		**x2 = (-b + sqrtD) / (2 * a);
		return 2;
	}

	/*int GetRoots2(int a, int b, int c, double & x1, double & x2)
	{
		double D = b * b - (4 * a*c);
		double sqrtD = sqrt(D);

		if (D < 0 || a < 1)
		{
			x1 = x2 = NULL;
			return 0;
		}
		if ((int)D == 0)
		{
			x1 = -(b / 2 * a);
			x2 = NULL;
			return 1;
		}
		x1 = (-b - sqrtD) / 2 * a;
		x2 = (-b + sqrtD) / 2 * a;
		return 2;
	}*/

	void SummNumbers(int value1, int value2)
	{
		cout << "Summ of integer is " << value1 + value2 << endl;
	}

	void SummNumbers(double value1, double value2)
	{
		cout << "Summ of double is " << value1 + value2 << endl;
	}

	void SummNumbers(int value1, double value2)
	{
		cout << "Summ of integer and double is " << value1 + value2 << endl;
	}

	int GetPower(int base, int power)
	{
		if (base <= 0)
		{
			return 0;
		}
		base = base - power;
		return 1 + GetPower(base, power);
	}

	void InsertionSort(double arr[], int size)
	{
		for (int i = 1; i < size; i++)
		{
			for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
			{
				double temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}

	void InsertionSort2(double * arr, int size)
	{
		for (int i = 1; i < size; i++)
		{
			for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
			{
				double temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}

	void UILab2()
	{
		//2
		cout << Prototype(false) << endl;
		cout << "--------------------------------------------------" << endl;

		//4
		cout << MakeCalculation(5, 5) << endl;
		cout << "--------------------------------------------------" << endl;

		//5
		double* x1 = new double;
		double* x2 = new double;
		cout << GetRoots(0, 1, 2, &x1,&x2);
		cout << " " << *x1 << " " << x2 << endl;
		cout << "--------------------------------------------------" << endl;

		//6
		double& xx1 = *(new double);
		double& xx2 = *(new double);
		//cout << GetRoots2(1, 3, 2, xx1, xx2);
		//cout << " " << *x1 << " " << *x2 << endl;
		cout << "--------------------------------------------------" << endl;

		//7
		int a = 1;
		int b = 2;
		SummNumbers(a, b);
		double x = 3.0;
		double y = 4.0;
		SummNumbers(x, y);
		SummNumbers(a, y);
		float m = 5.0;
		float nn = 6.0;
		SummNumbers(m, nn);
		cout << "--------------------------------------------------" << endl;

		//8
		cout << "Global Variable: " << globalVariable << endl;
		GlobalPlusTwo();
		cout << "Global Variable: " << globalVariable << endl;
		GlobalMultiplyThree();
		cout << "Global Variable: " << globalVariable << endl;
		GlobalEqualsOne();
		cout << "Global Variable: " << globalVariable << endl;
		globalVariable = 5;
		cout << "Global Variable: " << globalVariable << endl;
		cout << "--------------------------------------------------" << endl;

		//9
		cout << GetPower(40, 10) << endl;
		cout << "--------------------------------------------------" << endl;

		//10
		cout << rand() % 11 << endl;
		cout << "--------------------------------------------------" << endl;

		//11 12 сортировка вставками
		double arr[20];
		for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		{
			arr[i] = rand() % 100;
		}
		InsertionSort(arr, sizeof(arr) / sizeof(arr[0]));
		//InsertionSort2(arr, sizeof(arr) / sizeof(arr[0]));
		for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl << "--------------------------------------------------" << endl;

		//13
//TODO: Внимательно прочитайте стандарт оформления кода RSDN https://rsdn.org/article/mag/200401/codestyle.XML
//TODO: и приведите свой код в соответстие со стандартом		
		double mA[100][100], mB[100][100], mC[100][100];
		int i, j, l, n;
		double s;
		cout << endl << "Введите Размер матрицы:";
		cin >> n;
		cout << endl;

		for (i = 0; i<n; i++)
		{
			for (j = 0; j<n; j++)
			{
				mA[i][j] = rand() % 100;
				mB[i][j] = rand() % 100;
			}
		}
		//TODO: Ниже много дублирования, поправьте.
		cout << "A:" << endl << endl;
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<n; j++)
			{
				cout << mA[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl << "B:" << endl << endl;
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<n; j++)
			{
				cout << mB[i][j] << " ";
			}
			cout << endl;
		}
		for (i = 0; i<n; i++)
		{
			for (l = 0; l<n; l++)
			{
				s = 0;
				for (j = 0; j<n; j++) {
					s += mA[i][j] * mB[j][l];
				}
				mC[i][l] = s;
			}
		}
		cout << endl << "A*B:" << endl << endl;
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<n; j++)
			{
				cout << mC[i][j] << " ";
			}
			cout << endl;
		}

		system("pause");
	}

	void GlobalEqualsOne()
	{
		globalVariable = 1;
	}

	void GlobalPlusTwo()
	{
		globalVariable += 2;
	}

	void GlobalMultiplyThree()
	{
		globalVariable *= 3;
	}

	//TODO: Чёт не понял - а это зачем и что показывает?
	bool Prototype(bool p)
	{
		return !p;
	}
}