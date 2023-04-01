#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    for (int i = 0; i < words.size(); i++)
    {
        if (i > 0 && words[i][0] != words[i - 1][words[i - 1].size() - 1])
        {
            int tmp1 = i % n;
            int tmp2 = i / n;
            answer.push_back(tmp1 + 1);
            answer.push_back(tmp2 + 1);
            return answer;
        }
        for (int j = 0; j < i; j++)
        {
            if (words[i].compare(words[j]) == 0)
            {
                int tmp1 = i % n;
                int tmp2 = i / n;
                answer.push_back(tmp1 + 1);
                answer.push_back(tmp2 + 1);
                return answer;
            }
        }
    }
    answer.push_back(0);
    answer.push_back(0);

    return answer;
}