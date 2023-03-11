#include<iostream>
#include<string>
#include "student.h"
#define  input 3
student init_student();
bool search_student(student tmp1,student tmp2);
int main()
{
	using namespace std;
	string data;
	student students[10];
	student search;
	for (int i = 0; i < input; i++) {
		cout << students[i].id << endl;
		cout << students[i].name << endl;
	}
	while (true)
	{
		cout << "choose activity" << endl;
		int answer;
		cin >> answer;
		switch (answer)
		{
		case 1:
			for (int i = 0; i < input; i++) {
				students[i] = init_student();
			}
		case 2:
			int tmp=0;
			cout << "input search data" << endl;
			cin >> search.id >> search.name;
			while (!search_student(students[tmp],search)) {
				tmp++;
			}
			cout << students[tmp].id << endl;
			cout << students[tmp].name << endl;
		default:
			break;
		}
	}
	return 0;
}
student init_student()
{
	student tmp;
	cout << "name school id(ex: kimpark 201512165 )" << endl;
	cin >> tmp.name >> tmp.id;
	return tmp;
}
bool search_student(student tmp1,student tmp2)
{
	if (tmp1.id == tmp2.id && tmp2.id == tmp2.name) {
		return true;
	}
	else
	{
		return false;
	}
}