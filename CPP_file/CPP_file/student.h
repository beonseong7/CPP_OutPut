#include <iostream>
#include <string>
using namespace std;
struct dept
{
	string dep_id;
	string dept_name;
	string grade;

};
struct student
{
	string id;
	string name;
	dept depts[10];
};
