#include <string>
#include <vector>
//������ ���� ����Ͽ� Ǯ������ ���հ�
//��ó : https://ansohxxn.github.io/programmers/97/  ��������
using namespace std;
long long solution(int n) {
    vector<long long>tmp;
    tmp.push_back(1);
    tmp.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        tmp.push_back((tmp[i - 1] + tmp[i - 2]) % 1234567);
    }
    return tmp.back();
}