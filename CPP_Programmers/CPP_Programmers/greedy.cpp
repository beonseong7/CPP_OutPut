#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//sort()�� ����� vector�� ������������ �������� ���Ѵٴ� ��������¾����� Ž�������� ��ȿ�������� ¥�� ���հ�
//��ó https://velog.io/@diddnjs02/%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EA%B5%AC%EB%AA%85%EB%B3%B4%ED%8A%B8
int solution(vector<int> v, int limit) {
    int answer = 0;
    sort(v.rbegin(), v.rend()); // ������� ���� ������ ��ġ��
    int s = 0;
    int e = v.size() - 1;
    while (s < e)
    {
        int sum = v[s] + v[e];
        if (sum > limit)
        {
            s++;
        }
        else
        {
            s++;
            e--;
        }
        answer++;
    }
    if (s == e)
        answer++;
    return answer;
}