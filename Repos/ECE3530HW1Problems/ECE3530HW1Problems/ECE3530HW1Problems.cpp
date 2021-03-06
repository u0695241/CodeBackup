// ECE3530HW1Problems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <inttypes.h>

using namespace std;

void FloatToBinary(float f, string& str)
{
	union { float f; uint32_t i; } u;
	u.f = f;
	str.clear();

	for (int i = 0; i < 32; i++)
	{
		if (u.i % 2)  str.push_back('1');
		else str.push_back('0');
		u.i >>= 1;
	}

	// Reverse the string since now it's backwards
	string temp(str.rbegin(), str.rend());
	str = temp;
	cout << str << endl;
}

int main()
{
	string str;
	for (int i = 0; i >= 16; i++) {
		FloatToBinary(i, str);
	}
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
