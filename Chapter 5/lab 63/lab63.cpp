#include <iostream>
#include "string"

using namespace std;

class ShopItemOrder
{
private:
	string name;
	int unitprice;
	int count;
public:
	ShopItemOrder(string Name, int UnitPrice, int Count);
	string getName();
	void setName(string Name);
	int getUnitPrice();
	void setUnitPrice(int UnitPrice);
	int getCount();
	void setCount(int Count);
	int getTotalAmount();
	void print();
};

ShopItemOrder::ShopItemOrder(string Name, int UnitPrice, int Count)
{
	this->name = Name;
	this->unitprice = UnitPrice;
	this->count = Count;
}

string ShopItemOrder::getName()
{
	return name;
}

void ShopItemOrder::setName(string Name)
{
	this->name = Name;
}

int ShopItemOrder::getUnitPrice()
{
	return unitprice;
}

void ShopItemOrder::setUnitPrice(int UnitPrice)
{
	this->unitprice = UnitPrice;
}

int ShopItemOrder::getCount()
{
	return count;
}

void ShopItemOrder::setCount(int Count)
{
	this->count = Count;
}

int ShopItemOrder::getTotalAmount()
{
	return unitprice * count;
}

void ShopItemOrder::print()
{
	cout << count << " item \"" << name << "\" with unit price " << unitprice << ". Total amount: " << getTotalAmount() << endl;
}

int main()
{
	ShopItemOrder item1("Sugar", 5, 2);

	item1.print();

	item1.setName("Solt");
	item1.setUnitPrice(3);
	item1.setCount(4);

	cout << item1.getName() << " up = " << item1.getUnitPrice() << " count = " << item1.getCount() << " ta = " << item1.getTotalAmount() << endl;

	system("pause");
	return 0;
}