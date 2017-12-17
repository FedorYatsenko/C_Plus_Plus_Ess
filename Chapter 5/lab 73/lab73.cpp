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
	bool Contains(Point2D point);
private:
	double slope;
	double y_intercept;
};

bool Line2D::Contains(Point2D point)
{
	if (abs(point.GetY() - ((point.GetX()*slope) + y_intercept)) < 0.0001)
		return true;
	return false;
}

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

	double x1, x2, y1, y2, x3, y3;
	string str1, str2, str3;
	getline(cin, str1);
	getline(cin, str2);
	getline(cin, str3);

	x1 = atof(str1.substr(0, str1.find(" ")).c_str());
	y1 = atof(str1.substr(str1.find(" ") + 1, str1.length()).c_str());

	x2 = atof(str2.substr(0, str2.find(" ")).c_str());
	y2 = atof(str2.substr(str2.find(" ") + 1, str2.length()).c_str());

	x3 = atof(str3.substr(0, str3.find(" ")).c_str());
	y3 = atof(str3.substr(str3.find(" ") + 1, str3.length()).c_str());

	Point2D first(x1, y1);
	Point2D second(x2, y2);
	Point2D contain(x3, y3);

	Line2D line(first, second);
	if (line.Contains(contain))
		cout << "collinear" << endl;
	else
		cout << "not collinear" << endl;


	system("pause");
	return 0;
}
