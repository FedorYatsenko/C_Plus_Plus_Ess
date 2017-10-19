#include "iostream"
#include <iomanip>

using namespace std;


int main(void)
{
	float a, b, c, d, e;

	cout << "Input a: ";
	cin >> a;

	cout << "Input b: ";
	cin >> b;

	cout << "Input c: ";
	cin >> c;

	cout << "Input d: ";
	cin >> d;

	cout << "Input e: ";
	cin >> e;

	cout << "Result:\n";
	cout << a << "\n";
	cout << fixed << setprecision(2) << b << "\n";
	cout << fixed << setprecision(-1) << c << "\n";
	cout << fixed << setprecision(2) << d << "\n";
	cout << fixed << setprecision(0) << e << "\n";

	system("pause");
}