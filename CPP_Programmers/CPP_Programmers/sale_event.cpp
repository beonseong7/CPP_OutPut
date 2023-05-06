#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for (int i = 0; i <= discount.size() - 10; i++)
    {
        vector<int> num_tmp = number;
        for (int j = 0; j < want.size(); j++)
        {
            int tmp = std::count(discount.begin() + i, discount.begin() + i + 10, want[j]);
            if (tmp > num_tmp[j])
                break;
            num_tmp[j] -= tmp;
        }
        if (accumulate(num_tmp.begin(), num_tmp.end(), 0) == 0)
        {
            answer += 1;
        }
    }
    return answer;
}