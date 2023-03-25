#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector <int> A, B;
    A.push_back(1);
    A.push_back(4);
    A.push_back(2);
    B.push_back(5);
    B.push_back(4);
    B.push_back(4);
    cout << solution(A,B) << endl;
}
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    for (int i = 0; i < A.size(); i++)
    {
        answer += A[i] * B[i];
    }
    return answer;
}