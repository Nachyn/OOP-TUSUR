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

	int GetRoots(int a, int b, int c, double * x1, double * x2)
	{
		double D = b * b - (4 * a*c);
		double sqrtD = sqrt(D);

		if (D < 0 || b == 0)
		{
			x1 = x2 = NULL;
			return 0;
		}

		if (a == 0)
		{
			*x1 = -c / b;
			return 1;
		}

		if ((int)D == 0)
		{
			*x1 = -(b / 2 * a);
			x2 = NULL;
			return 1;
		}
		*x1 = (-b - sqrtD) / (2 * a);
		*x2 = (-b + sqrtD) / (2 * a);
		return 2;
	}

	int GetRoots2(int a, int b, int c, double & x1, double & x2)
	{
		double D = b * b - (4 * a*c);
		double sqrtD = sqrt(D);

		if (D < 0 || b == 0)
		{
			x1 = x2 = NULL;
			return 0;
		}

		if (a == 0)
		{
			x1 = -c / b;
			return 1;
		}

		if ((int)D == 0)
		{
			x1 = -(b / 2 * a);
			x2 = NULL;
			return 1;
		}
		x1 = (-b - sqrtD) / (2 * a);
		x2 = (-b + sqrtD) / (2 * a);
		return 2;
	}

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

	void InsertionSort2(double* arr, int size)
	{
		InsertionSort(arr, size);
	}

	void ShowArray(double arr[100][100], int size)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}

	void MultiplyArrays(double arr1[100][100], double arr2[100][100], double resultArr[100][100], int size)
	{
		for (int i = 0; i < size; i++)
		{
			for (int l = 0; l < size; l++)
			{
				double sum = 0;
				for (int j = 0; j < size; j++)
				{
					sum += arr1[i][j] * arr2[j][l];
				}
				resultArr[i][l] = sum;
			}
		}
	}

	void UILab2()
	{
		cout << MakeCalculation(5, 5) << endl;
		cout << "--------------------------------------------------" << endl;

		double* x1 = new double;
		double* x2 = new double;
		cout << GetRoots(0, 1, 2, x1, x2);
		cout << " " << *x1 << " " << *x2 << endl;
		cout << "--------------------------------------------------" << endl;

		double& xx1 = *(new double);
		double& xx2 = *(new double);
		cout << GetRoots2(0, 1, 2, xx1, xx2);
		cout << " " << xx1 << " " << xx2 << endl;
		cout << "--------------------------------------------------" << endl;

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

		cout << GetPower(40, 10) << endl;
		cout << "--------------------------------------------------" << endl;

		cout << rand() % 11 << endl;
		cout << "--------------------------------------------------" << endl;

		double arr[20];
		for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		{
			arr[i] = rand() % 100;
		}
		InsertionSort(arr, sizeof(arr) / sizeof(arr[0]));
		for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl << "--------------------------------------------------" << endl;
	
		double array1[100][100];
		double array2[100][100];
		double array3[100][100];

		int size;
		do 
		{
			cout << endl << "Введите Размер матрицы:";
			size = CheckSymbol();
			cout << endl;
		} 
		while (size < 1);

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				array1[i][j] = rand() % 100;
				array2[i][j] = rand() % 100;
			}
		}

		cout << "A:" << endl << endl;
		ShowArray(array1, size);

		cout << endl << "B:" << endl << endl;
		ShowArray(array2, size);

		MultiplyArrays(array1, array2, array3, size);

		cout << endl << "A*B:" << endl << endl;
		ShowArray(array3, size);

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
}