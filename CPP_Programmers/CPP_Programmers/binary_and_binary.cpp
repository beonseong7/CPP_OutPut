#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> solution(string s);
int main()
{
    vector<int> tmp = solution("110010101001");
    cout << tmp[0];
    cout << tmp[1];

}
vector<int> solution(string s) {
    int total_repeat = 0;
    int del_zero = 0;
    
    while (s.size() > 1)
    {
        int one_del_zero = 0;
        total_repeat++;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0') {
                del_zero++;
                one_del_zero++;
            }
        }
        for (int i = 0; i < one_del_zero; i++)
        {
            s.erase(find(s.begin(), s.end(), '0'));
        }
        cout << s << endl;
        int tmp = s.size();
        s = "";
        while (tmp > 0)
        {
            s.insert(0, to_string(tmp % 2));
            tmp = tmp / 2;
        }
    }
    vector<int> answer;
    answer.push_back(total_repeat);
    answer.push_back(del_zero);
    return answer;
}