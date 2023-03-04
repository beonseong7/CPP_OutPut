#include<iostream>
#include<stack>
#include<string>
#include"basic_op.h"
using namespace std;
int calculating(string postfix);
string to_postfix(string input);
int main()
{
	string input;
	string postfix = "";
	cout << "input formula" << endl;
	cin >> input;
	postfix = to_postfix(input);
	cout << postfix << endl;
	cout << "answer is" << calculating(postfix) << endl;
}
string to_postfix(string input)
{
	stack<char>op;
	string postfix = "";
	for (int i = 0; i < input.size(); i++) {
		switch (input[i])
		{
		case '+':
			for (int j = op.size(); j > 0 && op.top() != '('; j--)
			{
				postfix += op.top();
				op.pop();
			}
			op.push(input[i]);
			break;
		case '-':
			for (int j = op.size(); j > 0 && op.top() != '('; j--)
			{
				postfix += op.top();
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
			for (int j = op.size(); op.top() != '('; j--)
			{
				postfix += op.top();
				op.pop();
			}
			op.pop();
			break;
		default:
			postfix += input[i];
			break;
		}
	}
	while (op.size() > 0) {
		postfix += op.top();
		op.pop();
	}
	return postfix;
}
int calculating(string postfix)
{
	stack<int> pf_op;
	int tmp1, tmp2;
	for (int i = 0; i < postfix.size(); i++)
	{
		switch (postfix[i]) {
		case'+':
			tmp1 = pf_op.top();
			pf_op.pop();
			tmp2 = pf_op.top();
			pf_op.pop();
			pf_op.push(plus_(tmp1, tmp2));
			break;
		case'-':
			tmp1 = pf_op.top();
			pf_op.pop();
			tmp2 = pf_op.top();
			pf_op.pop();
			pf_op.push(minus_(tmp1, tmp2));
			break;
		case'/':
			tmp2 = pf_op.top();
			pf_op.pop();
			tmp1 = pf_op.top();
			pf_op.pop();
			pf_op.push(divide_(tmp1, tmp2));
			break;
		case'*':
			tmp1 = pf_op.top();
			pf_op.pop();
			tmp2 = pf_op.top();
			pf_op.pop();
			pf_op.push(multiple_(tmp1, tmp2));
			break;
		default:
			pf_op.push(postfix[i] - '0');
			break;
		}
		cout << "done" << endl;
	}
	return pf_op.top();
}