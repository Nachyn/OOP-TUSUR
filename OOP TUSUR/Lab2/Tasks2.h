#pragma once
#include "../CheckSymbol.h"

namespace Lab2
{
	double MakeCalculation(int value1, int value2);
	int GetRoots(int a, int b, int c, double* x1, double* x2);
	int GetRoots2(int a, int b, int c, double& x1, double& x2);
	void SummNumbers(int value1, int value2);
	void SummNumbers(double value1, double value2);
	void SummNumbers(int value1, double value2);
	int GetPower(int base, int power);

	void InsertionSort(double arr[], int size);
	void InsertionSort2(double* arr, int size);

	bool Prototype(bool p);
	void GlobalPlusTwo();
	void GlobalMultiplyThree();
	void GlobalEqualsOne();

	void UILab2();
}