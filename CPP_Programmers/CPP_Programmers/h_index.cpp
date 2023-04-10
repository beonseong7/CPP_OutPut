#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//발상은 맞았지만 h-index라는 정보자체가 생소했고 예외처리를 잘못해 불합격
//참조 사이트: https://mungto.tistory.com/27
int solution(vector<int> cit) {
    int answer = 0;
    sort(cit.rbegin(), cit.rend());
    for (int i = 0; i < cit.size(); i++)
    {
        if (i < cit[i])
        {
            answer++;
        }
        else
        {
            break;
        }

    }
    return answer;
}
