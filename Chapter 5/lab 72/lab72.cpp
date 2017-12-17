#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class Point2D
{
public:
	Point2D(double x, double y);
	string toString();
	double toDouble();
	double distanceTo(Point2D that);
	double GetX();
	double GetY();
private:
	double x;
	double y;
};

class Line2D
{
public:
	Line2D(double slope, double y_intercept);
	Line2D(Point2D pointA, Point2D pointB);
	string toString();
private:
	double slope;
	double y_intercept;
};

Line2D::Line2D(double slope, double y_intercept)
{
	this->slope = slope;
	this->y_intercept = y_intercept;
}

Line2D::Line2D(Point2D pointA, Point2D pointB)
{
	slope = (pointB.GetY() - pointA.GetY()) / (pointB.GetX() - pointA.GetX());
	y_intercept = pointB.GetY() - (pointB.GetX()*slope);
}

string Line2D::toString()
{
	stringstream help;
	if (y_intercept >= 0)
		help << "y = " << slope << "x + " << y_intercept;
	else
		help << "y = " << slope << "x " << y_intercept;
	string result;
	getline(help, result);
	return result;
}

Point2D::Point2D(double x, double y)
{
	this->x = x;
	this->y = y;
}
double Point2D::GetX()
{
	return x;
}

double Point2D::GetY()
{
	return y;
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

	Point2D first(x1, y1);
	Point2D second(x2, y2);

	Line2D line(first, second);
	cout << line.toString() << endl;

	system("pause");
	return 0;
}