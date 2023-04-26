#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;
//�����ϱ⿡�� ��Ģ���� ã����°Ϳ� ������ �޾� Ǯ����
bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return a.second > b.second;
}
vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<int, int>m;
    string tmp = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            tmp += s[i];
        }
        else
        {
            if (!tmp.empty())
            {
                m[stoi(tmp)]++;
                tmp = "";
            }
        }
    }
    vector<pair<int, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp);
    for (auto elem : vec)
    {
        answer.push_back(elem.first);
    }
    return answer;
}