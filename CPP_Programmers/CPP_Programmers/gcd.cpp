#include <string>
#include <vector>
#include<algorithm>
//불합격
//출처:https://yabmoons.tistory.com/702
using namespace std;
int Min(int a, int b)//두수의 최대공약수를 구한다
{
    while (a % b != 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return b;
}
int solution(vector<int> arr) {
    int answer = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        int gcd = Min(answer, arr[i]);
        int tmp = answer * arr[i] / gcd;//두수의 곱한값/최대공약수는 최소공배수가 된다
        answer = tmp;
    }
    return answer;
}