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
	Fraction plus(Fraction that);
	Fraction minus(Fraction that);
	Fraction times(Fraction that);
	Fraction by(Fraction that);
private:
	int numerator;
	int denominator;
	void Reduce();
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

Fraction Fraction::plus(Fraction that)
{
	int n = (that.numerator * this->denominator) + (that.denominator * this->numerator);
	int d = this->denominator * that.denominator;
	Fraction res(n, d);
	res.Reduce();
	return res;
}

Fraction Fraction::minus(Fraction that)
{
	int n = (that.denominator * this->numerator) - (that.numerator * this->denominator);
	int d = this->denominator * that.denominator;
	Fraction res(n, d);
	res.Reduce();
	return res;
}
Fraction Fraction::times(Fraction that)
{
	int num = this->numerator * that.numerator;
	int den = this->denominator * that.denominator;
	Fraction result(num, den);
	result.Reduce();
	return result;
}
Fraction Fraction::by(Fraction that)
{
	int num = this->numerator * that.denominator;
	int den = this->denominator * that.numerator;
	Fraction result(num, den);
	result.Reduce();
	return result;
}

void Fraction::Reduce()
{
	int n = numerator;
	int d = denominator;
	int t;
	while (d != 0)
	{
		t = d;
		d = n % d;
		n = t;
	}
	denominator /= n;
	numerator /= n;
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

	if (n != 0) help << n << '/' << d;

	getline(help, result);

	return result;
}

int main(void) {
	int num, den;
	int num1, den1;
	string input = "";
	getline(cin, input);
	num = atoi(input.substr(0, input.find("/") - 1).c_str());
	den = atoi(input.substr(input.find("/") + 2, input.length() - 1).c_str());

	string input1 = "";
	getline(cin, input1);
	num1 = atoi(input1.substr(0, input1.find("/") - 1).c_str());
	den1 = atoi(input1.substr(input1.find("/") + 2, input1.length() - 1).c_str());

	try {

		Fraction fraction(num, den);
		Fraction temp(num1, den1);
		cout << fraction.toString() << " + " << temp.toString() << " = " << fraction.plus(temp).toString() << endl;
		cout << fraction.toString() << " - " << temp.toString() << " = " << fraction.minus(temp).toString() << endl;
		cout << fraction.toString() << " * " << temp.toString() << " = " << fraction.times(temp).toString() << endl;
		cout << fraction.toString() << " / " << temp.toString() << " = " << fraction.by(temp).toString() << endl;
	}
	catch (invalid_argument& e) {
		cerr << e.what() << endl;
	}

	system("pause");
	return 0;
}
