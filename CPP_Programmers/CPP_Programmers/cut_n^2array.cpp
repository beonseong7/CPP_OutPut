#include <string>
#include <vector>

using namespace std;
//문제에서 알려준그대로 풀었을땐 45점으로 탈락
//https://sindh718.tistory.com/105 를 보고 이해하여 다시풀이함
//다른 풀이로 최댓값을 이용한것이 인상적이었음
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int divide, remain;
    for (int i = 0; i < right - left + 1; i++)
    {
        divide = (left + i) / n;
        remain = (left + i) % n;
        if (divide >= remain + 1)
            remain += divide - remain;
        answer.push_back(remain + 1);
    }
    return answer;
}