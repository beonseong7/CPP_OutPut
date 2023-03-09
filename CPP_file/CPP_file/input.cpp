#include<iostream>
#include<string>
#include "student.h"
int main()
{
	using namespace std;
	string data;
	student students[10];
	for (int i = 0; i < 3; i++) {
		string tmp1, tmp2, tmp3;
		cout << "name school id(ex: kimpark 201512165 )" << endl;
		cin >> students[i].name >> students[i].id;
	}
	for (int i = 0; i < 3; i++) {
		cout << students[i].id << endl;
		cout << students[i].name << endl;
	}
	return 0;
}