#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;
inline int CheckSymbol()
{
	string inputData;
	int outputNumber;
	do
	{
		cin >> inputData;
		if (inputData == "0") { return 0; }
		outputNumber = atoi(inputData.c_str());
	} 
	while (outputNumber == 0);
	return outputNumber;
}