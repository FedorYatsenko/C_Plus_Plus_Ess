#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void)
{
	int maxball;
	int ballsno;

	cout << "Max ball number? ";
	cin >> maxball;
	cout << "How many balls? ";
	cin >> ballsno;
	srand(time(NULL));
	
	int ball;
	int *balls = new int[ballsno];
	int count = 0;
	bool newBall;

	while (count < ballsno)
	{
		ball = rand() % maxball + 1;
		newBall = true;

		for (int i = 0; i < count; i++)
			if (balls[i] == ball) newBall = false;

		if (newBall)
		{
			balls[count] = ball;
			count++;
		}
	}

	for (int i = 0; i < ballsno; i++)
		cout << balls[i] << " ";
	cout << endl;

	delete[] balls;
	system("pause");
	return 0;
}