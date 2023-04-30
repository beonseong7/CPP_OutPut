#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int count;
    int max;
    if (progresses.size() > 0)
    {
        count = 0;
        max = ceil((100.0 - progresses[0]) / speeds[0]);
    }

    for (int i = 0; i < progresses.size(); i++)
    {
        int tmp = ceil((100.0 - progresses[i]) / speeds[i]);
        if (max < tmp)
        {
            answer.push_back(i - count);
            count = i;
            max = tmp;
        }
    }
    if (count == progresses.size())
    {
        answer.push_back(1);
    }
    else
    {
        answer.push_back(progresses.size() - count);
    }
    return answer;
}
