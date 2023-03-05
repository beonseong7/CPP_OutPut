#include<iostream>
#include<stack>
#include<string>
#include<queue>
#include"basic_op.h"
using namespace std;
int calculating(string postfix);
queue<string> to_postfix(queue<string> postfix);
queue<string>parsing(queue<string> postfix,string input);
int main()
{
	queue<string> postfix;
	string input;
	cout << "input formula" << endl;
	cin >> input;
	postfix = parsing(postfix,input);
	//cout << postfix << endl;
	//cout << "answer is" << calculating(postfix) << endl;
}
queue<string>parsing(queue<string> postfix, string input)
{
	string tmp="";
	for (int i = 0; i < input.size();)
	{
		tmp = "";
		if (input[i] >= '0' && input[i] <= '9') {
			while (input[i] >= '0' && input[i] <= '9')
			{
				tmp += input[i];
				i++;
			}
			postfix.push(tmp);
		}
		else
		{
			tmp += input[i];
			postfix.push(tmp);
			i++;
		}
	}
	return postfix;
}
queue<string> to_postfix(queue<string> postfix)
{
	stack<string>op;
	queue<string> tmp_postfix;
	for (int i = 0; i < postfix.size(); i++) {
		switch (tmp_postfix.front())
		{
		case "+":
			for (int j = op.size(); j > 0 && op.top() != "("; j--)
			{
				tmp_postfix.push(op.top());
				op.pop();
			}
			op.push(input[i]);
			break;
		case '-':
			for (int j = op.size(); j > 0 && op.top() != "("; j--)
			{
				tmp_postfix.push(op.top());
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
			for (int j = op.size(); op.top() != "("; j--)
			{
				tmp_postfix.push(op.top());
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