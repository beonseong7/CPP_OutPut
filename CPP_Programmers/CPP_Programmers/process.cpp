#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    int loca_num = location;
    while (true)
    {
        if (priorities.front() == *max_element(priorities.begin(), priorities.end()))
        {
            if (loca_num == 0)
            {
                break;
            }
            priorities.erase(priorities.begin());
            loca_num--;
            answer++;
        }
        else
        {
            priorities.push_back(priorities.front());
            priorities.erase(priorities.begin());
            if (loca_num == 0)
            {
                loca_num = priorities.size() - 1;
            }
            else
            {
                loca_num--;
            }
        }
    }
    return answer;
}