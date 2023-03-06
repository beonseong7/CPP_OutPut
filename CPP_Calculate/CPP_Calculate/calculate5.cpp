#include<iostream>
#include<stack>
#include<string>
#include<queue>
#include"basic_op.h"
using namespace std;
int calculating(queue<string>postfix);
queue<string> to_postfix(queue<string> postfix);
queue<string>parsing(queue<string> postfix,string input);
int main()
{
	queue<string> postfix;
	string input;
	int result;
	cout << "input formula" << endl;
	cin >> input;
	postfix = parsing(postfix,input);
	postfix = to_postfix(postfix);
	result = calculating(postfix);
	cout <<"answer is " << result << endl;
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
	string tmp = "";
	queue<string> tmp_postfix;

	while (!postfix.empty()) {
		tmp = postfix.front();
		if (tmp[0] >= '0' && tmp[0] <= '9')
		{
			tmp_postfix.push(postfix.front());
		}
		else
		{
			switch (tmp[0])
			{
			case '+':
				for (int j = op.size(); j > 0 && op.top() != "("; j--)
				{
					tmp_postfix.push(op.top());
					op.pop();
				}
				op.push(tmp);
				break;
			case '-':
				for (int j = op.size(); j > 0 && op.top() != "("; j--)
				{
					tmp_postfix.push(op.top());
					op.pop();
				}
				op.push(tmp);
				break;
			case'*':
				op.push(tmp);
				break;
			case'/':
				op.push(tmp);
				break;
			case'(':
				op.push(tmp);
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
				cout << "error code(0001):정의되지않은 데이터입니다." << endl;
				break;
			}
		}
		postfix.pop();
	}
	while (op.size() > 0) {
		tmp_postfix.push(op.top());
		op.pop();
	}
	return tmp_postfix;
}
int calculating(queue<string> postfix)
{
	stack<int> pf_op;
	int tmp1, tmp2;
	while (!postfix.empty())
	{
		if (postfix.front()[0] >= '0' && postfix.front()[0] <= '9') {
			pf_op.push(stoi(postfix.front()));
		}
		else
		{
			switch (postfix.front()[0]) {
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
				pf_op.push(minus_(tmp2, tmp1));
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
				break;
			}
			cout << "done" << endl;
		}
		postfix.pop();
	}
	return pf_op.top();
}