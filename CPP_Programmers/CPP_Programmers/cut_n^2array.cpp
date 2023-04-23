#include <string>
#include <vector>

using namespace std;
//�������� �˷��ر״�� Ǯ������ 45������ Ż��
//https://sindh718.tistory.com/105 �� ���� �����Ͽ� �ٽ�Ǯ����
//�ٸ� Ǯ�̷� �ִ��� �̿��Ѱ��� �λ����̾���
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