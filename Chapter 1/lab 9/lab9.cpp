#include "iostream"

using namespace std;

int main(void)
{
	int a, b, c, d;

	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	cout << "d = ";
	cin >> d;
	
	if (a >= 0 && b >= 0 && c >= 0 && d >= 0 & a < 256 & b < 256 && c < 256 && d < 256)
		cout << a << "." << b << "." << c << "." << d << endl;

	system("pause");
	return 0;
}