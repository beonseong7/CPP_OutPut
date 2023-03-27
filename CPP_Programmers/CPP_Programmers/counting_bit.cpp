#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;
int counting_one(string tmp);
int solution(int n) {
    int answer = 0;
    bitset<16> my_b(n);
    int original_count = 0;
    original_count = counting_one(my_b.to_string());
    for (int i = n + 1;; i++)
    {
        int count = 0;
        int tmp = i;
        bitset<16> bit_tmp(tmp);
        string s_tmp = bit_tmp.to_string();
        if (original_count == counting_one(s_tmp))
        {
            return tmp;
        }
    }
}
int counting_one(string tmp)
{
    int count = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (tmp[i] == '1')
            count++;
    }
    return count;
}