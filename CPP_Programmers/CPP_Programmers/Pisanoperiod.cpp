#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n) {
    queue<int> q;
    q.push(0);
    q.push(1);
    for (int i = 0; i < n - 1; i++)
    {
        q.push((q.front() + q.back()) % 1234567);
        q.pop();
    }
    q.pop();
    return q.front();
}