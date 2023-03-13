#include<iostream>
#include<string>
#include<fstream>
#include "student.h"
#define  input 3
student init_student();
bool search_student(student tmp1,student tmp2);
void debug_student(student tmp);
int main()
{
	ifstream ifs;
	ifs.open("student_dt.txt");
	using namespace std;
	string data;
	student students[10];
	student search;
	if (ifs.is_open())
	{
		int tmp = 0;
		while (!ifs.eof())
		{
			getline(ifs, students[tmp].name);
			getline(ifs, students[tmp].id);
			tmp++;
		}
	}
	ifs.close();
	for (int i = 0; i < input; i++) {
		cout << students[i].id << endl;
		cout << students[i].name << endl;
	}
	while (true)
	{
		int tmp = 0;
		cout << "choose activity" << endl;
		int answer;
		cin >> answer;
		switch (answer)
		{

		case 1:
			for (int i = 0; i < input; i++) {
				students[i] = init_student();
			}
			break;
		case 2:
			cout << "input search data" << endl;
			cin >> search.id >> search.name;
			while (!search_student(students[tmp],search)) {
				tmp++;
			}
			break;
		case 3:
			while (!students[tmp].id.empty())
			{
				debug_student(students[tmp]);
				tmp++;
			}
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
void debug_student(student tmp)
{
	cout << tmp.id << endl;
	cout << tmp.name << endl;
}