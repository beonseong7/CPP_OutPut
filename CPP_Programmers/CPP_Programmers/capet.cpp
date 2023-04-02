#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> yaksu;
    int sum = brown + yellow;
    vector <int> answer;
    for (int i = 3; i * i <= sum; i++)
    {
        if (sum % i == 0)
        {
            int row = sum / i;

            if (((i - 2) * (row - 2)) == yellow)
            {
                answer.push_back(row);
                answer.push_back(i);
                return answer;
            }
        }
    }
}