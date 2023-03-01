#include<iostream>
#include"basic_op.h"
int main()
{
	using namespace std;
	int results[5];
	char op;
	int num1 = 0;
	int num2 = 0;
	for (int i = 0; i < 5;i++) {
		cout << "input +,-,/.*" << endl;
		cin >> num1 >> op >> num2;
		switch (op)
		{
		case '+':
			results[i]=plus_(num1, num2);
			break;
		case '-':
			results[i] = minus_(num1, num2);
			break;
		case '*':
			results[i] = multiple_(num1, num2);
			break;
		case '/':
			results[i] = divide_(num1, num2);
			break;
		default:
			cout << "please enter correct op" << endl;
			break;
		}
	}
	for (int i = 0; i < 5; i++) {
		cout << i+1 << "result is " << results[i] << endl;
	}
	return 0;
}