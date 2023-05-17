#include<iostream>
#include"basic_op.h"
int main()
{
	using namespace std;
	char op;
	int num1 = 0;
	int num2 = 0;
	cout << "input +,-,/.*" << endl;
	cin >> num1 >> op >> num2;

	switch (op)
	{
	case '+':
		cout << plus_(num1, num2) << endl;
		break;
	case '-':
		cout << minus_(num1, num2) << endl;
		break;
	case '*':
		cout << multiple_(num1, num2) << endl;
		break;
	case '/':
		cout << divide_(num1, num2) << endl;
		break;
	default:
		cout << "please enter correct op" << endl;
		break;
	}
	return 0;
}