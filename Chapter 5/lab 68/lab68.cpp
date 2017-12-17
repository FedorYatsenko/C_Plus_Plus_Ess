#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Fraction
{
public:
	Fraction(int numerator, int denominator);
	string toString();
	double toDouble();
private:
	int numerator;
	int denominator;
};

Fraction::Fraction(int numerator, int denominator)
{
	if (!denominator)
		throw invalid_argument("Denominator = 0");
	this->numerator = numerator;
	this->denominator = denominator;
}

double Fraction::toDouble()
{
	return (double)numerator / denominator;
}

string Fraction::toString()
{
	int part = 0;
	int n = numerator;
	int d = denominator;

	if (abs(n) >= abs(d)) {
		part = n / d;
		n = n - (d*part);
	}

	if (part < 0)
	{
		n = abs(n);
		d = abs(d);
	}
	else
		if (n > 0 && d < 0)
		{
			n = -n;
			d = -d;
		}

	string result = "";
	stringstream help;

	if (part)
		help << part << ' ';
	
	if(n != 0) help << n << '/' << d;

	getline(help, result);

	return result;
}

int main(void)
{
	int num, den;
	string input = "";
	getline(cin, input);
	num = atoi(input.substr(0, input.find("/") - 1).c_str());
	den = atoi(input.substr(input.find("/") + 2, input.length() - 1).c_str());

	try {
		Fraction fraction(num, den);
		cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;
	}
	catch (invalid_argument& e) {
		cerr << e.what() << endl;
	}

	system("pause");
	return 0;
}
