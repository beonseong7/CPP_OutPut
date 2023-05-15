#include <string>
#include <vector>
#include <set>
#include <iostream>
//셋과 substr을 사용해 풀이함
using namespace std;
bool solution(vector<string> phone_book) {
    set<string> book;
    for (auto& tmp : phone_book)
    {
        book.insert(tmp);
    }
    for (auto it = book.begin(); it != (--book.end()); ++it)
    {
        auto tmp = it;
        if (*it == (++tmp)->substr(0, it->size()))
            return false;
    }
    return true;
}