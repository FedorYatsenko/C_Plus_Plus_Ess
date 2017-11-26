#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	string name;
	int age;
	int labs;
};

void print(Person* person)
{
	cout << person->name << " is " << person->age << " years old. " << person->name << " has made " << person->labs << " labs." << endl;
}

int main()
{
	Person person;
	person.name = "Harry";
	person.age = 23;
	person.labs = 5;

	cout << "Meet " << person.name << endl;
	print(&person);
	
	cout << "Has made " << person.labs << " labs." << endl;

	system("pause");
	return 0;
}