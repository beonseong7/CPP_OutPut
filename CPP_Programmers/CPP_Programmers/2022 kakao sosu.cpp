#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

int solution(int n, int k) {
    string tmp = "";
    vector<string> values;
    string mini_tmp;
    int result = 0;
    while (n > 0)
    {
        tmp.insert(0, to_string(n % k));
        n = n / k;
    }
    cout << tmp << endl;
    stringstream ss(tmp);
    while (getline(ss, mini_tmp, '0'))
    {
        if (mini_tmp != "" && stol(mini_tmp) > 1)
            values.push_back(mini_tmp);
    }
    for (auto& value : values)
    {
        long long int check_dt = stol(value);
        bool so = false;
        for (long long int i = 2; i * i <= check_dt; i++)
        {
            if (check_dt % i == 0)
            {
                so = true;
                break;
            }
        }
        if (so == false)
            result++;
    }
    return result;
}