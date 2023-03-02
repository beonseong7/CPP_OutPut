#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
	string input;
	stack<char>op; 

	cout << "input formula" << endl;
	cin >> input;
	cout << input << input.size() << endl;
	for (int i = 0; i < input.size(); i++) {
		switch (input[i])
		{
		case '+':
			for (int j = op.size(); j > 0 && op.top()!='('; j--)
			{
				cout << op.top();
				op.pop();
			}
			op.push(input[i]);
			break;
		case '-':
			for (int j = op.size(); j > 0 && op.top() != '('; j--)
			{
				cout << op.top();
				op.pop();
			}
			op.push(input[i]);
			break;
		case'*':
			op.push(input[i]);
			break;
		case'/':
			op.push(input[i]);
			break;
		case'(':
			op.push(input[i]);
			break;
		case')':
			for (int j = op.size(); op.top()!='('; j--)
			{
				cout << op.top();
				op.pop();
			}
			op.pop();
			break;
		default:
			cout << input[i];
			break;
		}
	}
	while (op.size() > 0) {
		cout << op.top();
		op.pop();
	}
}