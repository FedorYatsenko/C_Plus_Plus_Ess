#include <iostream>
#include <sstream>
#include<cmath>

using namespace std;

class Point2D {
public:
	Point2D(double x, double y);
	string toString();
	double toDouble();
	double distanceTo(Point2D that);
private:
	double x;
	double y;
};

Point2D::Point2D(double x, double y)
{
	this->x = x;
	this->y = y;
}

double Point2D::distanceTo(Point2D that)
{
	return sqrt(pow((that.x - this->x), 2) + pow((that.y - this->y), 2));
}

int main()
{

	double x1, x2, y1, y2;
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	x1 = atof(str1.substr(0, str1.find(" ")).c_str());
	y1 = atof(str1.substr(str1.find(" ") + 1, str1.length()).c_str());

	x2 = atof(str2.substr(0, str2.find(" ")).c_str());
	y2 = atof(str2.substr(str2.find(" ") + 1, str2.length()).c_str());

	Point2D pnt(x1, y1);
	Point2D pnt2(x2, y2);

	cout << pnt.distanceTo(pnt2) << endl;

	system("pause");
	return 0;
}