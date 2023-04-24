#include <string>
#include <vector>
#include <iostream>
using namespace std;
//�ǻ��� ���������� sort�ϴ� ������ �Ϸ� �����Ĵ� ������ ���ߴ�.
struct clo_box
{
    int num;
    string clothe;
};
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    vector<clo_box> sort;
    for (int i = 0; i < clothes.size(); i++)
    {
        bool already = false;
        for (int j = 0; j < sort.size(); j++)
        {
            if (clothes[i][1].compare(sort[j].clothe) == 0)
            {
                already = true;
                sort[j].num++;
                break;
            }
        }
        if (already == false)
        {
            clo_box tmp;
            tmp.num = 1;
            tmp.clothe = clothes[i][1];
            sort.push_back(tmp);
        }
    }
    for (int i = 0; i < sort.size(); i++)
    {
        answer *= (sort[i].num + 1);
    }
    return answer - 1;
}