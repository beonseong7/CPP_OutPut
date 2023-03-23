#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string solution(string s);

int main() {
    cout << solution("1 2 3 4") << endl;
}
string solution(string s) {
    int min = NULL;
    int max = NULL;
    stringstream s2(s);
    string s1;
    while (s2 >> s1) {
        if (stoi(s1) < min || min == NULL)
        {
            min = stoi(s1);
        }
        if (stoi(s1) > max || max == NULL)
        {
            max = stoi(s1);
        }
    }
    string answer = "";
    cout << min << " " << max << endl;
    answer += to_string(min);
    answer += " ";
    answer += to_string(max);
    return answer;
}