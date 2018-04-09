#include "Tasks.h"

namespace Lab1
{
	void Task2()
	{
		printf_s("Hello World!\n");
	}

	void Task3()
	{
		int a = 1;
		int b = 2;

		printf_s("A: %d \n", a);
		printf_s("B: %d \n", b);
		printf_s("A + B: %d \n", a + b);
	}

	void Task4()
	{
		int a = 5;
		int b = 3;

		float z = 5.0f;
		float y = 3.0f;

		printf_s("Float division: %f \n", z / y);
		printf_s("Integer division: %d \n", a / b);
	}

	void Task5()
	{
		int a;
		int b;

		printf_s("Enter A: ");
		scanf_s("%d", &a);
		printf_s("Enter B: ");
		scanf_s("%d", &b);

		printf_s("Sum %d + %d = %d \n", a, b, a + b);
	}

	void Task6()
	{
		int* pA = new int;
		int* pB = new int;

		printf_s("Enter A: ");
		scanf_s("%d", pA);
		printf_s("Enter B: ");
		scanf_s("%d", pB);

		printf_s("Sum %d + %d = %d \n", *pA, *pB, *pA + *pB);
	}

	void Task7()
	{
		int a;
		printf_s("Enter value for check on even/odd: ");
		scanf_s("%d", &a);
		if (a % 2 == 0)
		{
			printf_s("\n Value %d is even! \n", a);
		}
		else
		{
			printf_s("\n Value %d is odd! \n", a);
		}
	}

	void Task8()
	{
		int a;
		printf_s("Enter value for check on even/odd: ");
		scanf_s("%d", &a);
		if (a % 5 == 0)
		{
			printf_s("\n Value %d multiples 5! \n", a);
		}
		else if (a % 2 == 0)
		{
			printf_s("\n Value %d multiples 2! \n", a);
		}
		else
		{
			printf_s("\n Value %d doesn`t multiply 5 or 2! \n", a);
		}
	}

	void Task9()
	{
		int a = 0;
		while (a < 5)
		{
			printf_s("Value is %d now \n", a);
			a++;
		}
	}

	void Task10()
	{
		int a = 0;
		do
		{
			printf_s("Value is %d now \n", a);
			a++;
		} while (a < 5);
	}

	void Task11()
	{
		int a = 10;
		for (int i = 0; i < 10; i++)
		{
			printf_s("Iteration #%d \n", i);
		}
		printf_s("\n\n");
		for (int i = 0; i < a; i++)
		{
			a--;
			printf_s("Iteration #%d Value is %d \n", i, a);
		}
	}

	void Task12()
	{
		int a = 10;
		for (int i = 0; i < 10; i++)
		{
			a--;
			if (i >= a)
			{
				printf_s("I is more or equal A! Break of cycle");
				break;
			}
		}
		printf_s("\n A is %d \n", a);
	}

	void Task13()
	{
		int a = 5;
		int b = 3;
		float z;

		z = a;
		printf_s("Value of z is %f \n", z);

		a = (int)z;
		printf_s("Value of a is %d \n", a);

		z = a / b;
		printf_s("Value of z is %f \n", z);

		z = ((float)a) / b;
		printf_s("Value of z is %f \n", z);
	}

	void UILab1()
	{
		Task2();
		cout << "-----------------------------------------------------------\n";
		Task3();
		cout << "-----------------------------------------------------------\n";
		Task4();
		cout << "-----------------------------------------------------------\n";
		Task5();
		cout << "-----------------------------------------------------------\n";
		Task6();
		cout << "-----------------------------------------------------------\n";
		Task7();
		cout << "-----------------------------------------------------------\n";
		Task8();
		cout << "-----------------------------------------------------------\n";
		Task9();
		cout << "-----------------------------------------------------------\n";
		Task10();
		cout << "-----------------------------------------------------------\n";
		Task11();
		cout << "-----------------------------------------------------------\n";
		Task12();
		cout << "-----------------------------------------------------------\n";
		Task13();

		system("pause");
	}
}


