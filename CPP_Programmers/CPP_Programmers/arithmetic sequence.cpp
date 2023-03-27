#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 1;
    for (int i = 1; i < (n / 2 + 1); i++)
    {
        int tmp = 0;
        for (int j = i; j <= (n / 2 + 1); j++)
        {
            tmp += j;
            if (tmp == n)
            {
                answer += 1;
                break;
            }
            else if (tmp > n)
            {
                break;
            }
        }
    }
    return answer;
}