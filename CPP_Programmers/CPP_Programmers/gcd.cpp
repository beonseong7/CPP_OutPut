#include <string>
#include <vector>
#include<algorithm>
//���հ�
//��ó:https://yabmoons.tistory.com/702
using namespace std;
int Min(int a, int b)//�μ��� �ִ������� ���Ѵ�
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
        int tmp = answer * arr[i] / gcd;//�μ��� ���Ѱ�/�ִ������� �ּҰ������ �ȴ�
        answer = tmp;
    }
    return answer;
}