#include <string>
#include <vector>
using namespace std;
//다른 풀이를 참조함
bool ch[8];
vector<vector<int>> dungeon;
int answer = 0;
void dfs(int k, int cnt) {
    if (k < 0) {
        return;
    }
    for (int i = 0; i < dungeon.size(); i++) {
        if (!ch[i] && k >= dungeon[i][0]) {
            ch[i] = true;
            dfs(k - dungeon[i][1], cnt + 1);
            ch[i] = false;
        }
    }
    answer = max(answer, cnt);
}
int solution(int k, vector<vector<int>> dungeons) {
    dungeon = dungeons;
    dfs(k, 0);
    return answer;
}