#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
//문제를 제대로 이해하지못해 애먹음
//참조 사이트 https://ansohxxn.github.io/programmers/71/
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> cache;
    for (int i = 0; i < cities.size(); i++)
        for (int j = 0; j < cities[i].size(); j++)
            cities[i][j] = tolower(cities[i][j]);
    for (int i = 0; i < cities.size(); i++)
    {
        if (find(cache.begin(), cache.end(), cities[i]) == cache.end())
        {
            answer += 5;
            if (cache.size() < cacheSize)
                cache.push_back(cities[i]);
            else if (cache.size() == cacheSize && cacheSize > 0)
            {
                cache.erase(cache.begin());
                cache.push_back(cities[i]);
            }
        }
        else
        {
            answer++;
            cache.erase(find(cache.begin(), cache.end(), cities[i]));
            cache.push_back(cities[i]);
        }
    }
    return answer;
}