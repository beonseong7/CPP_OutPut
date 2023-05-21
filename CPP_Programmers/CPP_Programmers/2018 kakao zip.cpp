#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> data;
    int count = 27;
    string tmp = "";
    for (int i = 0; i < msg.size(); i++)
    {
        tmp += msg[i];
        if (data.find(tmp) == data.end())
        {
            if (tmp.size() > 1)
            {
                data.insert({ tmp,count++ });
                tmp.pop_back();
                answer.push_back(data.find(tmp)->second);
                i--;
            }
            else
            {
                answer.push_back(msg[i] - 'A' + 1);
                data.insert({ tmp,msg[i] - 'A' + 1 });
                if (i + 1 < msg.size())
                    data.insert({ tmp + msg[i + 1],count++ });
            }

            tmp = "";
        }
        else
        {
            if (i == msg.size() - 1)
            {
                answer.push_back(data.find(tmp)->second);
            }
        }
    }
    return answer;
}