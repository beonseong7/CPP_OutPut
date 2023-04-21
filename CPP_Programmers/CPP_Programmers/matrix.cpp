#include <string>
#include <vector>
//행렬의 곱은 3중 포문,한쪽은 가로,한쪽은 세로;
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for (int i = 0; i < arr1.size(); i++)
    {
        vector<int> tmp;
        for (int j = 0; j < arr2[0].size(); j++)
        {
            int tmp1 = 0;
            for (int k = 0; k < arr1[0].size(); k++)
            {
                tmp1 += arr1[i][k] * arr2[k][j];
            }
            tmp.push_back(tmp1);
        }
        answer.push_back(tmp);
    }
    return answer;
}