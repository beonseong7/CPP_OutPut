#include <iostream>

int plus_(int num1, int num2);
int minus_(int num1, int num2);
int multiple_(int num1, int num2);
int divide_(int num1, int num2);
int main()
{
	using namespace std;
	char op;
	int num1 = 0;
	int num2 = 0;
	cout << "input +,-,/.*" << endl;
	cin >> op;
	cout << "input num1,num2" << endl;
	cin >> num1 >> num2;

	switch (op)
	{
	case '+':
		cout << plus_(num1,num2) << endl;
		break;
	case '-':
		cout << minus_(num1,num2) << endl;
		break;
	case '*':
		cout << multiple_(num1,num2) << endl;
		break;
	case '/':
		cout << divide_(num1,num2) << endl;
		break;
	default:
		cout << "please enter correct op" << endl;
		break;
	}
	return 0;
}
int plus_(int num1, int num2)
{
	return num1 + num2;
}
int minus_(int num1, int num2)
{
	return num1 - num2;
}
int multiple_(int num1, int num2)
{
	return num1 * num2;
}
int divide_(int num1, int num2)
{
	return num1 / num2;
}