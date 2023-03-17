#include<iostream>
#include<string>
#include<fstream>
#include "student.h"
#define  input 3
void debug_dept(dept tmp);
student init_student();
bool search_student(student tmp1,student tmp2);
void debug_student(student tmp);
bool search_dept(dept tmp1, dept tmp2);
int main()
{
	ifstream ifs;
	ifstream ifs_dept;
	ifs_dept.open("dept_dt.txt");
	ifs.open("student_dt.txt");
	using namespace std;
	string data;
	student students[10];
	dept depts[10];
	student search;
	dept dept_search;
	int search_num = 0;
	int dept_search_num = 0;
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
	if (ifs_dept.is_open())
	{
		int tmp = 0;
		while (!ifs_dept.eof())
		{
			getline(ifs_dept, depts[tmp].dept_name);
			getline(ifs_dept, depts[tmp].dep_id);
			tmp++;
		}
	}
	ifs.close();
	ifs_dept.close();
	for (int i = 0; i < input; i++) {
		cout << students[i].id << endl;
		cout << students[i].name << endl;
	}
	for (int i = 0; i < input; i++) {
		cout << depts[i].dep_id << endl;
		cout << depts[i].dept_name << endl;
	}
	while (true)
	{
		
		cout << "choose activity" << endl;
		cout << "[1:input student dt]" << endl;
		cout << "[2:search student dt]" << endl;
		cout << "[3:debug student dt]" << endl;
		cout << "[4:search dept dt]" << endl;
		cout << "[5:input dept dt to student dt]" << endl;
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
			search_num = 0;
			cout << "input search data" << endl;
			cin >> search.id;
			while (!search_student(students[search_num],search)) {
				search_num++;
			}
			debug_student(students[search_num]);
			break;
		case 3:
			for(int i=0;!students[i].id.empty();i++)
			{
				debug_student(students[i]);
				int j = 0;
				while (!students[i].depts[j].dep_id.empty())
				{
					debug_dept(students[i].depts[j]);
					j++;
				}
			}
			break;
		case 4:
			cout << "choose dept data" << endl;
			for (int i = 0; !depts[i].dep_id.empty(); i++)
			{
				debug_dept(depts[i]);
			}
			dept_search_num = 0;
			cin >> dept_search.dep_id;
			while (!search_dept(depts[dept_search_num],dept_search)) {
				dept_search_num++;
			}
			break;
		case 5:
			char tmp;
			cout << "input this data to founded student?(y,n)" << endl;
			cin >> tmp;
			if (tmp == 'y' || tmp == 'Y')
			{
				int i = 0;
				while (!students[search_num].depts[i].dep_id.empty())
				{
					i++;
				}
				students[search_num].depts[i] = depts[dept_search_num]; // ¼öÁ¤
			}
			break;
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
	if (tmp1.id == tmp2.id) {
		return true;
	}
	else
	{
		return false;
	}
}
bool search_dept(dept tmp1, dept tmp2)
{
	if (tmp1.dep_id == tmp2.dep_id) {
		return true;
	}
	else
	{
		return false;
	}
}
void debug_dept(dept tmp)
{
	cout << tmp.dept_name << endl;
	cout << tmp.dep_id << endl;
}
void debug_student(student tmp)
{
	cout << tmp.id << endl;
	cout << tmp.name << endl;
}