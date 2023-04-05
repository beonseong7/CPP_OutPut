#include <iostream>

using namespace std;
//불합격
//정답 출처 https://excited-hyun.tistory.com/171
int solution(int n, int a, int b)
{
    int answer = 0;
    while (a != b)
    {
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        answer++;
    }
    return answer;
}