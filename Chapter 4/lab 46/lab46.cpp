#include "iostream"
#include <iomanip>

using namespace std;

int main(void)
{
	int **grades;
	int numOfCourses,
		numOfGrades,
		grade;

	do
	{
		cout << "Enter number of courses: ";
		cin >> numOfCourses;
	} while (numOfCourses < 0);
	
	grades = new int *[numOfCourses];

	for (int i = 0; i < numOfCourses; i++)
	{
		do
		{
			cout << i + 1 << ". Enter number of grades: ";
			cin >> numOfGrades;
		} while (numOfGrades < 0);

		grades[i] = new int[numOfGrades + 1];
		grades[i][0] = numOfGrades;

		for (int j = 1; j <= numOfGrades; j++)
		{
			do
			{
				cout << "Grades[" << j << "] = ";
				cin >> grade;

			} while (grade < 1 || grade > 5);

			grades[i][j] = grade;
		}
	}
	cout << endl;

	float averageGrade = 0,
		courseAverageGrade = 0;
	
	cout << fixed << setprecision(2);

	for (int i = 0; i < numOfCourses; i++)
	{
		courseAverageGrade = 0;

		cout << "Course " << i + 1 << " final ";

		for (int j = 1; j <= grades[i][0]; j++)
			courseAverageGrade += grades[i][j];

		courseAverageGrade /= grades[i][0];

		averageGrade += courseAverageGrade;

		cout << courseAverageGrade << ", grades:";
		
		for (int j = 1; j <= grades[i][0]; j++)
			cout << " " << grades[i][j];

		cout << endl;
	}
	cout << "Overall final " << averageGrade / numOfCourses << endl << endl;


	for (int i = 0; i < numOfCourses; i++)
		delete[] grades[i];
	delete[] grades;

	system("pause");
	return 0;
}