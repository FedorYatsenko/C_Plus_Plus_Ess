// lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main(void) {
	float pi = 3.14159265359;
	float x, y;
	cout << "Enter value for x: ";
	cin >> x;

	y = x*x / (pi*pi);
	y = y / (x*x + 0.5) * (1 +  y / ((x*x - 0.5) * (x*x - 0.5)));

	cout << "y = " << y << endl;

	system("pause");

	return 0;
}
