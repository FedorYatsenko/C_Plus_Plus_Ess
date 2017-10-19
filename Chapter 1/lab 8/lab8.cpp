#include "iostream"

using namespace std;

int main(void)
{
	int a, b;

	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

    float x = 1 / (float)a;
	float y = 1.0 / (float)b;

	if (abs(x - y) < 0.000001) cout << "Results are equal (by 0.000001 epsilon)\n";
	else cout << "Results are not equal (by 0.000001 epsilon)\n";

	system("pause");
	return 0;
}