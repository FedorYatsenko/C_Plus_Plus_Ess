#include <iostream>

using namespace std;

int main(void)
{
	float grossprice, taxrate, netprice, taxvalue;

	cout << "Enter a gross price: ";
	cin >> grossprice;
	cout << "Enter a tax rate: ";
	cin >> taxrate;

	if (grossprice > 0 && taxrate >0 && taxrate < 100)  // gross price is greater than zero
	{	//tax rate expressed as a percentage (i.e. a value greater than 0 and, let's be optimistic, less than 100)

		netprice = grossprice / (1 + taxrate / 100);
		taxvalue = netprice * taxrate / 100;

		
		cout << "Net price: " << netprice << endl;
		cout << "Tax value: " << taxvalue << endl;
	}

	system("pause");
	return 0;
}