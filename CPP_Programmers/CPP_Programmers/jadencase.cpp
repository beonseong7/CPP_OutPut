#include <string>
#include <vector>
#include <iostream>
using namespace std;
string solution(string s);
int main()
{
    cout << solution("E F G H") << endl;
}
string solution(string s) {
    for (int i = 0; i < s.size(); i++)
    {
        if(i==0)
        {
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] -= 32;
            }
        }
        else if (s[i] >= 'a' && s[i] <= 'z' && s[i - 1] == ' ')
        {
            s[i] -= 32;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z' && s[i - 1] != ' ')
        {
            s[i] += 32;
        }

    }
    string answer = s;
    return answer;
}