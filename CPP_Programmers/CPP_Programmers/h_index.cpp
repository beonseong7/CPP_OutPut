#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//�߻��� �¾����� h-index��� ������ü�� �����߰� ����ó���� �߸��� ���հ�
//���� ����Ʈ: https://mungto.tistory.com/27
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
