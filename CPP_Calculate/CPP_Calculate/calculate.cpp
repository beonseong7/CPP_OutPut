#include<iostream>
int main()
{
	using namespace std;
	char op;
	int num1=0;
	int num2=0;
	cout << "input +,-,/.*" << endl;
	cin >> op;
	cout << "input num1,num2" << endl;
	cin >> num1>>num2;

	switch (op)
	{
	case '+':
		cout << num1 + num2 << endl;
		break;
	case '-':
		cout << num1 - num2 << endl;
		break;
	case '*':
		cout << num1 * num2 << endl;
		break;
	case '/':
		cout << num1 / num2 << endl;
		break;
	default:
		cout << "please enter correct op" << endl;
		break;
	}
	return 0;
}