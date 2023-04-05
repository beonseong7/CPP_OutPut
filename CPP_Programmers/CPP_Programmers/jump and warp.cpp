#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;

    while (n != 0)
    {
        int tmp = n % 2;
        if (tmp)
            ans++;
        n = n / 2;
    }

    return ans;
}