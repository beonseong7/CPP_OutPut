#include <string>
#include <vector>
//조합의 수를 사용하여 풀었지만 불합격
//출처 : https://ansohxxn.github.io/programmers/97/  를응용함
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