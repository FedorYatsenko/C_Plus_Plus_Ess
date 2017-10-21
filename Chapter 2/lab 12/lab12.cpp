#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	int sys;
	float m, ft, in;

	cout << "Input measurement systems (0 means \"metric\" and 1 means \"imperial\")" << endl;
	cin >> sys;

	if (!sys)
	{
		cout << "Input meters:";
		cin >> m;

		in = m / 0.0254;
		
		ft = (int)in / 12;
		in -= ft*12;

		cout << "Result: " << (int)ft << "'" << in << "\"\n";

	}
	else
		if (sys == 1)
		{
			cout << "Input foots:";
			cin >> ft;

			cout << "Input inchs:";
			cin >> in;

			if (in > 0 && in < 12)
			{
				m = (ft * 12 + in) * 0.0254;
				cout << "Result: " << m << "m\n";
			}
		}

	system("pause");
	return 0;
}