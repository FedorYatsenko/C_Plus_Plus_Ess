#include <iostream>
#include <string>

using namespace std;

class AdHocSquare
{
public:
	AdHocSquare(double side);
	void set_side(double side);
	double get_area();
private:
	double side;
};

AdHocSquare::AdHocSquare(double side)
{
	this->side = side;
}

void AdHocSquare::set_side(double side)
{
	if (side < 0) return;

	this->side = side;
}

double AdHocSquare::get_area()
{
	return side*side;
}

class LazySquare
{
public:
	LazySquare(double side);
	void set_side(double side);
	double get_area();
private:
	double side;
	double area;
	bool side_changed;
};

LazySquare::LazySquare(double side)
{
	this->side = side;
	side_changed = true;
}

void LazySquare::set_side(double side)
{
	if (side < 0) return;

	this->side = side;
	side_changed = true;
}

double LazySquare::get_area()
{
	if (side_changed)
	{
		area = side * side;
		side_changed = false;
	}

	return area;
}

int main()
{
	AdHocSquare s(4);
	cout << s.get_area() << endl;

	s.set_side(2.0);
	cout << s.get_area() << endl;

	s.set_side(-33.0);
	cout << s.get_area() << endl;

	LazySquare ls(4);
	cout << ls.get_area() << endl;

	ls.set_side(2.0);
	cout << ls.get_area() << endl;

	ls.set_side(-33.0);
	cout << ls.get_area() << endl;

	system("pause");
	return 0;
}