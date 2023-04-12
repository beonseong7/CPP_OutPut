#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
//스택과 아스키코드를 사용하여 풀이함
int solution(string s) {
    int answer = 0;

    bool right = false;
    if (s.empty())
    {
        return 0;
    }
    for (int i = 0; i < s.size(); i++)
    {
        stack <char> st;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '[' || s[j] == '(' || s[j] == '{')
            {
                right = true;
                st.push(s[j]);
            }
            else
            {
                if (s[j] - st.top() > 0 && s[j] - st.top() < 3)
                {
                    st.pop();
                }
            }

        }
        if (st.empty() && right)
            answer++;
        //cout << s << answer << endl;
        s.append(1, s.front());
        s.erase(0, 1);
    }
    return answer;
}